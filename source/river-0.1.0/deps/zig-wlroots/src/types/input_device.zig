const wlr = @import("../wlroots.zig");

const wayland = @import("wayland");
const wl = wayland.server.wl;

pub const InputDevice = extern struct {
    pub const Type = extern enum {
        keyboard,
        pointer,
        touch,
        tablet_tool,
        tablet_pad,
        switch_device,
    };

    const Impl = opaque {};

    impl: *const Impl,

    type: Type,
    vendor: c_uint,
    product: c_uint,
    name: [*:0]u8,

    width_mm: f64,
    height_mm: f64,
    output_name: [*:0]u8,

    /// InputDevice.type determines which of these is active
    device: extern union {
        _device: ?*c_void,
        keyboard: *wlr.Keyboard,
        pointer: *wlr.Pointer,
        // TODO:
        //switch_device: *wlr.Switch,
        touch: *wlr.Touch,
        tablet: *wlr.Tablet,
        // TODO:
        //tablet_pad: *wlr.TabletPad,
    },

    events: extern struct {
        destroy: wl.Signal(*InputDevice),
    },

    data: usize,

    link: wl.list.Link,

    extern fn wlr_input_device_get_virtual_keyboard(wlr_dev: *InputDevice) ?*wlr.VirtualKeyboardV1;
    pub const getVirtualKeyboard = wlr_input_device_get_virtual_keyboard;

    extern fn wlr_input_device_is_libinput(wlr_dev: *InputDevice) bool;
    extern fn wlr_libinput_get_device_handle(wlr_dev: *InputDevice) *LibinputDevice;
    pub fn getLibinputDevice(wlr_dev: *InputDevice) ?*LibinputDevice {
        if (!wlr_input_device_is_libinput(wlr_dev)) return null;
        return wlr_libinput_get_device_handle(wlr_dev);
    }
};

const LibinputDevice = opaque {};
