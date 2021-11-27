const wlr = @import("../wlroots.zig");

const wl = @import("wayland").server.wl;

pub const Touch = extern struct {
    pub const event = struct {
        pub const Down = extern struct {
            device: *wlr.InputDevice,
            time_msec: u32,
            touch_id: i32,
            /// From 0..1
            x: f64,
            /// From 0..1
            y: f64,
        };

        pub const Up = extern struct {
            device: *wlr.InputDevice,
            time_msec: u32,
            touch_id: i32,
        };

        pub const Motion = extern struct {
            device: *wlr.InputDevice,
            time_msec: u32,
            touch_id: i32,
            /// From 0..1
            x: f64,
            /// From 0..1
            y: f64,
        };

        pub const Cancel = extern struct {
            device: *wlr.InputDevice,
            time_msec: u32,
            touch_id: i32,
        };
    };

    const Impl = opaque {};

    impl: *const Impl,

    events: extern struct {
        down: wl.Signal(*event.Down),
        up: wl.Signal(*event.Up),
        motion: wl.Signal(*event.Motion),
        cancel: wl.Signal(*event.Cancel),
    },

    data: usize,
};
