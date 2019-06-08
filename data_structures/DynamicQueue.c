#include <stdio.h>

typedef enum { false, true } bool;
typedef int Data; 
typedef struct _Node {
   Data item; 
   struct _Node* next; 
} Node;

typedef struct {
   Node* front;
   Node* rear;
} DQueue;

// Make a queue empty. 

void InitQueue(DQueue *pqueue) { 
   pqueue->front = pqueue->rear = NULL; 
} 

// Check whether a queue is empty. 

bool IsEmpty(DQueue *pqueue) {
   return pqueue->front == NULL; 
}                                                   

//Read the item at the front. 

Data Peek(DQueue *pqueue) {
   if (IsEmpty(pqueue))
      exit(1);
}


// Insert an item at the rear. 
void EnQueue(DQueue *pqueue, Data item){
   if (IsFull(pqueue))
		exit(1); //error: stack full
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;

}
// Delete an item at the front. 
void DeQueue(DQueue *pqueue){
	if (IsEmpty(pqueue))
		exit(1); //error: empty stack
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}


int main() {

}
