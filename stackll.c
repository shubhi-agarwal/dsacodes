#include <stdio.h>
#include <stdlib.h>

struct node 
{
int info;
struct node *next;
}*top, *temp;
//int count=0;
void push(int data);
void pop();
void display();
void create();
int topelement();
void destroy();

void main()
{
	int no, ch, e,n;
	printf ("1- PUSH\n");
	printf ("2- POP \n");
	printf ("3- display \n");
	printf ("4- top element \n");
	printf ("5- destroy entire stack \n");
	printf ("6- exit\n");
	
	
	while(1)
	{	
		printf (" \nEnter choice:");
		scanf ("%d", &ch);
		switch (ch)
		{
			case 1: printf (" enter data \n");
				scanf ("%d", &no);
				push (no);
				break;
			case 2: pop();
				break;
			case 3: display ();
				break;
			case 4: if (top == NULL)
				printf (" no elements in stack\n");
				else
				{
					e= topelement();
					printf (" top element = %d", e);
				}
				break;
			case 5: destroy();
				break;
			
			case 6: exit (0);
				
			default : printf ("wrong choice\n");
				break;
		}
	}
}
	void push (int data)
	{ if (top==NULL)
		{	top= (struct node *) malloc (sizeof (struct node));
			top->next =NULL;
			top->info = data;
		}
	else
		{
			temp= (struct node *) malloc (sizeof (struct node));
			temp->next= top;
			temp->info=data;
			top= temp;
		}
	//count++;
	}
	
	void pop ()
	{	//struct node *n;
		struct node *top1;
		top1=top;
		if (top1==NULL)
			printf(" underflow- trying to pop from an empty stack");
		else
		{	
			top1= top1-> next;
			printf (" popped value is %d", top->info);
			free (top);
			top= top1;
			
		}
	//count-- ;
	}
	
	void display()
	{
		struct node *top1;
		top1=top;
		
		if (top1==NULL)
		{	printf(" stack is empty");
			
		}
		while (top1!= NULL)
		{
			printf ("%d ", top1->info);
			top1=top1->next;
		}
	}
	
	int topelement ()
	{
		return (top-> info);
	}
	
	void destroy ()
	{ 
		struct node * top1;
		top1= top;
		while (top1!= NULL);
		{
			top1= top->next;
			free (top);
			top= top1;
			top1= top1->next;
		}
		free (top1);
		top= NULL;
		printf (" all elements are destroyed\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
