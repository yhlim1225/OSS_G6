#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>

#include <general.h>
#include <insertion_sort.h>

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

	// sort the list using insertion sort
	insertion_sort<int>(list,MAX_ELEMENTS);  

	// print the result
	printf("The list after sorting using insertion sort algorithm:\n");
	printlist_int(list,MAX_ELEMENTS);
	return 0;
}
