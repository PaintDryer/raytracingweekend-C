#ifndef SPHERE_H
#define SPHERE_H

#include "rtweekend.h"
#include "hittable.h"

typedef struct sphere_t
{
	point3	center;
	double	radius;
} sphere;

// gets called by newSphObject to make a new sphere
static inline sphere newSph(point3 center, double radius)
{
	return (sphere) {center, radius};
}

// 
static inline bool hitSph(const ray r, const sphere s, interval ray_t, hit *rec)
{
	vec3 oc = v3sub(s.center, r.orig);
	double a = v3len_sq(r.dir);
	// let h = -2b
	double h = v3dot(r.dir, oc);
	double c = v3len_sq(oc) - s.radius * s.radius;

	double discriminant = h * h - a * c;
	if (discriminant < 0)
		return false;

	double sqrtd = sqrt(discriminant);

	// nearest root
	double root = (h - sqrtd) / a; //
	if (!contains(ray_t, root))
	{
		root = (h + sqrtd) / a; // +
		if (!contains(ray_t, root))
			return false;
	}

	rec->t = root;
	rec->p = at(r, rec->t);
	vec3 outward_normal = v3div( v3sub(rec->p, s.center), s.radius);
	set_face_normal(rec, r, outward_normal);
	return true;
}
#endif
