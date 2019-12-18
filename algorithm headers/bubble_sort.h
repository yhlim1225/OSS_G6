ifndef _BUBBLE_SORT_H
define _BUBBLE_SORT_H

#include <assert.h>
#include <general.h>

template<typename T>
static void BubbleSort(T item_list[], int start, int end)
{
	int i;
	bool swap = true;
	assert(start < end);
	while(swap)
	{
		swap = false;
		for(i = start+1; i <= end; i++)
		{
			if(item_list[i-1] > item_list[i])
			{
				swap(item_list[i-1], item_list[i]);
				swap=true;
			}
		}
	}
}
#endif
