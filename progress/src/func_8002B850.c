typedef struct Rec { unsigned short id; char pad[3]; unsigned char type; char rest[6]; } Rec;
extern Rec D_800BF680[];
extern Rec *D_80102F40;
int func_8002B850(int a) {
    D_80102F40 = D_800BF680;
    while (D_80102F40->id != 0) {
        if (D_80102F40->type == a) break;
        D_80102F40++;
    }
    return (int)D_80102F40 & -(D_80102F40->id != 0);
}
