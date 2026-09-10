#ifndef COLOR_H
#define COLOR_H

#include "rtweekend.h"

typedef vec3 color;

static inline void fwrite_color(FILE *f, const color pixel_color)
{
	double r = pixel_color.x;
	double g = pixel_color.y;
	double b = pixel_color.z;

	int rbyte = 255.999 * r;
	int gbyte = 255.999 * g;
	int bbyte = 255.999 * b;

	fprintf(f, "%d %d %d\n", rbyte, gbyte, bbyte);
}

static inline void write_color(const color pixel_color)
{
	double r = pixel_color.x;
	double g = pixel_color.y;
	double b = pixel_color.z;

	int rbyte = 255.999 * r;
	int gbyte = 255.999 * g;
	int bbyte = 255.999 * b;

	printf("%d %d %d\n", rbyte, gbyte, bbyte);
}

#endif
