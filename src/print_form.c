#include "print_form.h"

static double ratio(double angle, double min, double max)
{
  double cal;
  if (angle != 0)
    {
      cal = (max - min) / angle;
      return cal;
    }
  return 0;
}

void print_sphere(t_glob *glob, t_bunny_position pos, int comp)
{
  double distance, angle ,rat;
  t_bunny_color col;

  distance = calcul_sphere(glob->vector, glob->cam_temp, glob->scene->rayon[comp]);
  if (distance > 0)
    {
      glob->coord = find_coord(glob->scene->cam, glob->vector , distance);
      angle = angle_sphere(glob->scene->pos[comp], glob->coord, glob->scene->light);
      rat = ratio(angle, 0, 90);
      if (rat > 1.0000)
        rat = 1.0;
      else if(rat < 0.0000)
        rat = 0.0;
      else
        rat *= 0.999999;
      col.argb[RED_CMP] = (int)(rat * glob->scene->color[comp].argb[RED_CMP]);
      col.argb[GREEN_CMP] = (int)(rat * glob->scene->color[comp].argb[GREEN_CMP]);
      col.argb[BLUE_CMP] = (int)(rat * glob->scene->color[comp].argb[BLUE_CMP]);
      std_set_pixel(glob->pic, pos, col.full);
    }
}

void print_cone(t_glob *glob, t_bunny_position pos, int comp)
{
  double distance, angle ,rat;
  t_bunny_color col;

  distance = calcul_cone(glob->vector, glob->cam_temp, glob->scene->rayon[comp]);
  if (distance > 0)
    {
      glob->coord = find_coord(glob->cam_temp, glob->vector , distance);
      angle = angle_sphere(glob->scene->pos[comp], glob->coord, glob->scene->light);
      rat = ratio(angle, 0, 90);
      if (rat > 1.0000)
        rat = 1.0;
      else if(rat < 0.0000)
        rat = 0.0;
      else
        rat *= 0.999999;
      col.argb[RED_CMP] = (int)(rat * glob->scene->color[comp].argb[RED_CMP]);
      col.argb[GREEN_CMP] = (int)(rat * glob->scene->color[comp].argb[GREEN_CMP]);
      col.argb[BLUE_CMP] = (int)(rat * glob->scene->color[comp].argb[BLUE_CMP]);
      std_set_pixel(glob->pic, pos, col.full);
    }
}

void print_cylindre(t_glob *glob, t_bunny_position pos, int comp)
{
  double distance, angle ,rat;
  t_bunny_color col;

  distance = calcul_cylindre(glob->vector, glob->cam_temp, glob->scene->rayon[comp]);
  if (distance > 0)
    {
      glob->coord = find_coord(glob->cam_temp, glob->vector , distance);
      angle = angle_sphere(glob->scene->pos[comp], glob->coord, glob->scene->light);
      rat = ratio(angle, 0, 90);
      if (rat > 1.0000)
        rat = 1.0;
      else if(rat < 0.0000)
        rat = 0.0;
      else
        rat *= 0.999999;
      col.argb[RED_CMP] = (int)(rat * glob->scene->color[comp].argb[RED_CMP]);
      col.argb[GREEN_CMP] = (int)(rat * glob->scene->color[comp].argb[GREEN_CMP]);
      col.argb[BLUE_CMP] = (int)(rat * glob->scene->color[comp].argb[BLUE_CMP]);
      std_set_pixel(glob->pic, pos, col.full);
    }
}
