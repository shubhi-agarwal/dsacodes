#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
int info;
struct tree *left;
struct tree *right;
}node ;
node *root = NULL;
int ele;

node* newnode(int x)
{
	node* newa=(node*)malloc(sizeof(node*));
	newa->info=x;
	newa->left=NULL;
	newa->right=NULL;
	return newa;
}

 node* insert( node* root,int ele)
{
	
	if(root==NULL)
		root=newnode(ele);
	else if(ele <= root->info)
	{
		
		root->left=insert(root->left,ele);
	}
	else 
		root->right=insert(root->right,ele);
	return (root);
}

void search (int ele)
{
	node* p= root;
	//if (root==NULL)
	//printf ("tree is empty");
	
	while ((p!= NULL) && (p-> info !=ele))
	{
	if (p-> info >ele)
		p=p->left;
	else
		p=p->right;
	}
	if (p-> info ==ele)
		printf ("element found\n");
	else
		{printf ("element not found\n");
		}
}

void preorder (node *p)
{
	if (p!=NULL)
	{
		printf ("%d ", p->info);
		preorder (p->left);
		preorder (p-> right);
	}
}

void inorder (node *p)
{
	if (p!=NULL)
	{
		inorder (p-> left);
		printf ("%d ", p->info);
		inorder (p-> right);
	}
}

void postorder (node *p)
{
	if (p!=NULL)
	{
		postorder (p-> left);
		postorder (p-> right);
		printf ("%d ", p->info);
	}
}


main()
{ 	int n;
	
    int choice,ele;
    while (1)
    {
        printf("\n1.insert an element\n");
        printf("2.search an element \n");
        printf("3.preorder \n");
        printf("4.inorder \n");
        printf("5. postorder\n");
        printf("6.exit\n");
        printf("7.delete\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
	case 1: printf ("enter element to insert: ");
            	scanf ( "%d", &ele);
            	root=insert (root, ele);
            	break;
        case 2: printf ("enter element to search: ");
        	scanf ( "%d", &ele);
            	search (ele);
                break;
        case 3: printf("\nPreorder traversal of binary tree is \n");
     		preorder(root);
 		break;
        case 4: printf("\nInorder traversal of binary tree is \n");
     		inorder(root);  
 		break;
     	case 5: printf("\nPostorder traversal of binary tree is \n");
     		postorder(root);
       		break;
       	case 6: exit (1);
       	case 7: printf( "\n Enter the element to delete\n");
       		scanf (" %d", &ele);
       		//search (ele);
       		todelete (ele);
       		printf (" element has been successfully deleted\n");
       		
	}
    }
}

void todelete (int ele)
{
	node *p, *q, *r, *s;
	r=s=NULL;
	p=root;
	q=root;
	while ((p-> info!=ele) && (p!= NULL))
	{
		q=p;
		if (p->info>ele)
			p=p->left;
		else
			p=p->right;
	}


	if ((p->left== NULL) && (p-> right== NULL)) // IT IS LEAF NODE
        //make parent left or right null
	{
		if (q-> info > ele)
			q-> left = NULL;
		else
			q-> right =NULL;
	}

     	// IF NODE HAS ONE CHILD 
	// IF NODE HAS RIGHT CHILD
	if (( p-> left == NULL) && ( p-> right != NULL))
	{
		if (q-> info> ele) // p is left child of q
			q-> left = p-> right;
		else
			q-> right = p-> right;
	}

	if ((p-> left !=NULL) && (p-> right== NULL))
	{
		if (q-> info> ele)
			q-> left = p-> left;
		else
			q-> right= p-> left;
	}
 	// node to be deleted has two child
	if ((p-> left!=NULL) && (p-> right!= NULL))
	{
	// IMMEDIATE PREDECESSOR ( left-> rightmost)
		r=p-> left;
		while (r-> right!= NULL)
		{
			s=r;
			r=r-> right;
		}
		p-> info= r-> info;
		if (s== NULL)
			p-> left= r-> left;
		else
		s-> right= r-> left;
	}
	 
}	










































