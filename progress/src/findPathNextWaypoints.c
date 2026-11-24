typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} SVec3;
typedef struct SNode
{
  s32 a;
  struct SNode *next;
  struct SNode *parent;
  f32 cost;
  SVec3 *pos;
  struct SNode *nbr[16];
  s32 pad[1];
} SNode;
extern SNode *gSearchNodes;
extern u32 sSearchEntryCount;
extern s32 D_8011F070;
extern SNode *D_8011F074;
extern s32 D_8011F0C8;
f32 approxDistanceXZ(SVec3 *, SVec3 *);
void gOverlayLoadAddr(s32 *, SNode *);
void unlinkListNode(SNode *);
/* Dijkstra search over the search-node graph from startIdx to goalIdx; writes the first path step's two positions to outFrom/outTo. */ void findPathNextWaypoints(s32 startIdx, s32 goalIdx, SVec3 *outFrom, SVec3 *outTo)
{
  volatile s64 reserve;
  u32 i;
  u32 count;
  SNode *current;
  SNode *node;
  SNode *p;
  SVec3 *a;
  SVec3 *b;
  f32 best;
  s32 reachedGoal = 0;
  SNode *entry;
  count = sSearchEntryCount;
  i = 0;
  current = NULL;
  if (count != 0)
  {
    f32 neg = -1.0f;
    entry = gSearchNodes;
    do
    {
      ((volatile SNode *) entry)->a = 0;
      ((volatile SNode *) entry)->next = 0;
      ((volatile SNode *) entry)->parent = 0;
      ((volatile SNode *) entry)->cost = neg;
      entry++;
      i++;
    }
    while (i < count);
  }
  if (startIdx == goalIdx)
  {
    outFrom->x = gSearchNodes[startIdx].pos->x;
    outFrom->y = gSearchNodes[startIdx].pos->y;
    outFrom->z = gSearchNodes[startIdx].pos->z;
    outTo->x = gSearchNodes[startIdx].pos->x;
    outTo->y = gSearchNodes[startIdx].pos->y;
    outTo->z = gSearchNodes[startIdx].pos->z;
    return;
  }
  D_8011F0C8 = 1;
  D_8011F070 = 0;
  D_8011F074 = &gSearchNodes[startIdx];
  D_8011F074->cost = 0;
  while (!((s16) reachedGoal))
  {
    best = 999999.0f;
    current = NULL;
    for (node = D_8011F074; node != NULL; node = node->next)
    {
      if (node->cost < best)
      {
        current = node;
        best = node->cost;
      }
    }

    if (current == NULL)
    {
      *outFrom = *gSearchNodes[startIdx].pos;
      *outTo = *gSearchNodes[startIdx].pos;
      return;
    }
    i = 0;
    if (current == (&gSearchNodes[goalIdx]))
    {
      reachedGoal = 1;
    }
    else
    {
      for (i = 0; i < 16; i++)
      {
        if (current->nbr[i] != NULL && current->nbr[i]->cost == -1.0f)
        {
          current->nbr[i]->cost = (s32) (current->cost + approxDistanceXZ(current->pos, current->nbr[i]->pos));
          current->nbr[i]->parent = current;
          gOverlayLoadAddr(&D_8011F070, current->nbr[i]);
          *((s32 *) 0x8011F0C8) = D_8011F0C8 + 1;
        }
      }
      unlinkListNode(current);
      D_8011F0C8 -= 1;
    }
  }

  a = current->pos;
  b = a;
  p = &gSearchNodes[startIdx];
  if (current != p)
  {
    do
    {
      current = current->parent;
      b = a;
      a = current->pos;
    }
    while (current != p);
  }
  outFrom->x = a->x;
  outFrom->y = a->y;
  outFrom->z = a->z;
  outTo->x = b->x;
  outTo->y = b->y;
  outTo->z = b->z;
}

