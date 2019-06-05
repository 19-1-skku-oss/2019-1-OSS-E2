#include<stdio.h>

int Height(BTreeNode *node){
  int r = 0, l = 0;
  if (node->right_child != NULL)
  r = Height(node->right_child);
  if (node->left_child != NULL)
  l = Height(node->left_child);
  return 1 + max(r, l);
}

int main(){

}
