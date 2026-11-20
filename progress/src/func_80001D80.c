extern void (*D_800D941C)(), (*D_800D9420)(), (*D_800D9424)();
extern void func_800469C0(),func_80082FE4(),func_80046648(),func_80046BD4(),func_80083138(),func_800467B0();
void func_80001D80(s32 arg0) {
  switch(arg0) {
  default:
  case 0:
    D_800D941C=func_800469C0;
    D_800D9420=func_80082FE4;
    D_800D9424=func_80046648;
    break;
  case 1:
    D_800D941C=func_80046BD4;
    D_800D9420=func_80083138;
    D_800D9424=func_800467B0;
    break;
  }
}
