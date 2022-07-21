#pragma once

#include "struct.h"
#include "calcul_plan.h"
#include "calcul_sphere.h"
#include "calcul_cone.h"
#include "calcul_cylindre.h"
#include "strcmp.h"
#include <math.h>

double angle_sphere(t_zpos center, t_zpos point, t_zpos light);

double lum_plan(t_zpos point, t_zpos light);

int angle_plan(t_glob *glob, t_zpos point, t_zpos light, int rayon, int comp);
