#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"

int	main(void)
{
	FILE *image = fopen("image.ppm", "w");
	
	if (image == NULL)
	{
		printf("Failed to open image\n");
		return (1);
	}
	
	int image_width = 256;
	int image_height = 256;

	fprintf(image, "P3\n%d %d\n255\n", image_width, image_height);

	for (int j = 0; j < image_height; j++)
	{
		printf("\rScanlines remaining: %d\n", image_height - j);
		for (int i = 0; i < image_width; i++)
		{
			color pixel_color =
				newv3( i / (image_width - 1.0),
					   j / (image_height - 1.0),
					   0);
			fwrite_color(image, pixel_color);
		}
	}
	fclose(image);
	return (0);
}
