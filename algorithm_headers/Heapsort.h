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

using namespace std;

void display(int[], int n);

// Function to Build a heap from a given array Using the Max Heap Property
int* buildHeap(int[], int, int);

// Function used to maintain the value property of a heap by checking the value of a node with both it's children nodes
void check(int[], int, int);

// Function to implement the HeapSort by making use of the above two functions
void HeapSort(int[], int, int);
int temp;

// Function to display the arrays at each step

void display(int a[], int m)
{
    cout << endl;
    cout << "| ";
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << "\t";
    }
    cout << "|";
    cout << endl;
}

// Function to arrange the nodes of the heap according to the value property of a Max Heap

// The function uses Floyd's Method for building the heap

// It starts with the middle element and decreaments until the 1st element is reached

int* buildHeap(int a[], int n, int m)
{
    int j;

    if (n < 1)
    {
        // If first element is reached, call the check function to check value property of children
        check(a, 1, m);
        return (a);
    }
    else
    {
        if (n == m)
        {
            // Start from middle element
            j = n / 2;
        }
        else
        {
            j = n;
        }

        while (2 * j <= m)
        {
            // Check with all children

            if (a[j] > a[2 * j])
            {
                if ((a[j] < a[2 * j + 1]))
                {
                    // When parent is smaller than right child
                    temp = a[2 * j + 1];
                    a[2 * j + 1] = a[j];
                    a[j] = temp;
                    // Swapping with right child
                    j = 2 * j + 1;
                }
                else
                {
                    // If parent is greater than both children, Break from loop and proceed to next iteration

                    break;
                }
            }
            else
            {
                if ((a[j] > a[2 * j + 1]))
                {
                    // When parent is smaller than left child
                    temp = a[2 * j];
                    a[2 * j] = a[j];
                    a[j] = temp;
                    j = 2 * j;
                }
                else
                {
                    // // When parent is smaller than right child and left child
                    // Swap with larger than both children

                    temp = max(a[2 * j], a[2 * j + 1]);
                    (a[2 * j] > a[2 * j + 1] ? a[2 * j] : a[2 * j + 1]) = a[j];
                    a[j] = temp;
                    j = a[2 * j] > a[2 * j + 1] ? 2 * j : 2 * j + 1;
                }
            }
        }
        // Decreament the value of iterator
        return (buildHeap(a, j - 1, m));
    }
}

// Function to check the value property of resultant heap

void check(int a[], int n, int m)
{

    // Check the value of the node with both children. The Last node with children will be the central element

    while (n <= m / 2)
    {
        if (a[n] > a[2 * n] && a[n] > a[2 * n + 1])
        {
            // Recursive call until the middle element is reached
            check(a, n + 1, m);
            return;
        }
        else
        {
            // Else, call the buildheap function to fix the value property

            buildHeap(a, m, m);
        }
    }
}

// Function to implement HeapSort from the concerted heap

void HeapSort(int a[], int m, int n)
{
    int temp;

    // Do while the length of heap is greater than 1

    while (a[0] > 1)
    {
        // Swap the 1st element and the element stored at the a[0]th position
        temp = a[a[0]];
        a[a[0]] = a[1];
        a[1] = temp;

        // Decreament the number of nodes of the heap
        a[0]--;

        display(a, a[0] + 1);

        // Check the value property of the resultant heap
        check(a, 1, a[0] - 1);

        // Display the heap before running it for the next iteration
        display(a, a[0] + 1);
    }
    display(a, m);
    return;
}
