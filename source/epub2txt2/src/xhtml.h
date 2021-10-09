/*============================================================================
  epub2txt v2 
  xhtml.h
  Copyright (c)2020 Kevin Boone, GPL v3.0
============================================================================*/

#pragma once

#include "epub2txt.h"
#include "wstring.h"

struct _WrapTextContext;

void     xhtml_to_stdout (const WString *s, const Epub2TxtOptions *options, 
             char **error);
void     xhtml_utf8_to_stdout (const char *s, const Epub2TxtOptions *options, 
             char **error);
void     xhtml_file_to_stdout (const char *file, 
             const Epub2TxtOptions *options, char **error);
WString *xhtml_translate_entity (const WString *entity);
void     xhtml_emit_fmt_eol_pre (struct _WrapTextContext *context);
void     xhtml_emit_fmt_eol_post (struct _WrapTextContext *context);

