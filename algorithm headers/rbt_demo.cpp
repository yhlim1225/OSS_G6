#include "rbt.h"
#include <stdio.h>

int main(){
	rbt_tree *T = rbt_create();
	int n, tmp;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &tmp);
		insert(T, tmp);
	}
	print_inorder(T->root);
	printf("\n");
	print_preorder(T->root);
	return 0;
}