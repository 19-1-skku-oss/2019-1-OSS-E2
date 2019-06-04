#include<stdio.h>

typedef enum { false, true } bool; 
typedef int Data;
typedef struct _Node { 
	Data item; 
	struct _Node* next; 
} Node;
typedef struct {
	Node* tail; 
	int len; 
} CircularList;


bool IsEmpty(CircularList* plist);
void InitList(CircularList* plist);

void InsertInit(CircularList* plist, Data item);
void InsertFirst(CircularList* plist, Data item);
void InsertLast(CircularList* plist, Data item);
void InsertMiddle(CircularList* plist, int pos, Data item);

void RemoveInit(CircularList* plist);
void RemoveFirst(CircularList* plist);
void RemoveLast(CircularList* plist);
void RemoveMiddle(CircularList* plist, int pos);

Data ReadItem(CircularList* plist, int pos);
void PrintList(CircularList* plist);
void ClearList(CircularList* plist);

//--------------------------------------------------
int main() {

}

// Make a list empty. 
void InitList(CircularList* plist) {
	plist->len = 0;
}
// Check whether the list is empty. 
bool IsEmpty(CircularList* plist) {
	return plist->len != 0;
}

void InsertInit(CircularList* plist, Data item) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = newNode;
	
	plist->tail= newNode;
	plist->len++;
}
void InsertFirst(CircularList* plist, Data item) {
	if (plist->len == 0) InsertInit(plist, item);
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->item = item;
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->len++;
	}
}

void InsertLast(CircularList* plist, Data item) {
	if (plist->len == 0) InsertInit(plist, item);
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->item = item;
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
		plist->len++;
	}
}

void InsertMiddle(CircularList* plist, int pos, Data item) {
	if (plist->len == 0) InsertInit(plist, item);
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		Node* cur;

		cur= plist->tail;
		for (int i = 0; i < pos; i++) {
			cur = cur->next;
		}

		newNode->item = item;
		newNode->next = cur->next;
		cur->next = newNode;
		plist->len++;
	}
}

void RemoveInit(CircularList* plist) {
	if (IsEmpty(plist)) exit(1);
	if (plist->len == 1) {
		free(plist->tail);
		plist->len--;
		plist->tail = NULL;
	}
}

void RemoveFirst(CircularList* plist) {
	if (plist->len == 1) RemoveInit(plist);
	else {
		Node* temp = plist->tail->next;
		plist->tail->next = temp->next;
		free(temp);
		plist->len--;
	}
}
void RemoveLast(CircularList* plist) {
	if (plist->len == 1) RemoveInit(plist);
	else {
		Node *cur, *temp; 
		cur = plist->tail; 
		for (int i = 0; i < plist->len - 1; i++) 
			cur = cur->next; 
		temp = cur->next; 
		cur->next = temp->next;
		free(temp);
		plist->tail = cur; 
		plist->len--;
	}
}
void RemoveMiddle(CircularList* plist, int pos) {
	if (plist->len == 1) RemoveInit(plist);
	else {
		Node *cur, *temp;
		cur = plist->tail;
		for (int i = 0; i < pos - 1; i++)
			cur = cur->next;
		temp = cur->next;
		cur->next = temp->next;
		free(temp);
		plist->len--;
	}
}

// Read an item at the k-th position. 
Data ReadItem(CircularList* plist, int pos) {
	return plist->tail->next->item;
}
// Print each item in a list in sequence. 
void PrintList(CircularList* plist) {
	for (Node* cur = plist->tail->next; cur != NULL; cur = cur->next) 
		printf("%d\n", cur->item);
}
// Remove all nodes in a list in sequence. 
void ClearList(CircularList* plist) {
	
}


