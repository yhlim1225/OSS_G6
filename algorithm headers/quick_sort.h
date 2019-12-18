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
