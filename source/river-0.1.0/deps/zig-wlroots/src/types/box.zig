const wl = @import("wayland").server.wl;
const wlr = @import("../wlroots.zig");
const pixman = @import("pixman");

pub const Box = extern struct {
    x: c_int,
    y: c_int,
    width: c_int,
    height: c_int,

    extern fn wlr_box_closest_point(box: *const Box, x: f64, y: f64, dest_x: *f64, dest_y: *f64) void;
    pub const closestPoint = wlr_box_closest_point;

    extern fn wlr_box_intersection(dest: *Box, box_a: *const Box, box_b: *const Box) bool;
    pub const intersection = wlr_box_intersection;

    extern fn wlr_box_contains_point(box: *const Box, x: f64, y: f64) bool;
    pub const containsPoint = wlr_box_contains_point;

    extern fn wlr_box_empty(box: *const Box) bool;
    pub const empty = wlr_box_empty;

    extern fn wlr_box_transform(dest: *Box, box: *const Box, transform: wl.Output.Transform, width: c_int, height: c_int) void;
    pub const transform = wlr_box_transform;

    extern fn wlr_box_rotated_bounds(dest: *Box, box: *const Box, rotation: f32) void;
    pub const rotatedBounds = wlr_box_rotated_bounds;

    extern fn wlr_box_from_pixman_box32(dest: *Box, box: pixman.Box32) void;
    pub const fromPixmanBox32 = wlr_box_from_pixman_box32;
};

pub const FBox = extern struct {
    x: f64,
    y: f64,
    width: f64,
    height: f64,
};
