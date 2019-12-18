// The MIT License (MIT)

// Copyright (c) 2019 OSS_G6. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

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
static inline void swap(T &a, T &b)
{
	T temp(a);
	a = b;
	b = temp;
}

template<typename T>
static inline T min(T a, T b)
{
	return (a < b ? a:b);
}

template<typename T>
static inline T max(T a, T b)
{
	return (a > b ? a:b);
}

template<typename T>
static void printlist_int(T & list,int count) {
	int i;
	for(i=0;i<count;i++)
		printf("%d\t ",list[i]);
	printf("\n");
}
#endif
