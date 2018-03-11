#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int info;
struct node* next;
}node;

node *start = NULL;

void create(int);
void display(node*);
void search(node*, int);
void insert(node*, int);
void insert_start(node*);
void delete(node*, int);
void delete_pos(node*, int);
void modify(node*, int);

void main()
{
	int n, c, ele;
	printf("\n Enter initial number of nodes");
	scanf("%d",&n);
	create(n);
	while(1)
	{
		printf("\nEnter the number corresponding to required option [1-8]:");
		printf("\n1.\tDisplay the linked list");
		printf("\n2.\tSearch a node");
		printf("\n3.\tInsert new node after a node");
		printf("\n4.\tInsert at Start");
		printf("\n5.\tDelete by element");
		printf("\n6.\tDelete by position of node[0, 1, 2,...]");
		printf("\n7.\tModify a node");
		printf("\n8.\tExit");
		printf("\n");

		scanf("%d",&c);
		
		switch(c)
		{
			case 1: display(start);
				break;
			case 2: printf("\nEnter the element to search: ");
				scanf("%d", &ele);
				search(start, ele);
				break;
			case 3: printf("\nEnter element after which new element has to be inserted: ");
				scanf("%d", &ele);
				insert(start, ele);
				display(start);
				break;
			case 4: insert_start(start);
				display(start);
				break;
			case 5: printf("\nEnter the element to be deleted: ");
				scanf("%d", &ele);
				delete(start, ele);
				display(start);
				break;
			case 6: printf("\nEnter position of element to be deleted: ");
				scanf("%d", &ele);
				delete_pos(start, ele);
				display(start);
				break;
			case 7: printf("\nEnter the element to be modified: ");
				scanf("%d", &ele);
				modify(start, ele);
				display(start);
				break;				
			case 8: exit(0);
				break;
			default:printf("Invalid option....Re-enter a number [1-8]");
		}
		getchar();
	}
}


void create (int n)
{
	int i, x;
	node *p, *l;
	l = NULL;
	for(i=0;i<n;i++)
	{
		p = (node *)malloc(sizeof(node));
		printf("\nEnter element: ");
		scanf("%d", &x);
		p->info = x;
		p->next = NULL;
		if(start==NULL)
			start = p;
		else
			l->next = p;
		l = p;
	}
}

void display(node *st)
{
	node *p = st;
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p = p->next;
	}
}

void search(node *p, int e)
{
	while((p!=NULL)&&(p->info!=e))
		p = p->next;
	if(p==NULL)
		printf("\nElement not found");
	else
		printf("\nElement found");
}

void insert(node *p, int e)
{
	int x;
	node *n;
	while((p!=NULL)&&(p->info!=e))
		p = p->next;
	if(p==NULL)
		printf("\nElement not found");
	else
	{
		printf("\nEnter element to be inserted: ");
		scanf("%d", &x);
		n = (node *)malloc(sizeof(node));
		n->info = x;
		n->next = p->next;
		p->next = n;
	}
}

void insert_start(node *p)
{
	int x;
	node *n;
	printf("\nEnter element to be inserted: ");
	scanf("%d", &x);
	n = (node *)malloc(sizeof(node));
	n->info = x;
	n->next = start;
	start = n;
}

void delete(node *p, int e)
{
	node *q, *r;	
	while((p!=NULL)&&(p->info!=e))
	{
		q = p;
		p = p->next;
	}
	if(p==NULL)
		printf("\nElement not found\n");
	else
	{
		if(q==start)
			start = start->next;
		else
		{
			r= p->next;
			q->next=r;
		}
		p->next = NULL;
		free(p);
	}
}	

void delete_pos(node *p, int n)
{
	node *q, *r;
	int i=0;	
	while((p!=NULL)&&(i<n))
	{
		q = p;		
		p = p->next;
		i++;
	}
	if(i<n)
		printf("\nNot enough elements in ll\n");
	else
	{
		if(q==start)
			start = start->next;
		else
		{
			r= p->next;
			q->next=r;
		}
		p->next = NULL;
		free(p);
	}
}	

void modify(node *p, int e)
{
	int x;
	node *n;
	while((p!=NULL)&&(p->info!=e))
		p = p->next;
	if(p==NULL)
		printf("\nElement not found");
	else
	{
		printf("\nEnter new value: ");
		scanf("%d", &x);
		p->info = x;
	}
}

