const wlr = @import("../wlroots.zig");

const os = @import("std").os;
const wl = @import("wayland").server.wl;
const pixman = @import("pixman");

pub const ShmAttributes = extern struct {
    fd: c_int,
    format: u32,
    width: c_int,
    height: c_int,
    stride: c_int,
    offset: os.off_t,
};

pub const Buffer = extern struct {
    pub const Impl = extern struct {
        destroy: fn (buffer: *Buffer) callconv(.C) void,
        get_dmabuf: fn (buffer: *Buffer, attribs: *wlr.DmabufAttributes) callconv(.C) bool,
        get_shm: fn (buffer: *Buffer, attribs: *wlr.ShmAttributes) callconv(.C) bool,
        begin_data_ptr_access: fn (buffer: *Buffer, data: **c_void, format: *u32, stride: *usize) callconv(.C) bool,
        end_data_ptr_access: fn (buffer: *Buffer) callconv(.C) void,
    };

    impl: *const Impl,

    width: c_int,
    height: c_int,

    dropped: bool,
    n_locks: usize,

    accessing_data_ptr: bool,

    events: extern struct {
        destroy: wl.Signal(void),
        release: wl.Signal(void),
    },

    extern fn wlr_buffer_init(buffer: *Buffer, impl: *const Buffer.Impl, width: c_int, height: c_int) void;
    pub const init = wlr_buffer_init;

    extern fn wlr_buffer_drop(buffer: *Buffer) void;
    pub const drop = wlr_buffer_drop;

    extern fn wlr_buffer_lock(buffer: *Buffer) *Buffer;
    pub const lock = wlr_buffer_lock;

    extern fn wlr_buffer_unlock(buffer: *Buffer) void;
    pub const unlock = wlr_buffer_unlock;

    extern fn wlr_buffer_get_dmabuf(buffer: *Buffer, attribs: *wlr.DmabufAttributes) bool;
    pub const getDmabuf = wlr_buffer_get_dmabuf;

    extern fn wlr_buffer_get_shm(buffer: *Buffer, attribs: *wlr.ShmAttributes) bool;
    pub const getShm = wlr_buffer_get_shm;
};

pub const ClientBuffer = extern struct {
    base: Buffer,

    resource: ?*wl.Buffer,
    resource_released: bool,
    texture: ?*wlr.Texture,

    resource_destroy: wl.Listener(*wl.Buffer),
    release: wl.Listener(void),

    extern fn wlr_client_buffer_get(buffer: *wlr.Buffer) ?*ClientBuffer;
    pub const get = wlr_client_buffer_get;

    extern fn wlr_client_buffer_import(renderer: *wlr.Renderer, resource: *wl.Buffer) ?*ClientBuffer;
    pub const import = wlr_client_buffer_import;

    extern fn wlr_client_buffer_apply_damage(buffer: *ClientBuffer, resource: *wl.Buffer, damage: *pixman.Region32) ?*ClientBuffer;
    pub const applyDamage = wlr_client_buffer_apply_damage;
};
