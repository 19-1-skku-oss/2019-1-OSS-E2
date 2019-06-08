#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *leftNode;
    int data;
    struct node *rightNode;
};


int Height(node *nod){
  int r = 0, l = 0;
  if (nod->rightNode != NULL)
  r = Height(node->leftNode);
  if (nod->leftNode != NULL)
  l = Height(nod->leftNode);
  return 1 + max(r, l);
}


int main(){
  //sample
  int h;
  struct node *root = (struct node *)malloc(sizeof(struct node));
  h = height(root);
  
  return 0;
}
