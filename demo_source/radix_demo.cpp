#include "radix.h"
#include <stdio.h>

int main(){
	int arr[] = {101, 203, 305, 1437, 79, 579, 12, 46};
	radix(arr, sizeof(arr)/sizeof(arr[0]));
	for(int i = 0 ; i < 8 ; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}