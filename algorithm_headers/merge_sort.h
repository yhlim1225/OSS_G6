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

#ifndef _MERGE_SORT_H__
#define _MERGE_SORT_H__

template<typename T>
static void merge_(T *array, int left, int mid, int right)
{

	T tempArray[right-left+1];
	int pos=0,lpos = left,rpos = mid + 1;
	while(lpos <= mid && rpos <= right) 
	{
		if(array[lpos] < array[rpos]) 
		{
			tempArray[pos++] = array[lpos++];
		}
		else 
		{
			tempArray[pos++] = array[rpos++];
		}
	}
	while(lpos <= mid)  tempArray[pos++] = array[lpos++];
	while(rpos <= right)tempArray[pos++] = array[rpos++];
	int iter;
	for(iter = 0;iter < pos; iter++)
	{
		array[iter+left] = tempArray[iter];
	}
	return;
}

template<typename T>
static void merge_sort(T *array, int left, int right) 
{
	int mid = (left+right)/2;
	if(left<right) 
	{
		merge_sort(array,left,mid);
		merge_sort(array,mid+1,right);
		merge_(array,left,mid,right);
	}
}
#endif
