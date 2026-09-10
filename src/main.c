#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#define WHITE v3one()
#define BLUE newv3(0.5, 0.7, 1.0)
#define RED newv3(1.0, 0, 0)

int	main(void)
{
	// file opening
	FILE *image = fopen("image.ppm", "w");
	if (image == NULL)
	{
		printf("Failed to open image\n");
		return (1);
	}
	
	double hit_sphere(point3 center, double radius, ray r)
	{
		vec3 oc = v3sub(center, r.orig); 
		double a = v3dot(r.dir, r.dir); // d^2
		double b = -2 * v3dot(r.dir, oc); // -2d(C-Q)
		double c = v3dot(oc, oc) - radius * radius; // (C-Q)^2 - r^2
		double discriminant = b * b - 4 * a * c;
		// solve for t if possible
		if (discriminant < 0)
			return (-1);
		printf("%f\n", (-b -sqrt(discriminant)) / 2 / a);
		return (-b - sqrt(discriminant)) / (2 * a);
	}

	color ray_color(const ray r)
	{
		point3 spherepos = newv3(0, 0, -1.0);
		double t = hit_sphere(spherepos, 0.5, r);
		// Find normal from t
		if (t > 0)
		{
			vec3 n = v3unit( v3sub(at(r, t), spherepos));
			n = v3mul( v3add(n, v3one()), 0.5);
			v3print(n);
			printf("\n");
			return (n);
		}

		vec3 unit_direction = v3unit(r.dir);
		double a = 0.5 * (unit_direction.y + 1.0);
		return (v3add( v3mul( WHITE, 1 - a),
					   v3mul(  BLUE,   a  ) ));
	}

	// image
	int image_width = 400;
	double aspect_ratio = 16.0 / 9.0;

	int image_height = image_width / aspect_ratio;
	printf("image height is %d\n", image_height);
	image_height = (image_height < 1) ? 1 : image_height;

	// camera
	double focal_length = 1.0;
	double viewport_height = 2.0;
	double viewport_width = viewport_height
							* image_width / (double)image_height;
	point3 camera_center = {};

	// viewport edges (x to the right, y down)
	// vec3 viewport_u = newv3(viewport_width, 0, 0);
	// vec3 viewport_v = newv3(0, -viewport_height, 0);

	// Delta vectors (per pixel)
	double pixel_delta_u = viewport_width / image_width;
	double pixel_delta_v = -viewport_height / image_height;

	// Upper left pixel pos
	point3 viewport_upper_left = camera_center;
	viewport_upper_left.x -= viewport_width / 2;
	viewport_upper_left.y -= -viewport_height / 2;
	viewport_upper_left.z -= focal_length;

	point3 pixel00_loc = viewport_upper_left;
	pixel00_loc.x += pixel_delta_u / 2;
	pixel00_loc.y += pixel_delta_v / 2;

	// render
	fprintf(image, "P3\n%d %d\n255\n", image_width, image_height);

	for (int j = 0; j < image_height; j++)
	{
		// printf("\rScanlines remaining: %d\n", image_height - j);
		for (int i = 0; i < image_width; i++)
		{
			point3 pixel_center = pixel00_loc;
			pixel_center.x += pixel_delta_u * i;
			pixel_center.y += pixel_delta_v * j;

			vec3 ray_direction = v3sub(pixel_center, camera_center);
			ray r = newray(camera_center, ray_direction);
			
			color pixel_color = ray_color(r);
			fwrite_color(image, pixel_color);
		}
	}
	fclose(image);
	return (0);
}
