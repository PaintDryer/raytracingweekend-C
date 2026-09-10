#ifndef SPHERE_H
#define SPHERE_H

#include "rtweekend.h"
#include "hittable.h"

typedef struct
{
	point3	center;
	double	radius;
} sphere;

static inline sphere newSph(point3 center, double radius)
{
	return (sphere) {center, radius};
}

static inline bool hitSph(const ray r, const sphere s, double ray_tmin, double ray_tmax, hit *rec)
{
	vec3 oc = v3sub(s.center, r.orig);
	double a = v3len_sq(r.dir);
	double h = v3dot(r.dir, oc);
	double c = v3len_sq(oc) - s.radius * s.radius;

	double discriminant = h * h - a * c;
	if (discriminant < 0)
		return false;

	double sqrtd = sqrt(discriminant);

	// nearest root
	double root = (h - sqrtd) / a; //
	if (root <= ray_tmin || ray_tmax <= root)
	{
		root = (h + sqrtd) / a; // +
		if (root <= ray_tmin || ray_tmax <= root)
			return false;
	}

	rec->t = root;
	rec->p = at(r, rec->t);
	vec3 outward_normal = v3div( v3sub(rec->p, s.center), s.radius);
	set_face_normal(rec, r, outward_normal);
	return true;
}
#endif
