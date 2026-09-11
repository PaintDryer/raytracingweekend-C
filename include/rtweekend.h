#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <float.h> // DOUBLE_MAX lives here
#include <stdlib.h>
#include <stdbool.h>

// no using make_shared or shared_ptr
// ough

// constants
const double infinity = DBL_MAX;
const double pi = 3.1415926535897932385;

// utility conversion

static inline double degrees_to_radians(double degrees)
{
	return degrees * pi / 180.0;
}

// common headers
#include "interval.h"
#include "vec3.h"
#include "color.h"
#include "ray.h"

#endif


