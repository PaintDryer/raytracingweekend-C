# CFLAGS = -Wall -Werror -Wextra -fsanitize=address -lm -I include/
CFLAGS = -Wall -Werror -Wextra -I include/
raytracer: src/main.o
	$(CC) $(CFLAGS) $^ -o raytrace.exe -lm

debug: src/debugmain.o
	$(CC) $(CFLAGS) $^ -o raytracedebug.exe -lm

src/main.o:
	$(CC) src/main.c -c $(CFLAGS) -O3 $^ -o src/main.o -lm

src/debugmain.o:
	$(CC) src/main.c -c $(CFLAGS) -g $^ -o src/debugmain.o -lm

clean:
	rm -rf raytrace*
	rm -rf *debug.exe
	rm -rf src/*.o
	rm -rf image.ppm
