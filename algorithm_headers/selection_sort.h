#ifndef _SELECTION_SORT_H__
#define _SELECTION_SORT_H__
#include <assert.h>
#include <general.h>

template<typename T>
static void SelectionSort(T& item_list, int start, int end) {
	int i,j;
	int min_index;

	assert(start <= end);

	for(j = start; j <= end-1; j++) {
		min_index = j;
		for(i = j+1; i <= end; i++) {
			if (item_list[i] < item_list[min_index]) {
				min_index = i;
			}
		}

		if (min_index != j) {
			swap(item_list[j], item_list[min_index]);
		}
	}
}

#endif
