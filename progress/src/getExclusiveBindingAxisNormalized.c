s32 getBindingAxisValue(s32, s32);
/* Returns the axis value of whichever binding is active, scaled to 0..1; 0 if both are active. */ f32 getExclusiveBindingAxisNormalized(s32 bindings, s32 bindingA, s32 bindingB) {
    s32 value = getBindingAxisValue(bindings, bindingA);
    if (value != 0) {
        value &= -(getBindingAxisValue(bindings, bindingB) == 0);
    } else {
        value = getBindingAxisValue(bindings, bindingB);
    }
    return (f32)value * 0.000015258789f;
}
