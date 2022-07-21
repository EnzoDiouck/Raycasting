#include "loop_function.h"

t_bunny_response loop_key(t_bunny_event_state    state,
                          t_bunny_keysym         keycode,
                          void                   *d)
{
  (void)d;
  if (keycode == BKS_ESCAPE && state == GO_DOWN)
    return(0);
  return GO_ON;
}

t_bunny_response loop_function(void *d)
{
  t_glob *glob;
  
  glob = (t_glob *)d;
  std_clear_pixelarray(glob->pic, PINK2);
  print_scene(glob);
  bunny_blit(&glob->win->buffer, &glob->pic->clipable, NULL);
  bunny_display(glob->win);
  return GO_ON;
}
