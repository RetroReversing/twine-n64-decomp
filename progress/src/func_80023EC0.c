typedef struct 
{
  char pad[0x18];
  s8 *name;
} SaveHeader;
extern char D_80107EA8[];
extern u8 D_80107EC0;
extern SaveHeader ***func_8002A980(void *);
extern SaveHeader ***func_8002A920(void *, s8);
extern s8 *func_800AB950(s8 *, s8 *);
extern s8 *lookupDataEntry(s32);
extern s32 func_8001226C(u8);
s32 func_80023EC0(s32 arg0)
{
  SaveHeader ***entry;
  SaveHeader **header;
  s8 *name;
  s8 *message;
  s16 index;
  s32 result;
  arg0 &= 0xEFFF;
  entry = func_8002A980(D_80107EA8);
  result = arg0;
  if (entry == NULL)
  {
    goto invalid;
  }
  if (arg0)
  {
    header = *entry;
  }
  else
  {
    header = *entry;
  }
  if (header == NULL)
  {
    goto invalid;
  }
  name = (*header)->name;
  if (name == NULL)
  {
    goto invalid;
  }
  switch ((u16) result)
  {
    case 1:
      if (func_800AB950(name, "TWINE") == NULL)
    {
      return arg0 | 0x1000;
    }
      if (func_8001226C(D_80107EC0) != 0)
    {
      return result;
    }
      return arg0 | 0x1000;

    case 2:
      if ((func_800AB950(name, "TWINE") == NULL) || (func_8001226C(D_80107EC0) == 0))
    {
      message = lookupDataEntry(0x3004);
      if (func_800AB950((*header)->name, message) == NULL)
      {
        return arg0 | 0x1000;
      }
    }
      if (func_800AB950((*header)->name, "TWINE") != NULL)
    {
      return result;
    }
      for (index = D_80107EC0 - 1; index >= 0; index--)
    {
      entry = func_8002A920(D_80107EA8, (s8) index);
      if (entry == NULL)
      {
        return result | 0x1000;
      }
      header = *entry;
      if (header == NULL)
      {
        return result | 0x1000;
      }
      if ((*header)->name == NULL)
      {
        return result | 0x1000;
      }
      message = lookupDataEntry(0x3004);
      if (func_800AB950((*header)->name, message) != NULL)
      {
        return result | 0x1000;
      }
    }

      return result;

    case 3:
      message = lookupDataEntry(0x3004);
      if (func_800AB950((*header)->name, message) == NULL)
    {
      return result;
    }
      invalid:
    return arg0 | 0x1000;


  }

  return result;
}

