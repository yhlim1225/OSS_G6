#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#include <general.h>
#include <quick_sort.h>

#define MAX_ELEMENTS 1000

int main()
{
	RAND_INIT();
	int list[MAX_ELEMENTS];

	int i = 0;
	srand(time(NULL));
	// generate random numbers and fill them to the list
	for(i = 0; i < MAX_ELEMENTS; i++ ){
		list[i] = rand()%1000;
	}
	printf("The list before sorting is:\n");
	printlist_int(list,MAX_ELEMENTS);

	// sort the list using quicksort
	quicksort(list,0,MAX_ELEMENTS-1);

	// print the result
	printf("The list after sorting using quicksort algorithm:\n");
	printlist_int(list,MAX_ELEMENTS);
	return 0;
}
