#ifndef RADIX_H_INCLUDED
#define RADIX_H_INCLUDED

#include <queue>

void radix(int arr[], int size){
	int tmp[size];
	std::queue<int> radix[10];

	int max = arr[0];
	int d = 1;
	int mod = 10;
	int dMin = 1;
	for(int i = 1 ; i < size ; i++)
		if(max < arr[i]) max = arr[i];

	while(max/10){
		d *= 10;
		max /= 10;
	}

	while(dMin <= d){
		for (int i = 0 ; i < size ; i++)
			radix[(arr[i] % mod)/dMin].push(arr[i]);
		for(int i = 0, j = 0; i < 10 ;){
			if(radix[i].size()){
				arr[j++] = radix[i].front();
				radix[i].pop();
			}
			else i++;
		}
		dMin *= 10;
		mod *= 10;
	}
}

#endif