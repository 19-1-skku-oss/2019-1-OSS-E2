#include <stdio.h>
#include <stdlib.h>


typedef enum { false, true } bool;
typedef int Data;

typedef struct _Node {
   Data item; 
   struct _Node* next; 
} Node;

typedef struct {
   Node* top; 
} DStack;

// Make stack empty. 

void InitStack(DStack *pstack) {
   pstack->top = NULL;
}

// check whether stack is empty. 

bool IsEmpty(DStack *pstack) {
   return pstack->top == NULL;
}

// Read the item at the top. 

Data Peek(DStack *pstack) {
   if (IsEmpty(pstack)) exit(1);
   return pstack->top->item;
}

// Insert an item at the top. 

void Push(DStack *pstack, Data item) {
   Node *newNode = (Node*)malloc(sizeof(Node));
   newNode->item = item;
   newNode->next = pstack->top;
   pstack->top = newNode;
}

// Remove the item at the top. 

void Pop(DStack *pstack) {
   if(IsEmpty(pstack)) exit(1);
   Node* temp;
   temp = pstack->top;
   pstack->top = pstack->top->next;
   free(temp);
}

int main() {
//will write later
}
