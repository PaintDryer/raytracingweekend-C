#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

typedef struct hit_record
{
	point3	p;
	vec3	normal;
	double	t;
} hit;

// Due to lack of class inheritance in C
// a hit function must be completely defined in each object

// bool hit(const ray r, double ray_tmin, double ray_tmax, hit_record rec)

#endif
