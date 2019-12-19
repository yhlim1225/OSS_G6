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
using namespace std;

struct node
{
	int key;
	node* left;
	node* right;
};

struct node* New(int data)
{
	node* Node = (node*)malloc(sizeof(node));
	Node->key = data;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

void PrintPreorder(struct node* node)
{
	if (node == NULL) return;
	cout << node->key << " ";
	PrintPreorder(node->left);
	PrintPreorder(node->right);
}

struct node* Insert(int key, node* node)
{
	if (node == NULL) return New(key);
	if (key < node->key) node->left = Insert(key, node->left);
	if (key > node->key) node->right = Insert(key, node->right);
	return node;
}

node* make(int start, int end, vector<node*>& nodes)
{
	if (start > end) return NULL;
	int mid = (start + end) / 2;
	node* root = nodes[mid];
	root->left = make(start, mid - 1, nodes);
	root->right = make(mid + 1, end, nodes);
	return root;
}

void tmpNode(node* root, vector<node*>& nodes)
{
	if (root == NULL) return;
	tmpNode(root->left, nodes);
	nodes.push_back(root);
	tmpNode(root->right, nodes);
}

node* Balance(struct node* root)
{
	vector<node*> bal;
	tmpNode(root, bal);
	return make(0, bal.size() - 1, bal);
}

struct node* Delete(int key, struct node* root)
{
	if (root == NULL) return root;
	if (key == root->key) {
		if (root->left == NULL) {
			struct node* next = root->right;
			free(root);
			return next;
		}
		else if (root->right == NULL) {
			struct node* next = root->left;
			free(root);
			return next;
		}
		node* next = root->right;
		while (next->right && next->left != NULL) next->right = next->right->left;
		root->key = next->key;
		root->right = Delete(next->key, root->right);
	}
	else if (key < root->key) root->left = Delete(key, root->left);
	else if (key > root->key) root->right = Delete(key, root->right);

	return root;
}
