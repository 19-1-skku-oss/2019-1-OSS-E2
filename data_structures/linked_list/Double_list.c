#include<stdio.h>

typedef enum { false, true } bool;
typedef int Data;
typedef struct _Node { 
	Data item; 
	struct _Node* prev;
	struct _Node* next; 
} Node;

typedef struct { 
	Node* head; 
	int len; 
} DoubleLinkedList;

void InitList(DoubleLinkedList* plist);
void InsertMiddle(DoubleLinkedList* plist, int pos, Data item);
void RemoveMiddle(DoubleLinkedList* plist, int pos);

int main() {
 int x=0,item, num;  
 printf("\t****Double linked list****\n");
	while(x!=4)
	{
		printf("enter your choice");
		printf("\n1.Init List
		       \n2.Insert Middle
		       \n3Remove List
		       \n4.exit
		       \n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				InitList(DoubleLinkedlist);
			  	 break;
			case 2:
		  		break;
			case 3: 
			      	break;
			case 4: return 0;
			      
		}
	}
	

}

void InitList(DoubleLinkedList* plist) {
	Node* dummy1, *dummy2; 
	dummy1 = (Node*)malloc(sizeof(Node)); 
	dummy2 = (Node*)malloc(sizeof(Node));

	dummy1->prev = NULL;
	dummy1->next = dummy2;
	dummy2->prev = dummy1;
	dummy2->next = NULL;

	plist->head = dummy1; 
	plist->len = 0;
}

void InsertMiddle(DoubleLinkedList* plist, int pos, Data item) {
	Node *cur, *newNode;

	cur = plist->head;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = cur->next;
	newNode->prev = cur;
	cur->next = newNode;
	cur->prev = newNode;
	plist->len++;
}

void RemoveMiddle(DoubleLinkedList* plist, int pos) {
	Node *cur, *temp;
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) exit(1);
	cur = plist->head;
	for (int i = 0; i < pos; i++) {
		cur = cur->next;
	}
	temp = (Node*)malloc(sizeof(Node));
	temp = cur->next;
	temp->next->prev = cur;
	cur->next = temp->next;
	plist->len--;
	free(temp);
}
