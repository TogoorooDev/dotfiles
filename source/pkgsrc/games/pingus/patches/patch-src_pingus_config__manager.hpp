$NetBSD: patch-src_pingus_config__manager.hpp,v 1.1 2019/05/12 06:17:30 triaxx Exp $

* Port to Boost.Signals2.

--- src/pingus/config_manager.hpp.orig	2011-12-24 21:46:47.000000000 +0000
+++ src/pingus/config_manager.hpp
@@ -17,7 +17,7 @@
 #ifndef HEADER_PINGUS_PINGUS_CONFIG_MANAGER_HPP
 #define HEADER_PINGUS_PINGUS_CONFIG_MANAGER_HPP
 
-#include <boost/signal.hpp>
+#include <boost/signals2.hpp>
 
 #include "math/size.hpp"
 #include "pingus/options.hpp"
@@ -39,55 +39,55 @@ public:
 
   void set_master_volume(int);
   int  get_master_volume() const;
-  boost::signal<void(int)> on_master_volume_change;
+  boost::signals2::signal<void(int)> on_master_volume_change;
 
   void set_sound_volume(int);
   int  get_sound_volume() const;
-  boost::signal<void(int)> on_sound_volume_change;
+  boost::signals2::signal<void(int)> on_sound_volume_change;
 
   void set_music_volume(int);
   int  get_music_volume() const;
-  boost::signal<void(int)> on_music_volume_change;
+  boost::signals2::signal<void(int)> on_music_volume_change;
 
   void set_fullscreen_resolution(const Size& size);
   Size get_fullscreen_resolution() const;
-  boost::signal<void(Size)> on_fullscreen_resolution_change;
+  boost::signals2::signal<void(Size)> on_fullscreen_resolution_change;
 
   void set_fullscreen(bool);
   bool get_fullscreen() const;
-  boost::signal<void(bool)> on_fullscreen_change;
+  boost::signals2::signal<void(bool)> on_fullscreen_change;
 
   void set_renderer(FramebufferType type);
   FramebufferType get_renderer() const;
-  boost::signal<void(FramebufferType)> on_renderer_change;
+  boost::signals2::signal<void(FramebufferType)> on_renderer_change;
 
   void set_resizable(bool);
   bool get_resizable() const;
-  boost::signal<void(bool)> on_resizable_change;
+  boost::signals2::signal<void(bool)> on_resizable_change;
 
   void set_mouse_grab(bool);
   bool get_mouse_grab() const;
-  boost::signal<void(bool)> on_mouse_grab_change;
+  boost::signals2::signal<void(bool)> on_mouse_grab_change;
 
   void set_print_fps(bool);
   bool get_print_fps() const;
-  boost::signal<void(bool)> on_print_fps_change;
+  boost::signals2::signal<void(bool)> on_print_fps_change;
 
   void set_language(const tinygettext::Language&);
   tinygettext::Language get_language() const;
-  boost::signal<void(const tinygettext::Language&)> on_language_change;
+  boost::signals2::signal<void(const tinygettext::Language&)> on_language_change;
 
   void set_software_cursor(bool);
   bool get_software_cursor() const;
-  boost::signal<void(bool)> on_software_cursor_change;
+  boost::signals2::signal<void(bool)> on_software_cursor_change;
 
   void set_auto_scrolling(bool);
   bool get_auto_scrolling() const;
-  boost::signal<void(bool)> on_auto_scrolling_change;
+  boost::signals2::signal<void(bool)> on_auto_scrolling_change;
 
   void set_drag_drop_scrolling(bool);
   bool get_drag_drop_scrolling() const;
-  boost::signal<void(bool)> on_drag_drop_scrolling_change;
+  boost::signals2::signal<void(bool)> on_drag_drop_scrolling_change;
 
 private:
   ConfigManager (const ConfigManager&);
