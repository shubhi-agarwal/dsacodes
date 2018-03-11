#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int info;
struct node* next;
struct node* prev;
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
			case 6:  printf("\nEnter position of element to be deleted: ");
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
		{
			start = p;
			p-> prev=NULL;
		}
		else
		{
			l->next = p;
			p->prev=l;
			}
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
		printf("\nElement not found\n");
	else
		printf("\nElement found\n");
}

void insert(node *p, int e)
{
	int x;
	node *n, *r;
	while((p!=NULL)&&(p->info!=e))
		p = p->next;
	if(p==NULL)
		printf("\nElement not found\n");
	else
	{
		printf("\nEnter element to be inserted:\n ");
		scanf("%d", &x);
		n = (node *)malloc(sizeof(node));
		n->info = x;
		r = p->next;
		p->next = n;
		n->prev=p;
		n->next=r;
		if (r!=NULL)
			r->prev=n;
	}
}

void insert_start(node *p)
{
	int x;
	node *n;
	printf("\nEnter element to be inserted:\n ");
	scanf("%d", &x);
	n = (node *)malloc(sizeof(node));
	n->info = x;
	n->prev= NULL;
	n->next = start;
	start->prev=n;
	start = n;
}





void modify(node *p, int e)
{
	int x;
	node *n;
	while((p!=NULL)&&(p->info!=e))
		p = p->next;
	if(p==NULL)
		printf("\nElement not found\n");
	else
	{
		printf("\nEnter new value: ");
		scanf("%d", &x);
		p->info = x;
	}
}
void delete(node *p, int e)
{	node *q, *r, *n;	
	while((p!=NULL)&&(p->info!=e))
	{
		q = p;
		p = p->next;
	}
	n=p->next;
	if(p==NULL)
		printf("\nElement not found\n");
	
	else
	{ 
		if (p==start)
		{
			p->prev=NULL;
			start=start->next;
		
		p->prev=NULL;
		p->next=NULL;
		free(p);
		}
		else
		{
			q=p->prev;
			q->next=n;
			if (n!=NULL)
			n->prev=q;
		}
	}
}
void delete_pos(node *p, int n)
{
	node *q, *r, *s;
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
	{	if (p==start)
		{
			p->prev=NULL;
			start=start->next;
		
		p->prev=NULL;
		p->next=NULL;
		free(p);}
		else
		{
			q=p->prev;
			q->next = s;
			if (s !=NULL)
			s->prev=q;
		}
		
	}
}	
