/*Includes structure for a node which can be use to make new nodes of the Linked List.
  It is assumed that the data in nodes will be an integer, though
  function can be modified according to the data type, easily.
  deleteNode deletes a node when passed with a key of the node.
*/
#include <stdio.h>

struct node
{
  int info;
  struct node *link;
};

struct node* start = nullptr;
///////////////////////////////////////////////////////////

struct node* createnode()//function to create node
{
  struct node* t;
  t = (struct node*)malloc(sizeof(struct node));
  return(t);
}
///////////////////////////////////////////////////////////

void insert()// function to insert at first location
{
  struct node* p;
  p = createnode();
  printf("\nEnter the number to insert : ");
  scanf("%d", &(p->info));
  p->link = nullptr;
  if(start == nullptr)
      start = p;
  else
  {
      p->link = start;  // insert at first location, not last location
      start = p;
  }
}
///////////////////////////////////////////////////////////

void deleteion()//function to delete from first position
{
    struct node* t;
    if(start == nullptr)
        printf("\nList is empty!\n");
    else
    {
        struct node* p;
        p = start;
        start = start->link;
        free(p);  // delete the data of node which was at first position
    }
}
///////////////////////////////////////////////////////////

void viewlist()//function to display values
{
    struct node* p;
    if(start == nullptr)
        printf("\nList is empty!\n");
    else
    {  
        p = start;
        while(p != nullptr)
        {
            printf("%d ",p->info);
            p = p->link;
        }
        printf("\n");
    }
}
///////////////////////////////////////////////////////////

int main()
{
    int n;
    while(1)
    {
        printf("\n1. add value at first location");
        printf("\n2. delete value from first location");
        printf("\n3. view value");
        printf("\nEnter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert();
            break;
        case 2:
            deleteion();
            break;
        case 3:
            viewlist();
            break;
        default:
            printf("\nInvalid choice!\n");
        }
    }
  
    return 0;
}
