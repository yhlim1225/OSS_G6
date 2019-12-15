#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef enum { RED, BLACK } rbt_color;

class rbt_node {
	public :
		int key;
		rbt_node *parent;
		rbt_node *left;
		rbt_node *right;
		rbt_color color;
} *nullptr = {};

class rbt_tree {
	public:
		rbt_node *root;
};

void rotate_left(rbt_tree *T, rbt_node *x);
void rotate_right(rbt_tree *T, rbt_node *x);
rbt_tree *rbt_create();	
rbt_node *insert(rbt_tree *T, int key);	
void insert_rbt(rbt_tree *T, rbt_node *z);
void insert_rbt_fixup(rbt_tree *T, rbt_node *z);
void print_preorder(rbt_node *x);
void print_inorder(rbt_node *x);

void rotate_left(rbt_tree *T, rbt_node *x){
	rbt_node* y = x->right;
	x->right = y->left;
	if(y->left != nullptr)
		y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == nullptr){
		T->root = y;
	}
	else if(x == x->parent->left){
		x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}
void rotate_right(rbt_tree *T, rbt_node *x){
    rbt_node* y = x->left;
    x->left = y->right;
    if(y->right != nullptr){
        y->right->parent = x;
    }
    y->parent = x->parent; 
    if(x->parent == nullptr){ 
        T->root = y;
    }
    else if(x == x->parent->right){
        x->parent->right = y;
    }
    else{
        x->parent->left = y;
    }
    y->right = x; 
    x->parent = y; 
}
rbt_tree *rbt_create(){
    rbt_tree* T = (rbt_tree*)malloc(sizeof(rbt_tree)); 

    T->root = nullptr; 

    return T; 
}

rbt_node *insert(rbt_tree *T, int key){
    rbt_node* x = (rbt_node*)malloc(sizeof(rbt_node)); 

    x->key = key;
    x->parent = nullptr;
    x->left = nullptr;
    x->right = nullptr;
    x->color = RED;

    insert_rbt(T, x); 
    return x; 
}
void insert_rbt(rbt_tree *T, rbt_node *z){
    rbt_node* y = nullptr;
    rbt_node* x = T->root;
    
    while(x != nullptr){
        y = x; 
        if(z->key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    z->parent = y; 
    if(y == nullptr){ 
        T->root = z;
    }
    else if(z->key < y->key){ 
        y->left = z;
    }
    else{ 
        y->right = z;
    }
    z->left = nullptr;
    z->right = nullptr;
    z->color = RED;
    insert_rbt_fixup(T, z);
}
void insert_rbt_fixup(rbt_tree *T, rbt_node *z){
    rbt_node* y;
    while(z->parent != nullptr && z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right; 
            if(y != nullptr && y->color == RED){ 
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{ 
                if(z == z->parent->right){ 
                    z = z->parent;
                    rotate_left(T, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotate_right(T, z->parent->parent);
            }
        }
        else{
            y = z->parent->parent->left;
            if(y != nullptr && y->color == RED){ 
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->left){ 
                    z = z->parent;
                    rotate_right(T, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotate_left(T, z->parent->parent);
            }

        }
    }
    T->root->color = BLACK;
}
void print_preorder(rbt_node *x) {
	if (x == nullptr) return;
	if(x->color == RED) printf("-%d-", x->key);
	else printf("<%d>", x->key);
	print_preorder(x->left);
	print_preorder(x->right);
}

void print_inorder(rbt_node *x) {
	if (x == nullptr) return;
	print_inorder(x->left);
	if (x->color == RED) printf("-%d-", x->key);
	else printf("<%d>", x->key);
	print_inorder(x->right);
}

#endif