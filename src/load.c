#include "load.h"

static int get_nbr_obj(const char *file)
{
  int fd;
  int comp;
  char c;

  comp = 0;
  fd = open(file, O_RDONLY);
  if (fd == -1)
    exit(0);
  while(read(fd, &c, 1) != 0)
    {
      if (c == '{')
        comp++;
    }
  comp--;
  close(fd);
  return comp;
}

static int *malloc_int(int *mal_case, int comp)
{
  mal_case = bunny_malloc(sizeof(int) * comp);
  if (mal_case == NULL)
    {
      write (1,"error when malloc\n",19);
      exit(0);
    }
  return mal_case;
}

static char **malloc_case(char **mal_case, int comp)
{
  int i;

  i = 0;
  mal_case = bunny_malloc(sizeof(char *) * comp);
  if (mal_case == NULL)
    {
      write (1,"error when malloc\n",19);
      exit(0);
    }
  while(i < comp)
    {
      mal_case[i] = bunny_malloc(sizeof(char) * 32);
      if (mal_case[i] == NULL)
        {
          write (1,"error when malloc\n",19);
          exit(0);
        }
      i++;
    }
  return mal_case;
}

t_scene *load(const char *file)
{
  t_scene *scene;
  const char *temp;
  t_bunny_configuration *readjson;
  int i, comp, comp2;

  readjson = bunny_open_configuration(file, NULL);
  if (readjson == NULL)
    {
      write (1,"error when openning file\n",26);
      exit(0);
    }
  comp = comp2 = 0;
  i = get_nbr_obj(file);
  scene = malloc(sizeof(*scene));
  if (scene == NULL)
    {
      write (1,"error malloc\n",14);
      exit(0);
    }
  scene->nbr_obj = i;
  scene->form = malloc_case(scene->form, i);
  scene->rayon = malloc_int(scene->rayon, i);
  scene->color = malloc(sizeof(*scene->color) * i);
  if (scene->color == NULL)
    {
      write (1,"error malloc color\n",20);
      exit(0);
    }
  scene->pos = malloc(sizeof(*scene->pos) * i);
  if (scene->pos == NULL)
    {
      write (1,"error malloc pos\n",18);
      exit(0);
    }
  while (comp2 < 3)
    {
      bunny_configuration_getf(readjson, &temp , "light[%d]",comp2);
      if (comp2 == 0)
	scene->light.x = std_atoi((char*)temp);
      if (comp2 == 1)
	scene->light.y = std_atoi((char*)temp);
      if (comp2 == 2)
	scene->light.z = std_atoi((char*)temp);
      bunny_configuration_getf(readjson, &temp , "cam[%d]",comp2);
      if (comp2 == 0)
	scene->cam.x = std_atoi((char*)temp);
      if (comp2 == 1)
	scene->cam.y = std_atoi((char*)temp);
      if (comp2 == 2)
	scene->cam.z = std_atoi((char*)temp);
      comp2++;
    }
  while (comp < i)
    {
      comp2 = 0;
      bunny_configuration_getf(readjson, &temp , "Objects[%d].form",comp);
      scene->form[comp] = std_strcpy(scene->form[comp], temp);
      bunny_configuration_getf(readjson, &temp , "Objects[%d].rayon",comp);
      scene->rayon[comp] = std_atoi((char*)temp);
      while (comp2 < 3)
	{
	  bunny_configuration_getf(readjson, &temp , "Objects[%d].color[%d]",comp, comp2);
	  if (comp2 == 0)
	    scene->color[comp].argb[RED_CMP] = std_atoi((char*)temp);
	  if (comp2 == 1)
	    scene->color[comp].argb[GREEN_CMP] = std_atoi((char*)temp);
	  if (comp2 == 2)
	    scene->color[comp].argb[BLUE_CMP] = std_atoi((char*)temp);
	  bunny_configuration_getf(readjson, &temp , "Objects[%d].pos[%d]",comp, comp2);
	  if (comp2 == 0)
	    scene->pos[comp].x = std_atoi((char*)temp);
	  if (comp2 == 1)
	    scene->pos[comp].y = std_atoi((char*)temp);
	  if (comp2 == 2)
	    scene->pos[comp].z = std_atoi((char*)temp);
	  comp2++;
	}
      comp++;
    }
  bunny_delete_configuration(readjson);
  return scene;
}
