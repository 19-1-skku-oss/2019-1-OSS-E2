#include<stdio.h>

typedef struct _GNode
{
	int id;
	struct _GNode* next;
} GNode;

typedef struct 
{
	int num;
	GNode** heads;
} Graph;

void CreateGraph(Graph* pgraph, int num)
{
	pgraph->num = num;
	pgraph->heads = (GNode **)malloc(sizeof(GNode*)* num);
	for (int i = 0; i < num; i++) {
		// Make a dummy node.
		pgraph->heads[i] = (GNode *)malloc(sizeof(GNode));
		pgraph->heads[i]->next = NULL;
	}
}

void DestroyGraph(Graph* pgraph)
{
	for (int i = 0; i < pgraph->num; i++) {
		GNode* cur = pgraph->heads[i];
		while (cur != NULL) {
			GNode* temp = cur;
			cur = cur->next;
			free(temp);
		}
	}
	free(pgraph->heads);
}

int main()
{

  //sample
	Graph g;
	CreateGraph(&g, 5);
	AddEdge(&g, 0, 1);
	AddEdge(&g, 0, 2);
	AddEdge(&g, 0, 4);
	AddEdge(&g, 1, 2);
	AddEdge(&g, 2, 3);
	AddEdge(&g, 2, 4);
	AddEdge(&g, 3, 4);
	
	PrintGraph(&g);
	DestroyGraph(&g);

	return 0;
}
