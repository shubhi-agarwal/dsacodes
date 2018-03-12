#include<stdio.h>
#include<stdlib.h>
int isempty();
void enqueue(int,int);
int dequeue(int);
void display();



struct node
{
int data;
struct node *next;
};
struct node *front;
struct node *rear;

int main()
{
	int choice,x,t,s;
	do
	{
		printf("1.enter a element in queue\n");
		printf("2.remove an element from queue\n");
		printf("3.display the array\n");
		printf("4.exit\n");
		printf("enter a choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :printf("enter x");
				scanf("%d",&x);
				t=isempty();
				enqueue(x,t);
				break;
			case 2 :t=isempty();
				s=dequeue(t);
				printf("%d\n",s);
				break;
			case 3 :display();
				break;
			case 4 :break;
		}
	}
	while(choice!=4);
	return 0;
}



int isempty()
{
	if(front==NULL && rear==NULL)
	return 1;
	else
	return 0;
}

void enqueue(int x,int t)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	temp->data=x;
	temp->next=NULL;
	if(t==1)
	{
		front=rear=temp;
		
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}

int dequeue(int t)
{
	int x;
	struct node *p;
	p=front;
	if(t==1)
	printf("stack underflow");
	if(front->next==NULL && rear->next==NULL)
	{
		x=front->data;
		front=NULL;
		rear=NULL;
	}
	else
	{
		x=front->data;
		front=front->next;
	}
	free(p);
	return x;
}
void display()
{
	struct node *p;
	p=front;
	printf("\nList is...\n");
	while(front->next!=NULL)

	{
		printf("%d\n",front->data);
		front=front->next;
	}
		printf("%d\n",front->data);
		front=p;	
}




