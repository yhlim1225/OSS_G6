#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>

#include <general.h>
#include <selection_sort.h>

#define MAX_ELEMENTS 1000

int main()
{
	int list[MAX_ELEMENTS];

	int i = 0;

	srand(time(NULL));

	for(i = 0; i < MAX_ELEMENTS; i++ )
	{
		list[i] = rand()%1000;
	}
	printf("The list before sorting is:\n");
	printlist_int(list,MAX_ELEMENTS);

	selectionsort<int>(list, 0, MAX_ELEMENTS);  

	printf("The list after sorting using insertion sort algorithm:\n");
	printlist_int(list,MAX_ELEMENTS);
	return 0;
}
