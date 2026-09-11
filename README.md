Compiles with cc through Make.

If you don't have it you can run:

$cc src/main.c -c -Wall -Werror -Wextra -I include/ -O3  -o src/main.o -lm

$cc -Wall -Werror -Wextra -I include/ src/main.o -o raytrace.exe -lm

run make:

$make

run the file:

$./raytrace.exe

enjoy the generated ppm

Divergence:
Due to lack of classes, vectors and shared pointers I defined an objects.h header that manages the objects as an array holding discrimined unions fo the type. For now there's only the sphere type

TODO:
apply interval functions
implement camera.h to declutter main
test the object arrays lol
