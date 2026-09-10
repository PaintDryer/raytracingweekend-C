#ifndef VEC3_H
#define VEC3_H

#include "rtweekend.h"

typedef struct
{
	double x;
	double y;
	double z;
} vec3;

typedef vec3 point3;

static inline vec3 newv3(double x, double y, double z)
{
	return (vec3){ x, y, z };
}

// hardcoded vectors
static inline vec3 v3zero()
{
	return newv3(0.0, 0.0, 0.0);
}

static inline vec3 v3one()
{
	return newv3(1.0, 1.0, 1.0);
}

// basic operations
static inline vec3 v3add(vec3 v, const vec3 a)
{
	return newv3( v.x + a.x,
				  v.y + a.y,
			      v.z + a.z );
}

static inline vec3 v3sub(vec3 v, const vec3 a)
{
	return newv3( v.x - a.x,
				  v.y - a.y,
				  v.z - a.z );
}

static inline vec3 v3neg(vec3 v)
{
	return v3sub(v3zero(), v);
}
	
static inline vec3 v3mul(vec3 v, const double i)
{
	return newv3( v.x * i,
				  v.y * i,
				  v.z * i );
}

static inline vec3 v3div(vec3 v, const double i)
{
	return v3mul(v, 1 / i);
}

// vector operations
static inline double v3dot(const vec3 u, const vec3 v)
{
	return ( u.x * v.x
		   + u.y * v.y
		   + u.z * v.z);
} 

static inline double v3len_sq(const vec3 v)
	{ return (v3dot(v, v)); }

static inline double v3len(const vec3 v)
	{ return sqrt(v3len_sq(v)); }

static inline vec3 v3unit(const vec3 v)
{
	double len = v3len(v);
	return newv3( v.x / len , v.y / len, v.z / len );
}

static inline vec3 v3cross(const vec3 u, const vec3 v)
{
	return newv3( u.y * v.z - u.z * v.y,
				  u.z * v.x - u.x * v.z,
				  u.x * v.y - u.y * v.x );
}

// utility
static inline void v3print(const vec3 v)
{
	printf("%f %f %f", v.x, v.y, v.z);
}

#endif
