#include "calcul_plan.h"

double calcul_plan(t_zpos vector, t_zpos point, double depth)
{
  if (vector.y > 0)
    {
      return ((depth - point.y)/ vector.y);
    }
  return 0.0;
}
