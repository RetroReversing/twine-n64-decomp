extern void (*D_800D941C)(), (*D_800D9420)(), (*D_800D9424)();
extern void vecSlerp(),buildRotationMatrixS16(),func_80046648(),quatSlerp(),func_80083138(),func_800467B0();
void func_80001D80(s32 arg0) {
  switch(arg0) {
  default:
  case 0:
    D_800D941C=vecSlerp;
    D_800D9420=buildRotationMatrixS16;
    D_800D9424=func_80046648;
    break;
  case 1:
    D_800D941C=quatSlerp;
    D_800D9420=func_80083138;
    D_800D9424=func_800467B0;
    break;
  }
}
