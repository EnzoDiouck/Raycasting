#include "calcul_angle.h"

double angle_sphere(t_zpos center, t_zpos point, t_zpos light)
{
  t_zpos Vn, Vl;
  double A,B;
  double value;

  Vn.x = center.x - point.x;
  Vn.y = center.y - point.y;
  Vn.z = center.z - point.z;

  Vl.x = center.x - light.x;
  Vl.y = center.y - light.y;
  Vl.z = center.z - light.z;

  A = sqrt(pow(Vn.x,2) + pow(Vn.y,2) + pow(Vn.z,2));
  B = sqrt(pow(Vl.x,2) + pow(Vl.y,2) + pow(Vl.z,2));
  value = ((Vn.x * Vl.x + Vn.y * Vl.y + Vn.z * Vl.z) / (A * B));
  return (acos(value) * (180 / M_PI));
}

double lum_plan(t_zpos point, t_zpos light)
{
  t_zpos Vn, Vl;
  double A,B;
  double value;

  Vn.x = point.x; //- point.x;
  Vn.y = point.y - (point.y - 1);
  Vn.z = point.z; // - point.z;

  Vl.x = point.x - light.x;
  Vl.y = point.y - light.y;
  Vl.z = point.z - light.z;

  A = sqrt(pow(Vn.x,2) + pow(Vn.y,2) + pow(Vn.z,2));
  B = sqrt(pow(Vl.x,2) + pow(Vl.y,2) + pow(Vl.z,2));
  value = ((Vn.x * Vl.x + Vn.y * Vl.y + Vn.z * Vl.z) / (A * B));
  return (acos(value) * (180 / M_PI));
}

int angle_plan(t_glob *glob, t_zpos point, t_zpos light, int rayon, int comp)
{
  t_zpos Vl;
  double distance_Vl;
  double distance;

  Vl.x = point.x - light.x;
  Vl.y = point.y - light.y;
  Vl.z = point.z - light.z;

  distance_Vl = sqrt( pow(Vl.x, 2) + pow(Vl.y, 2) + pow(Vl.z, 2) );

  if (std_strcmp(glob->scene->form[comp],"sphere") == 0)
    distance = calcul_sphere(Vl, light, rayon);
  else if (std_strcmp(glob->scene->form[comp],"cone") == 0)
    distance = calcul_cone(Vl, light, rayon);
  else if (std_strcmp(glob->scene->form[comp],"cylindre") == 0)
    distance = calcul_cylindre(Vl, light, rayon);
  else
    return 1;
  (void)distance_Vl;
  if (distance == 0)
    return 1;
  else
    return 0;
}
