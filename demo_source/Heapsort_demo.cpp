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

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include"Kruskal.h"

using namespace std;

// Function to Build a heap from a given array Using the Max Heap Property
int *buildHeap(int[], int, int);

// Function used to maintain the value property of a heap by checking the value of a node with both it's children nodes
void check(int[], int, int);

// Function to implement the HeapSort by making use of the above two functions
void HeapSort(int[], int, int);
int temp;
int main()
{
    // Hardcoded Given array of numbers, with Random Null nodes, indicated by -1

    int arr[30] = { 0, 2, 7, 98, -1, 21, -1, 10, 1, 9, -1, 14, 75, 88, 4, -1, 50, 42, -1, 100, 89, -1, 49, 70, 69, -1, 55, 20, -1, -1 };
    int size_of_heap = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    for (int i = 1; i < size_of_heap; i++)
    {
        if (arr[i] != -1)
        {
            count++;
        }
    }
    cout << endl;
    cout << "The given random Array of numbers is: " << endl;
    display(arr, size_of_heap);
    cout << endl;

    // Creating an array for numbers in the heap, by getting rid of the null nodes

    int heap[count + 1];
    int o = 1;
    for (int j = 1; j < size_of_heap; j++)
    {
        if (arr[j] != -1)
        {
            heap[o] = arr[j];
            o++;
        }
    }
    // Setting the 0th element of the heap array as the number of values in the array

    heap[0] = count;
    cout << "The value of the nodes in the heap after dropping the null nodes is: " << endl;
    display(heap, count + 1);
    cout << endl;

    // Array pointer for assignment of the return value from the declared function

    int* p[22];
    *p = buildHeap(heap, count + 1, count + 1);

    cout << "The resultant heap array, satisfying the value property from the given array of random numbers is: " << endl;
    display(*p, count + 1);
    cout << endl;

    // Calling the function to implement Heapsort

    cout << "Implementation of Heapsort :" << endl;
    display(*p, count + 1);
    HeapSort(*p, count + 1, count + 1);
    cout << endl;
    cout << "The Resultant array sorted in ascending order using HeapSort is: " << endl;
    display(*p, count + 1);
    cout << endl;
    cout << "The end" << endl;
}
