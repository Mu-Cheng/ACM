#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct treenode *bintree;
// typedef bintree position;

typedef struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
} treenode, *bintree;

void preorderTraversal(bintree bt);
bintree insert(int x, bintree bt);

int main() {
	struct treenode *bit;
	int i, x;
	bit = NULL;
	int n;
	scanf("%d", &n);

	for (i = 0; i<n; i++) {
		scanf("%d", &x);
		//	printf("%d\n",x);
		bit = insert(x, bit);
		//	 printf("%d",bit->data);
	}
	preorderTraversal(bit);
}

void preorderTraversal(bintree bt) {
	if (bt!=NULL) {
		preorderTraversal(bt->left);
		printf("%d ", bt->data);
		preorderTraversal(bt->right);
	}
}
bintree insert(int x, bintree bt) {
	if (!bt) {
		bt = (bintree)malloc(sizeof(struct treenode));
	
		if (bt)
			bt->data = x;
		else
			return NULL;
		bt->left = bt->right = NULL;
	} else if (x < bt->data) {
		bt->left = insert(x, bt->left);
	} else if (x > bt->data) {
		bt->right = insert(x, bt->right);
	}
	//	printf("%d",x);
	return bt;
}
