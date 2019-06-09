/* Includes the functions for Recursive Traversals
   of a Binary Tree. It is assumed that nodes and
   tree have been created as per create_node.c
 */

#include <stdio.h>

struct node* inOrderTraversal(struct node *node)
{
    if(node == NULL) //if tree is empty
        return node;

    inOrderTraversal(node->leftNode);
    printf("\t%d\t", node->data);
    inOrderTraversal(node->rightNode);
}

struct node* preOrderTraversal(struct node *node)
{
    if(node == NULL) //if tree is empty
        return node;

    printf("\t%d\t", node->data);
    preOrderTraversal(node->leftNode);
    preOrderTraversal(node->rightNode);
}

struct node* postOrderTraversal(struct node *node)
{
    if(node == NULL) //if tree is empty
        return node;

    postOrderTraversal(node->leftNode);
    postOrderTraversal(node->rightNode);
    printf("\t%d\t",node->data);
}

int main(void)
{
    /* traversals can be done by simply invoking the
       function with a pointer to the root node.
    */

	return 0;
}
