#ifndef RAY_H
#define RAY_H

typedef struct
{
	point3	pos;
	vec3	dir;
} ray;

static inline point3 at(const ray r, const double t)
{
	return v3add( r.pos, v3mul(r.dir, t));
}

#endif
