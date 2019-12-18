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

#ifndef _QSORT_H__
#define _QSORT_H__

#include <general.h> 

template<typename T>
static int partition_(T item_list[], int begin, int end) 
{
	int pivot_idx = RAND(begin,end);
	T pivot = item_list[pivot_idx];
	swap(item_list[begin], item_list[pivot_idx]);

	int i = begin + 1;
	int j = end;

	while(i <= j) 
	{
		while((i <= end) && (item_list[i] <= pivot))
			i++;
		while((j >= begin) && (item_list[j] > pivot))
			j--;
		if(i < j)
			swap(item_list[i],item_list[j]);
	}

	swap(item_list[begin],item_list[j]);
	return j; // final pivot position
}

template<typename T>
static void quicksort(T item_list[],int begin,int end) 
{
	if( begin < end) 
	{
		int pivot_idx = partition_<T>(item_list, begin, end);
		quicksort(item_list, begin, pivot_idx-1);
		quicksort(item_list, pivot_idx+1, end);
	}
}

#endif
