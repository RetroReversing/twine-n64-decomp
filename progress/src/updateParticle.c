s32 vec3Add(void *, void *, void *);
/* Per-frame particle update: applies velocity, type-specific rise/scale behavior, fades color/alpha, and flags the particle for removal when alpha goes negative. */ void updateParticle(void *particle)
{
  f32 temp_fv0;
  f32 temp_fv1;
f32 __repair_phase_temp_fv1;
  f32 t44;
f32 __repair_phase_t44;
  short alpha;
  void *def;
  void *temp_v1_2;
  def = *((void **) (((char *) particle) + 0x6C));
  vec3Add(def, particle + 0x24, particle + 0x24);
  switch (*((u16 *) (((char *) particle) + 0x78)))
  {
    case 0x54:
      temp_v1_2 = *((void **) (((char *) particle) + 0x20));
      temp_fv1 = (*((f32 *) (((char *) particle) + 0x28))) + 0.020416668f;
      *((f32 *) (((char *) particle) + 0x44)) += 16.0f;
      *((f32 *) (((char *) particle) + 0x28)) = temp_fv1;
      if ((*((f32 *) (((char *) (*((void **) (((char *) temp_v1_2) + 0x3C)))) + 0x24))) < temp_fv1)
    {
      *((f32 *) (((char *) particle) + 0x24)) += *((f32 *) (((char *) def) + 0));
      *((f32 *) (((char *) particle) + 0x2C)) += *((f32 *) (((char *) def) + 8));
      *((f32 *) (((char *) particle) + 0x28)) = *((f32 *) (((char *) (*((void **) (((char *) temp_v1_2) + 0x3C)))) + 0x24));
      break;
    }
      goto mul;

    case 0x17:
      __repair_phase_temp_fv1 = (*((f32 *) (((char *) particle) + 0x28))) + 0.010208334f;
      *((f32 *) (((char *) particle) + 0x44)) += 16.0f;
      *((f32 *) (((char *) particle) + 0x28)) = __repair_phase_temp_fv1;
      temp_fv0 = *((f32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) particle) + 0x20)))) + 0x3C)))) + 0x24));
      if (temp_fv0 < __repair_phase_temp_fv1)
    {
      *((f32 *) (((char *) particle) + 0x28)) = temp_fv0;
    }

    case 0x22:

    case 0x2C:
      mul:
    *((f32 *) (((char *) particle) + 0x54)) *= *((f32 *) (((char *) def) + 0x14));

      break;

  }

  alpha = *((u8 *) (((char *) particle) + 0x82));
  alpha -= *((u8 *) (((char *) def) + 0x26));
  *((u8 *) (((char *) particle) + 0x7F)) += *((u8 *) (((char *) def) + 0x23));
  *((u8 *) (((char *) particle) + 0x80)) += *((u8 *) (((char *) def) + 0x24));
  *((u8 *) (((char *) particle) + 0x81)) += *((u8 *) (((char *) def) + 0x25));
  if (alpha < 0)
  {
    *((s32 *) (((char *) particle) + 0x60)) |= 1;
    return;
  }
  *((u8 *) (((char *) particle) + 0x82)) = alpha;
}


