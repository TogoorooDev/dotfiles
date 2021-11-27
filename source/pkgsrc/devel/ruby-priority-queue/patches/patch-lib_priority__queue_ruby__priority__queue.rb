$NetBSD: patch-lib_priority__queue_ruby__priority__queue.rb,v 1.1 2021/02/14 14:58:20 taca Exp $

Convert to UTF-8.

--- lib/priority_queue/ruby_priority_queue.rb.orig	2021-01-11 07:17:11.306557525 +0000
+++ lib/priority_queue/ruby_priority_queue.rb
@@ -458,7 +458,7 @@ class RubyPriorityQueue
 	  n = n.right;
 	end while n != min.child
 
-	# Kinder einf�gen
+	# Kinder einfügen
 	if @rootlist
 	  l1 = @rootlist.left
 	  l2 = n.left
@@ -472,10 +472,10 @@ class RubyPriorityQueue
 	end
       end
 
-      # Gr��e anpassen
+      # Größe anpassen
       @length -= 1
 
-      # Wieder aufh�bschen
+      # Wieder aufhübschen
       consolidate
     end
 
