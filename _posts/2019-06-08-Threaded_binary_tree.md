---
title: Threaded_binary_tree
date: 2019-06-08
---

Create the Threaded_binary_tree.

## Member's information
There is not Threaded_binary_tree in Open Source Project 'C Algorithms'. So we check it, and write codes.

```
#include<stdio.h>


typedef int BData;

typedef struct _bTreeNode
{
	BData item;
	struct _bTreeNode * left_child;
	struct _bTreeNode * right_child;
	bool isTheaded;
} BTreeNode;


BTreeNode* leftMost(BTreeNode* node)
{
	if (node == NULL) return NULL;
	while (node->left_child != NULL)
		node = node->left_child; // Go to the leftmost node.

	return node;
}

void inorder(BTreeNode* node)
{
	BTreeNode* cur = leftmost(node);
	while (cur != NULL) {
		printf("%d ", cur->item);
		// If the node is a thread node, go to its inorder successor.
		if (cur->isTheaded)
			cur = cur->right_child;
		else // Go to the leftmost child in a right subtree.
			cur = leftmost(cur->right_child);
	}
}

int main(){

}
```
