Compiles with cc through Make. If you don't have it you can run:
$cc src/main.c -c -Wall -Werror -Wextra -I include/ -O3  -o src/main.o -lm
$cc -Wall -Werror -Wextra -I include/ src/main.o -o raytrace.exe -lm

run make:
$make

run the file:
$./raytrace.exe

enjoy the generated ppm
