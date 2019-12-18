#ifndef _GENERAL_H__
#define _GENERAL_H__

//Random, Swap

#include <stdlib.h>
#include <stdint.h>

#define Max(a, b) ( (a > b) ? a : b )
#define Min(a, b) ( (a < b) ? a : b )

#define RAND_INIT()	srand(time(NULL))
#define RAND(b, e)	(b + rand() % ((e) - (b) + 1))

template<typename T>
static inline void swap(T &a, T &y)
{
	T temp(a);
	a = b;
	b = temp;
}
