/*============================================================================
  epub2txt v2 
  epub2txt.c
  Copyright (c)2020 Kevin Boone, GPL v3.0
============================================================================*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#ifndef __APPLE__
#include <malloc.h>
#endif
#include "epub2txt.h" 
#include "log.h"
#include "list.h"
#include "string.h"
#include "sxmlc.h"
#include "xhtml.h"

/*============================================================================
  epub2txt_unescape_html
  The metadata fields in EPUB are XHTML escaped into plain text using
  XHTML entities. Ugh. So we need to convert the entities into plain
  XHTML characters like < and >, and then format the result as XHTML.
  This is all a colossal time and effort for little to no gain, but 
  automated EPUB tools do put (X)HTML into the metadata, so we have to
  be prepared to remove it.
============================================================================*/
static char *epub2txt_unescape_html (const char *s)
  {
  typedef enum {MODE_ANY=0, MODE_AMP=1} Mode;

  Mode mode = MODE_ANY;

  String *out = string_create_empty();
  WString *in = wstring_create_from_utf8(s);
  WString *ent = wstring_create_empty();

  int i, l = wstring_length (in);
  for (i = 0; i < l; i++)
    {
    const uint32_t *ws = wstring_wstr (in);
    int c = ws[i];

    if (mode == MODE_AMP)
      {
      if (c == ';') 
        {
        WString *trans = xhtml_translate_entity (ent);
        char *trans_utf8 = wstring_to_utf8 (trans); 
        string_append (out, trans_utf8);
        free (trans_utf8);
        wstring_destroy (trans);
        wstring_clear (ent);
        mode = MODE_ANY; 
        }
      else
        {
        wstring_append_c (ent, c);
        }
      }
    else
      {
      if (c == '&') 
        mode = MODE_AMP; 
      else
        string_append_c (out, c);
      }
    }

  wstring_destroy (ent);
  wstring_destroy (in);
  char *ret = strdup (string_cstr (out));
  string_destroy (out);
  return ret;
  }


/*============================================================================
  epub2txt_format_meta
============================================================================*/
static void epub2txt_format_meta (const Epub2TxtOptions *options, 
          const char *key, const char *text)
  {
  char *ss = epub2txt_unescape_html (text);
  char *s;
  asprintf (&s, "%s: %s", key, ss);
  char *error = NULL;
  xhtml_utf8_to_stdout (s, options, &error);
  if (error) free (error);
  free (s);
  free (ss);
  }


/*============================================================================
  epub2txt_dump_metadata
  Parse the OPF file to print document metadata 
============================================================================*/
static List *epub2txt_dump_metadata (const char *opf, 
        const Epub2TxtOptions *options, char **error)
  {
  IN
  List *ret = NULL;
  String *buff = NULL;
  if (string_create_from_utf8_file (opf, &buff, error))
    {
    const char *buff_cstr = string_cstr (buff);
    log_debug ("Read OPF, size %d", string_length (buff));
    XMLNode *metadata = NULL;
    XMLDoc doc;
    XMLDoc_init (&doc);
    if (XMLDoc_parse_buffer_DOM (buff_cstr, APPNAME, &doc))
      {
      XMLNode *root = XMLDoc_root (&doc);

      int i, l = root->n_children;
      for (i = 0; i < l; i++)
	{
	XMLNode *r1 = root->children[i];
	if (strcmp (r1->tag, "metadata") == 0 || strstr (r1->tag, ":metadata"))
	  {
	  metadata = r1;
          int i, l = metadata->n_children;
          for (i = 0; i < l; i++)
	    {
	    XMLNode *r2 = metadata->children[i];
            const char *mdtag = r2->tag;
            const char *mdtext = r2->text;
            if (strstr (mdtag, "creator"))
              epub2txt_format_meta (options, "Creator", mdtext);
            else if (strstr (mdtag, "publisher"))
              epub2txt_format_meta (options, "Publisher", mdtext);
            else if (strstr (mdtag, "date"))
              {
              char *mdate = strdup (mdtext);
              char *p = strchr (mdate, '-');
              if (p) *p = 0;
              epub2txt_format_meta (options, "Date", mdate);
              free (mdate);
              }
            else if (strstr (mdtag, "description"))
              epub2txt_format_meta (options, "Description", mdtext);
            else if (strstr (mdtag, "subject"))
              epub2txt_format_meta (options, "Subject", mdtext);
            else if (strstr (mdtag, "language"))
              epub2txt_format_meta (options, "Language", mdtext);
            else if (strstr (mdtag, "title"))
              epub2txt_format_meta (options, "Title", mdtext);
            else if (strstr (mdtag, "meta") && options->calibre)
              {
	      int k, nattrs = r2->n_attributes;
              for (k = 0; k < nattrs; k++)
                {
		const char *value= r2->attributes[k].value;
                if (strcmp (value, "calibre:series") == 0)
                  {
	          int j; 
                  for (j = 0; j < r2->n_attributes; j++)
                    {
                    if (strcmp (r2->attributes[j].name, "content") == 0)
                      epub2txt_format_meta (options, 
                        "Calibre series", r2->attributes[j].value);
                    }
                  }
                else if (strcmp (value, "calibre:series_index") == 0)
                  {
	          int j;
                  for (j = 0; j < r2->n_attributes; j++)
                    {
                    if (strcmp (r2->attributes[j].name, "content") == 0)
                      {
                      char *s = strdup (r2->attributes[j].value);
                      // For some reason, Calibre stores the series index
                      //  as a decimal. Remove fraction.
                      char *p = strchr (s, '.');
                      if (p) *p = 0;
                      epub2txt_format_meta (options, 
                        "Calibre series index", s);
                      free (s);
                      }
                    }
                  }
                else if (strcmp (value, "calibre:title_sort") == 0)
                  {
	          int j;
                  for (j = 0; j < r2->n_attributes; j++)
                    {
                    if (strcmp (r2->attributes[j].name, "content") == 0)
                      {
                      char *s = strdup (r2->attributes[j].value);
                      epub2txt_format_meta (options, 
                        "Calibre title sort", s);
                      free (s);
                      }
                    }
                  }
                }
              }
            }
	  }
        }
      XMLDoc_free (&doc);
      }
    else
      {
      asprintf (error, "Can't parse OPF XML");
      }
    string_destroy (buff);
    }

  OUT
  return ret;
  }


/*============================================================================
  epub2txt_get_items
  Parse the OPF file to get the spine items 
============================================================================*/
List *epub2txt_get_items (const char *opf, char **error)
  {
  IN
  List *ret = NULL;
  String *buff = NULL;
  if (string_create_from_utf8_file (opf, &buff, error))
    {
    const char *buff_cstr = string_cstr (buff);
    log_debug ("Read OPF, size %d", string_length (buff));
    BOOL got_manifest = FALSE;
    XMLNode *manifest = NULL;
    XMLDoc doc;
    XMLDoc_init (&doc);
    if (XMLDoc_parse_buffer_DOM (buff_cstr, APPNAME, &doc))
      {
      XMLNode *root = XMLDoc_root (&doc);

      int i, l = root->n_children;
      for (i = 0; i < l; i++)
	{
	XMLNode *r1 = root->children[i];
	// Add workaround for bug #4 
	if (strcmp (r1->tag, "manifest") == 0 || strstr (r1->tag, ":manifest"))
	  {
	  manifest = r1;
	  got_manifest = TRUE;
	  }
	}

      if (!got_manifest)
	{
	asprintf (error, "File %s has no manifest", opf);
	OUT
	return NULL; 
	}
   
      ret = list_create_strings();

      for (i = 0; i < l; i++)
	{
	XMLNode *r1 = root->children[i];
	// Add workaround for bug #4
	if (strcmp (r1->tag, "spine") == 0 || strstr (r1->tag, ":spine"))
	  {
	  int j, l2 = r1->n_children;
	  for (j = 0; j < l2; j++)
	    {
	    XMLNode *r2 = r1->children[j]; // itemref
	    int k, nattrs = r2->n_attributes;
	    for (k = 0; k < nattrs; k++)
	      {
	      char *name = r2->attributes[k].name;
	      if (strcmp (name, "idref") == 0)
		{
		char *value= r2->attributes[k].value;
		int m;
		for (m = 0; m < manifest->n_children; m++)
		  {
		  XMLNode *r3 = manifest->children[m]; // item
		  int n, nattrs = r3->n_attributes;
		  for (n = 0; n < nattrs; n++)
		    {
		    char *name2 = r3->attributes[n].name;
		    char *val2 = r3->attributes[n].value;
		    if (strcmp (name2, "id") == 0 && 
			strcmp (val2, value) == 0)
		      {
		      int p;
		      for (p = 0; p < nattrs; p++)
			{
			char *name2 = r3->attributes[p].name;
			char *val2 = r3->attributes[p].value;
			if (strcmp (name2, "href") == 0)
			  {
			  list_append (ret, strdup (val2));
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
          }
        }
      XMLDoc_free (&doc);
      }
    else
      {
      asprintf (error, "Can't parse OPF XML");
      }
    string_destroy (buff);
    }

  OUT
  return ret;
  }


/*============================================================================
  epub2txt_get_root_file 
  Parse the OPF file to get the root document
============================================================================*/
String *epub2txt_get_root_file (const char *opf, char **error)
  {
  IN
  String *ret = NULL;
  String *buff = NULL;
  if (string_create_from_utf8_file (opf, &buff, error))
    {
    const char *buff_cstr = string_cstr (buff);
    log_debug ("Read OPF, size %d", string_length (buff));
    XMLDoc doc;
    XMLDoc_init (&doc);
    if (XMLDoc_parse_buffer_DOM (buff_cstr, APPNAME, &doc))
      {
      XMLNode *root = XMLDoc_root (&doc);
      int i, l = root->n_children;
      for (i = 0; i < l; i++)
	{
	XMLNode *r1 = root->children[i];
	if (strcmp (r1->tag, "rootfiles") == 0)
	  {
	  XMLNode *rootfiles = r1;
	  int i, l = rootfiles->n_children;
	  for (i = 0; i < l; i++)
	    {
	    XMLNode *r1 = rootfiles->children[i];
	    if (strcmp (r1->tag, "rootfile") == 0)
	      {
	      int k, nattrs = r1->n_attributes;
	      for (k = 0; k < nattrs; k++)
		{
		char *name = r1->attributes[k].name;
		char *value = r1->attributes[k].value;
		if (strcmp (name, "full-path") == 0)
		  {
		  ret = string_create (value);
		  }
		}
	      }
	    }
	  }
	}

      if (ret == NULL)
        asprintf (error, "container.xml does not specify a root file");
      XMLDoc_free (&doc);
      }
    else
      {
      asprintf (error, "Can't parse OPF XML");
      }
    string_destroy (buff);
    }

  OUT
  return ret;
  }



/*============================================================================
  epub2txt 
============================================================================*/
void epub2txt_do_file (const char *file, const Epub2TxtOptions *options, 
     char **error)
  {
  IN

  log_debug ("epub2txt_do_file: %s", file);
  if (access (file, R_OK) == 0)
    {
    log_debug ("File access OK");

    //output_para = 0;
    char tempdir[512];
    char tempbase[256];
    char cmd[1024];

    if (getenv ("TMP"))
      strcpy (tempbase, getenv("TMP"));
    else if (getenv ("TMPDIR"))
      strcpy (tempbase, getenv("TMPDIR"));
    else
      strcpy (tempbase, "/tmp");

    log_debug ("tempbase is: %s", tempbase);

    sprintf (tempdir, "%s/epub2txt%d", tempbase, getpid()); 

    log_debug ("tempdir is: %s", tempdir);

    // We should really check this but, honestly, anybody who creates
    //  a non-writable tempdir has problems far worse than being unable
    //  to run this utility
    mkdir (tempdir, 0777); 

    BOOL unzip_ok = TRUE;

    log_debug ("Running unzip command");
    int pid = fork();
    if (pid == 0)
      {
      execlp ("unzip", "unzip", "-o", "-qq", file, "-d", tempdir, NULL);
      log_error ("Can't execute unzip: %s", strerror (errno));
      kill (getppid(), SIGTERM);
      exit (-1);
      }
    else
      {
      int status = 0;
      waitpid (pid, &status, 0);
      // We could set unzip_ok here, but I'm not sure that unzip really
      //  returns a reliable status code
      }

    if (unzip_ok)
      {
      log_debug ("Unzip finished");
      // On some systems, unzip results in a file with no read permissions
      //   for the user -- reason unknown 
      sprintf (cmd, "chmod -R 744 \"%s\"", tempdir);
      log_debug ("Fix permissions: %s", cmd);
      system (cmd);
      log_debug ("Permissions fixed");


      char opf[1024];
      sprintf (opf, "%s/META-INF/container.xml", tempdir);
      log_debug ("OPF path is: %s", opf);
      String *rootfile = epub2txt_get_root_file (opf, error);
      if (*error == NULL)
        {
        log_debug ("OPF rootfile is: %s", string_cstr(rootfile));

        sprintf (opf, "%s/%s", tempdir, string_cstr (rootfile));
        char *content_dir = strdup (opf);
        char *p = strrchr (content_dir, '/');
        *p = 0; 
        log_debug ("Content directory is: %s", content_dir);


        if (options->meta)
          {
          epub2txt_dump_metadata (opf, options, error);
          if (*error)
            {
            // Log it as a warning, but don't give up reading the document
            log_warning (*error);
            free (*error);
            *error = NULL;
            }
          }

        if (!options->notext)
          {
          List *list = epub2txt_get_items (opf, error);
          if (*error == NULL)
	    {
	    log_debug ("EPUB spine has %d items", list_length (list));
	    int i, l = list_length (list);
	    for (i = 0; i < l; i++)
	      {
	      const char *item = (const char *)list_get (list, i);
	      sprintf (opf, "%s/%s", content_dir, item);
	      xhtml_file_to_stdout (opf, options, error);
	      }
	    list_destroy (list);
	    }
          }
        free (content_dir);
        }

      if (rootfile) string_destroy (rootfile);
      sprintf (cmd, "rm -rf \"%s\"", tempdir);
      log_debug ("Deleting temporary directory");
      system (cmd); 
      }
    else
      {
      // unzip failed
      }
    }
  else
    {
    asprintf (error, "File not found: %s", file);
    }

  OUT
  }



