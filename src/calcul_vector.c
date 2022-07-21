#include "calcul_vector.h"

t_zpos calcul_vector(double distance, t_screen size ,t_bunny_position pos)
{
  t_zpos zpos;

  zpos.x = pos.x - (size.width / 2);
  zpos.y = pos.y - (size.height / 2);
  zpos.z = distance;
  return zpos;
}

t_zpos find_coord(t_zpos cam, t_zpos vector_dir, double distance)
{
  t_zpos pos;
  
  pos.x = vector_dir.x * distance + cam.x;
  pos.y = vector_dir.y * distance + cam.y;
  pos.z = vector_dir.z * distance + cam.z;
  return pos;
}
