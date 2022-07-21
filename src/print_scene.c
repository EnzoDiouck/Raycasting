#include "print_scene.h"

static void print_form(t_glob *glob, t_bunny_position pos, int comp)
{
  if (std_strcmp(glob->scene->form[comp],"sphere") == 0)
    print_sphere(glob, pos, comp);
  else if (std_strcmp(glob->scene->form[comp],"cone") == 0)
    print_cone(glob, pos, comp);
  else if (std_strcmp(glob->scene->form[comp],"cylindre") == 0)
    print_cylindre(glob, pos, comp);
  else
    print_sphere(glob, pos, comp);//par defaut
}

void print_scene(t_glob *glob)
{
  int comp, color;
  double distance;
  t_bunny_position pos;

  comp = 0;
  glob->cam_temp = glob->scene->cam;
  while (comp < glob->scene->nbr_obj)
    {
      pos.x = 0;
      pos.y = 0;
      glob->cam_temp.x = glob->scene->cam.x - (glob->scene->pos[comp].x);
      glob->cam_temp.y = glob->scene->cam.y - (glob->scene->pos[comp].y);
      glob->cam_temp.z = glob->scene->cam.z - (glob->scene->pos[comp].z);
      while (pos.x * pos.y < glob->screen.width * glob->screen.height)
	{
	  if (pos.x == glob->screen.width)
	    {
	      pos.y++;
	      pos.x = 0;
	    }
	  glob->vector = calcul_vector(-glob->scene->cam.z, glob->screen, pos);
	  distance = calcul_plan(glob->vector, glob->scene->cam, 100);
	  if (distance > 0)
	    {
	      glob->coord = find_coord(glob->scene->cam, glob->vector , distance);
	      color = angle_plan(glob, glob->coord, glob->scene->light, glob->scene->rayon[comp], comp);
	      if (std_get_pixel(glob->pic, pos) != BLACK)
		std_set_pixel(glob->pic,pos,COLOR(255,(int)(color * 255),(int)(color * 255),(int)(color * 255)));
	    }
	  pos.x++;
	}
      comp++;
    }
  comp = 0;
  while (comp < glob->scene->nbr_obj)
    {
      pos.x = 0;
      pos.y = 0;
      glob->cam_temp.x = glob->scene->cam.x - (glob->scene->pos[comp].x);
      glob->cam_temp.y = glob->scene->cam.y - (glob->scene->pos[comp].y);
      glob->cam_temp.z = glob->scene->cam.z - (glob->scene->pos[comp].z);
      while (pos.x * pos.y < glob->screen.width * glob->screen.height)
	{
	  if (pos.x == glob->screen.width)
	    {
	      pos.y++;
	      pos.x = 0;
	    }
	  glob->vector = calcul_vector(-glob->cam_temp.z, glob->screen, pos);
	  print_form(glob, pos, comp);
	  pos.x++;
	}
      comp++;
    }
}
