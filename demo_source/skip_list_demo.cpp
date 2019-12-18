// The MIT License (MIT)

// Copyright (c) 2019 OSS_G6. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <stdio.h>
#include "skip_list.h"

#define MAX_ELEMENTS 20

int main()
{
	SkipList<int, int> ss;

	srand(time(NULL));
	
	for(int i = 0; i < MAX_ELEMENTS; i++ ){
		ss.insert(i, rand()%100);
	}

	printf("Skip list :\n");
	ss.print();

	printf("Random get keys :\n");
	for(int i = 0; i < MAX_ELEMENTS; i++ ){
		int r = rand()%100;
		try {
			printf("get: %d->%d\n",r, ss[r]); 
		} catch (std::exception &e) {
			printf("%s\n", e.what());
		}
	}
	
	printf("Random deleteion:\n");
	for(int i = 0; i < MAX_ELEMENTS; i++ ){
		int r = rand()%100;
		printf("delete key :%d\n",r); 
		ss.delete_key(r);
	}

	printf("The skip list after deletion:\n");
	ss.print();

	return 0;
}
