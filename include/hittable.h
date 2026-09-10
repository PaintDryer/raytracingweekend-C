#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

typedef struct hit_record
{
	point3	p;
	vec3	normal;
	double	t;
	bool	front_face;
} hit;

// Due to lack of class inheritance in C
// a hit function must be completely defined in each object

// bool hit(const ray r, double ray_tmin, double ray_tmax, hit_record rec)

static inline void set_face_normal(hit *h, const ray r, const vec3 outward_normal)
{
	// sets hit record normal vector
	// NOTE: outward_normal is assumed to have unit length
	
	h->front_face = v3dot(r.dir, outward_normal) < 0;
	h->normal = h->front_face ? outward_normal : v3neg(outward_normal); 
}
#endif
