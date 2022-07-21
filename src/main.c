#include "struct.h"
#include "load.h"
#include "loop_function.h"
#include "clear_pixelarray.h"
#include "calcul_vector.h"

int main()
{
  t_glob glob;

  glob.scene = load("test.json");
  glob.screen.width = 800;
  glob.screen.height = 600;
  //glob.distance = 300;
  glob.win = bunny_start(glob.screen.width, glob.screen.height, false, "RTX 10090");
  glob.pic = bunny_new_pixelarray(glob.screen.width, glob.screen.height);
  /*
  glob.light.pos.x = 1000;
  glob.light.pos.y = 0;
  glob.light.pos.z = 1000;
  glob.cam.x = 0;
  glob.cam.y = 0;
  glob.cam.z = -glob.distance;
  glob.sphere.pos.x = 0;
  glob.sphere.pos.y = 0;
  glob.sphere.pos.z = 0;
  glob.sphere.color.argb[RED_CMP] = 0;
  glob.sphere.color.argb[BLUE_CMP] = 0;
  glob.sphere.color.argb[GREEN_CMP] = 0;
  */
  std_clear_pixelarray(glob.pic, PINK2);
  bunny_blit(&glob.win->buffer, &glob.pic->clipable, NULL);
  bunny_display(glob.win);
  bunny_set_key_response(loop_key);
  bunny_set_loop_main_function(loop_function);
  bunny_loop(glob.win, 60, &glob);
}
