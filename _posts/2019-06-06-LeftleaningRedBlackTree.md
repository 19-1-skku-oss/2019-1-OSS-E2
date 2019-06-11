---
title: Left-leaning red black tree
date: 2019-06-06
---

Create Left-leaning red black tree

## Left-leaning red black tree
To write left-leaning red black tree, we should think to create node to connect. Below codes are related to nodes.

```C Language
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define COUNT 5

typedef struct node {
	struct node *left;
	struct node *right;
	int data;
	//red = 1, black = 0;
	int color;
} node;


node *makenode(int data, int color) {

	node *nod = (node *) malloc(sizeof(node));
	nod->left = NULL;
	nod->right = NULL;
	nod->data = data;
	nod->color = color;

	return nod;
}

node *movleft(node *nod) {
	node *moved = nod->right;
	node *movedL = moved->left;

	moved->left = nod;
	nod->left = movedL;

	return moved;
}

node *movright(node *nod) {
	node *moved = nod->left;
	node *movedR = nod->right;

	moved->right = nod;
	nod->left = movedR;

	return moved;
}

node *insert(node *nod, int data) {
	int c;
	if (nod == NULL) {
		return makenode(data, 1);
	}

	else if (data < nod->data) {
		nod->left = insert(nod->left, data);
	}
	else if (data > nod->data) {
		nod->right = insert(nod->right, data);
	}
	else {
		return nod;
	}

	if (nod->left->color == 0 && nod->right->color == 1) {
		nod = movleft(nod);
		c = nod->color;
		nod->color = nod->left->color;
		nod->left->color = c;
	}

	if (nod->left->color == 1 && nod->left->left->color == 1) {
		nod = movright(nod);
		c = nod->color;
		nod->color = nod->right->color;
		nod->right->color = c;
	}
	if (nod->left->color == 1 && nod->right->color == 1) {
		nod->color = (1 - nod->color);
		nod->left->color = 0;
		nod->right->color = 0;
	}

	return nod;
}


int main() {
	node *root = NULL;
	char *cmd = malloc(sizeof(char) * 10);
	int num;

	printf("What do you want to do?\n");
	scanf("%s", cmd);

	while (strcmp(cmd, "end")) {
		if (strcmp(cmd, "insert")) {
			scanf("%d", &num);
			insert(root, num);
			printf("Done.\n");
		}
		else if (strcmp(cmd, "delete")) {

			printf("Done.\n");
		}
		else {
			printf("Wrong input. Please retry.\n");
		}

		cmd = NULL;
		printf("What do you want to do?\n");
		scanf("%s", cmd);
	}

	return 0;
}
```
