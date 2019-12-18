#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include <general.h>
#include <merge_sort.h>

#define MAX_ELEMENTS 1000

int main()
{
	int list[MAX_ELEMENTS];

	int i = 0;
	// generate random numbers and fill them to the list
	for(i = 0; i < MAX_ELEMENTS; i++ ){
		list[i] = rand()%1000;
	}

	printf("The list before sorting is:\n");
	printlist_int(list,MAX_ELEMENTS);

	// sort the list using quicksort
	merge_sort<int>(list,0,MAX_ELEMENTS-1);

	// print the result
	printf("The list after sorting using merge sort algorithm:\n");
	printlist_int(list,MAX_ELEMENTS);
	return 0;
}
