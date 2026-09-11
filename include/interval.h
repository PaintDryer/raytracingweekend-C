#ifndef INTERVAL_H
#define INTERVAL_H

typedef struct
{
	double min;
	double max;
} interval;


static inline interval newinterval(double min, double max)
{
	if (!max)
		max = +infinity;
	// cannot set default value of -infinity due to no overloads 
	return (interval){ min, max };
}

static inline interval emp_interval()
{
	return newinterval(+infinity, -infinity);
}

static inline interval uni_interval()
{
	return newinterval(-infinity, +infinity);
}

bool contains(interval i, double x)
{
	return (i.min <= x && x <= i.max);
}

bool surrounds(interval i, double x)
{
	return (i.min < x && x < i.max);
}
#endif
