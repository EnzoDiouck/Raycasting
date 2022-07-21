#pragma once

#include <lapin.h>
#include "clear_pixelarray.h"
#include "print_scene.h"

t_bunny_response loop_key(t_bunny_event_state    state,
                          t_bunny_keysym         keycode,
                          void                   *d);

t_bunny_response loop_function(void *d);
