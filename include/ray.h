#ifndef RAY_H
#define RAY_H

#include "rtweekend.h"

typedef struct
{
	point3	orig;
	vec3	dir;
} ray;

static inline point3 at(const ray r, const double t)
{
	return v3add( r.orig, v3mul(r.dir, t));
}

static inline ray newray(point3 orig, vec3 dir)
{
	return (ray) {orig, dir};
}

#endif
