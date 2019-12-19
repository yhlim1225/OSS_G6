//The MIT License (MIT)

//Copyright (c) 2019 OSS_G6. All rights reserved.

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.



#include<iostream>
#include<vector>
#include"BST.h"
using namespace std;


int main()
{
	struct node* root = NULL;
	struct node* root1 = NULL;
	struct node* root2 = NULL;
	root1 = Insert(30, root1);
	Insert(20, root1);
	Insert(50, root1);
	Insert(10, root1);
	Insert(80, root1);
	Insert(40, root1);
	Insert(70, root1);
	PrintPreorder(root1);

	Delete(70, root1);
	Delete(20, root1);
	Delete(50, root1);

	PrintPreorder(root1);


	Insert(70, root1);
	Insert(20, root1);
	PrintPreorder(root1);


	root1 = Balance(root1);
	PrintPreorder(root1);


	root2 = Insert(50, root2);
	Insert(60, root2);
	Insert(90, root2);
	PrintPreorder(root2);


	root2 = Balance(root2);
	PrintPreorder(root2);

	cout << endl;
	return 0;
}
