#pragma once

#include "struct.h"

t_zpos calcul_vector(double distance, t_screen size ,t_bunny_position pos);

t_zpos find_coord(t_zpos cam, t_zpos vector_dir, double distance);
