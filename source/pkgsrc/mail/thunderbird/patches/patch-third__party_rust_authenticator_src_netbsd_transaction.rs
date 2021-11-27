$NetBSD: patch-third__party_rust_authenticator_src_netbsd_transaction.rs,v 1.1 2020/09/03 15:26:22 ryoon Exp $

--- third_party/rust/authenticator/src/netbsd/transaction.rs.orig	2020-09-02 20:55:31.087295047 +0000
+++ third_party/rust/authenticator/src/netbsd/transaction.rs
@@ -0,0 +1,50 @@
+/* This Source Code Form is subject to the terms of the Mozilla Public
+ * License, v. 2.0. If a copy of the MPL was not distributed with this
+ * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
+
+use runloop::RunLoop;
+use util::OnceCallback;
+
+use platform::fd::Fd;
+use platform::monitor::Monitor;
+
+pub struct Transaction {
+    // Handle to the thread loop.
+    thread: Option<RunLoop>,
+}
+
+impl Transaction {
+    pub fn new<F, T>(
+        timeout: u64,
+        callback: OnceCallback<T>,
+        new_device_cb: F,
+    ) -> Result<Self, ::Error>
+    where
+        F: Fn(Fd, &dyn Fn() -> bool) + Sync + Send + 'static,
+        T: 'static,
+    {
+        let thread = RunLoop::new_with_timeout(
+            move |alive| {
+                // Create a new device monitor.
+                let mut monitor = Monitor::new(new_device_cb);
+
+                // Start polling for new devices.
+                try_or!(monitor.run(alive), |_| callback.call(Err(::Error::Unknown)));
+
+                // Send an error, if the callback wasn't called already.
+                callback.call(Err(::Error::NotAllowed));
+            },
+            timeout,
+        )
+        .map_err(|_| ::Error::Unknown)?;
+
+        Ok(Self {
+            thread: Some(thread),
+        })
+    }
+
+    pub fn cancel(&mut self) {
+        // This must never be None.
+        self.thread.take().unwrap().cancel();
+    }
+}
