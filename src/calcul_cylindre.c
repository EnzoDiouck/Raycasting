#include "calcul_cylindre.h"

double calcul_cylindre(t_zpos vector, t_zpos cam, double rayon)
{
  double solution;
  double solution2;
  double delta;
  double a, b, c;

  a = pow(vector.x, 2) + pow(vector.z, 2);
  b = 2 * (cam.x * vector.x + cam.z * vector.z);
  c = pow(cam.x, 2)  + pow(cam.z, 2) - pow(rayon, 2);
  delta = pow(b,2) - 4 * a * c;
  
  if (delta < 0)
    return 0.0;
  else if (delta == 0)
    return (-b+sqrt(delta))/(2*a);
  else
    {
      solution = (-b+sqrt(delta))/(2*a);
      solution2 = (-b-sqrt(delta))/(2*a);
      if (solution > 0 && solution2 > 0)
	{
	  if (solution < solution2)
	    return solution;
	  else if (solution > solution2)
	    return solution2;
	  else
	    return 0.0;
	}
      else
	{
	  if (solution > 0)
	    return solution;
	  else if (solution2 > 0)
	    return solution2;
	  else
	    return 0.0;
	}
    }
}
