#pragma once

#include <lapin.h>

typedef struct s_zpos
{
  double x;
  double y;
  double z;
} t_zpos;

typedef struct s_screen
{
  int width;
  int height;
}t_screen;

typedef struct s_scene
{
  int nbr_obj;
  char **form;
  int *rayon;
  t_bunny_color *color;
  t_zpos *pos;
  t_zpos light;
  t_zpos cam;
} t_scene;

typedef struct s_glob
{
  t_scene *scene;
  t_screen screen;
  t_zpos cam_temp;
  t_zpos vector;
  t_zpos coord;
  t_bunny_window *win;
  t_bunny_pixelarray *pic;
}t_glob;
