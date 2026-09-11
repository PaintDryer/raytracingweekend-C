#ifndef OBJECTS_H
#define OBJECTS_H

#include "sphere.h"

typedef struct sphere_t
{
    point3  center;
    double  radius;
} sphere;

typedef enum o_type
{
    SPHERE
    // Quad
    // ...
} ObjectType;

typedef struct object_t
{
    ObjectType type;
    union
    {
        struct sphere_t s;
        // Quad quad;
        // ...
    } object_u;
} object;

static inline object newSphObject(point3 center, double radius)
{
	return (object){ .type = SPHERE,
					 .object_u.s = (sphere){ center, radius } }; 
}

// will hold a count of the size, pointer to the contiguous memory, current number of elements, offer a way to iterate
typedef struct world_t
{
	object	*objectArr;
	int		slotcount;
	int		objectcount;
} world;

// default size of 32
world initialize()
{
	int default_size = 32;
	world w;
	w.objectArr = (object *)malloc(sizeof(object) * default_size);
	w.slotcount = default_size;
	w.objectcount = 0;
	return (w);
}

void add(world *w, object o)
{
	if (w->objectcount == w->slotcount)
	{
		printf("Out of room for new objects! Implement memory additions\n");
		return;
		// TO DO: allocate more memory somehow
	}
	w->objectArr[w->objectcount] = o;
	w->objectcount++;
}
#endif
