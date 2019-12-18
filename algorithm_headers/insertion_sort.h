#ifndef _INSERTION_SORT_H__
#define _INSERTION_SORT_H__
template<typename T>
static void insertion_sort(T& item_list , int len ) {
	int i,j;
	for(i = 1; i < len; i++) 
	{
		T current = item_list[i];
		j = i-1;
		while(j>=0 && item_list[j] > current) {
			item_lsit[j+1] = item_list[j];
			j--;
		}
		item_list[j+1] = current;
	}
}
#endif
