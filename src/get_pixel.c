/*
** *****************************************************************************
** enzo.pfeiffer
** enzo.pfeiffer <enzo.pfeiffer@student-station>
**
** get_pixel.c - 2021
**
** *****************************************************************************
*/

#include "get_pixel.h"

unsigned int	std_get_pixel(t_bunny_pixelarray	*px,
			      t_bunny_position		pos)
{
  unsigned int	*pixel;

  pixel = px->pixels;
  return (pixel[pos.y * px->clipable.buffer.width + pos.x]);
}
