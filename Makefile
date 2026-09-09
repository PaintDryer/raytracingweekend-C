CFLAGS = -Wall -Werror -Wextra -fsanitize=address -lm -I include/
raytracer: src/main.o
	$(CC) $(CFLAGS) $^ -o raytrace.exe

src/main.o:
	$(CC) src/main.c -c $(CFLAGS) $^ -o src/main.o

clean:
	rm -rf raytracer
	rm -rf src/*.o
	rm -rf image.ppm
