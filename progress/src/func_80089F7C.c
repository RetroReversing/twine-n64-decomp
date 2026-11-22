typedef struct Node
{
  struct Node *prev;
  struct Node *next;
  s32 addr;
  s32 tag;
  s32 len;
  u32 data;
} Node;
typedef struct Out
{
  s32 a;
  s32 b;
  s16 c;
  s16 d;
} Out;
typedef struct Ent
{
  s32 a;
  s32 b;
  s32 c;
} Ent;
s32 func_800CEEE0();
extern Node *D_800E425C;
extern Node *D_800E4260;
extern Node *D_800E4264;
extern Ent *D_80103EB4;
extern u16 D_80108F70;
extern s32 D_80109BA0;
extern s32 D_80109BF8;
void func_80089F7C(Out *arg0, u32 arg1, s32 arg2, s32 arg3)
{
  u32 buf[3][2];
  u32 sp2C;
  u32 sp34;
  Node *node;
  Node *next;
  u32 a0;
  u32 a1;
  s32 s3;
  s32 t0;
  u32 s1;
  Node *t;
  s32 tmp;

  node = D_800E4260;
  sp2C = arg1 + arg2;
  sp34 = arg1 - 0x600;
  s3 = 0;
  if (node != NULL)
  {
    t0 = 0x600;
    do
    {
      next = node->next;
      if (node->tag == arg3 && (a0 = node->addr) < sp2C && sp34 < a0)
      {
        a1 = node->len;
        if (a1 != t0 && a0 + a1 < arg1 + arg2)
        {
          s1 = arg1 + arg2;
          if (s1 >= a0 + 0x600)
            s1 = t0 - a1;
          else
            s1 = ((s1 - (a0 + a1)) + 0xFF) & ~0xFF;
          D_80109BF8 += 0xC;
          D_80109BA0 = func_800CEEE0(D_80109BA0, D_80109BF8);
          D_80103EB4[D_80108F70].b = node->addr + node->len;
          D_80103EB4[D_80108F70].a = s1;
          D_80103EB4[D_80108F70].c = node->data + node->len;
          D_80108F70++;
          node->len += s1;
        }
        if (node != D_800E4260)
        {
          if (node->prev != NULL)
            node->prev->next = node->next;
          if (node->next != NULL)
            node->next->prev = node->prev;
          else
            D_800E425C = node->prev;
          D_800E4260->prev = node;
          node->next = D_800E4260;
          D_800E4260 = node;
          node->prev = NULL;
        }
        a1 = node->addr;
        if (arg1 < a1)
        {
          s32 n;
          buf[0][(u16) s3] = node->data;
          buf[2][(u16) s3] = node->addr;
          n = arg2 - (node->addr - arg1);
          buf[1][(u16) s3] = n;
          s3++;
          arg2 -= n;
        }
        else if (a1 + node->len < arg1 + arg2)
        {
          u32 n;
          buf[0][(u16) s3] = node->data + (arg1 - a1);
          buf[2][(u16) s3] = arg1;
          n = node->addr + node->len - arg1;
          buf[1][(u16) s3] = n;
          s3++;
          arg2 -= n;
          arg1 = node->addr + node->len;
        }
        else
        {
          buf[0][(u16) s3] = node->data + (arg1 - a1);
          buf[1][(u16) s3] = arg2;
          arg2 = 0;
          buf[2][(u16) s3] = arg1;
          s3++;
          break;
        }
      }
      node = next;
    }
    while (node != NULL);
  }
  if (arg2 != 0)
  {
    s1 = (arg1 - arg3) % 0x600;
    do
    {
      if (D_800E4264 != NULL)
      {
        t = D_800E4264;
        D_800E4264 = t->prev;
        if (D_800E4264 != NULL)
          D_800E4264->next = NULL;
        if (D_800E4260 == NULL)
        {
          t->prev = D_800E425C;
          if (D_800E425C != NULL)
            D_800E425C->next = t;
          D_800E425C = t;
        }
        else
        {
          t->prev = NULL;
          t->next = D_800E4260;
          D_800E4260->prev = t;
        }
        D_800E4260 = t;
        node = t;
      }
      else
      {
        Node *head;
        Node *prev;
        t = D_800E425C;
        t->prev->next = NULL;
        prev = t->prev;
        head = D_800E4260;
        node = t;
        D_800E4260 = node;
        head->prev = node;
        node->next = head;
        node->prev = NULL;
        D_800E425C = prev;
      }
      node->addr = arg1 - s1;
      node->tag = arg3;
      if (arg2 + s1 > 0x600)
      {
        u32 n;
        u32 m;
        node->len = 0x600;
        D_80109BF8 += 0xC;
        D_80109BA0 = func_800CEEE0(D_80109BA0, D_80109BF8);
        D_80103EB4[D_80108F70].b = node->addr;
        D_80103EB4[D_80108F70].a = 0x600;
        D_80103EB4[D_80108F70].c = node->data;
        D_80108F70++;
        buf[0][(u16) s3] = node->data + s1;
        buf[2][(u16) s3] = node->addr + s1;
        buf[1][(u16) s3] = 0x600 - s1;
        s3++;
        n = arg2 - 0x600;
        arg2 = n + s1;
        m = s1 - 0x600;
        arg1 -= m;
      }
      else
      {
        node->len = (arg2 + s1 + 0xFF) & ~0xFF;
        D_80109BF8 += 0xC;
        tmp = func_800CEEE0(D_80109BA0, D_80109BF8);
        D_80103EB4[D_80108F70].b = node->addr;
        D_80103EB4[D_80108F70].a = node->len;
        D_80103EB4[D_80108F70].c = node->data;
        D_80109BA0 = tmp;
        buf[0][(u16) s3] = node->data + s1;
        buf[2][(u16) s3] = node->addr + s1;
        D_80108F70++;
        buf[1][(u16) s3] = arg2;
        arg2 = 0;
        s3++;
      }
      s1 = 0;
    }
    while (arg2 != 0);
  }
  if ((s3 & 0xFFFF) == 1)
  {
    arg0->a = buf[0][0];
    arg0->c = buf[1][0];
    arg0->d = 0;
    return;
  }
  if (buf[2][0] < buf[2][1])
  {
    arg0->a = buf[0][0];
    arg0->b = buf[0][1];
    arg0->c = buf[1][0];
    arg0->d = buf[1][1];
    return;
  }
  arg0->a = buf[0][1];
  arg0->b = buf[0][0];
  arg0->c = buf[1][1];
  arg0->d = buf[1][0];
}
