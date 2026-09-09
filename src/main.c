#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#define WHITE v3one()
#define BLUE newv3(0.5, 0.7, 1.0)

int	main(void)
{
	// file opening
	FILE *image = fopen("image.ppm", "w");
	if (image == NULL)
	{
		printf("Failed to open image\n");
		return (1);
	}
	
	color ray_color(const ray r)
	{
		vec3 unit_direction = v3unit(r.dir);
		double a = 0.5 * (unit_direction.y + 1.0);
		return (v3add( v3mul( WHITE, 1 - a),
					   v3mul(  BLUE,   a  ) ));
	}

	// image
	int image_width = 400;
	double aspect_ratio = 16.0 / 9.0;

	int image_height = image_width / aspect_ratio;
	image_height = (image_height < 1) ? 1 : image_height;

	// camera
	double focal_length = 1.0;
	double viewport_height = 2.0;
	double viewport_width = viewport_height
							* image_width / (double)image_height;
	point3 camera_center = v3zero();

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
		printf("\rScanlines remaining: %d\n", image_height - j);
		for (int i = 0; i < image_width; i++)
		{
			point3 pixel_center = pixel00_loc;
			// pixel_center = v3add(pixel_center, v3mul(pixel_delta_u, i));
			// pixel_center = v3add(pixel_center, v3mul(pixel_delta_v, j));
			pixel_center.x += pixel_delta_u * i;
			pixel_center.y += pixel_delta_v * j;

			vec3 ray_direction = v3sub(pixel_center, camera_center);
			ray r = (ray){.orig = camera_center, .dir = ray_direction};
			
			color pixel_color = ray_color(r);
			fwrite_color(image, pixel_color);
		}
	}
	fclose(image);
	return (0);
}
