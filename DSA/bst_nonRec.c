#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int *S[MAX];
int top=-1;
int empty()
{
        if(top==-1)
                return 1;
        else return 0;
}
int full()
{
        if(top==MAX-1)
                return 1;
        else
                return 0;
}

struct bst
{	int info;
	struct bst *left,*right;
};
int push(struct bst *);
int pop();
void display();
struct bst *insert(struct bst *,int);
void traverse(struct bst *);


main()
{
	int ch,val;
	struct bst *root=NULL;
	while(1)
	{
		printf("\n1.Insert\n2.Traverse\n5.Delete\nEnter Your Choice  : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nEnter Value  : ");
				scanf("%d",&val);
				root=insert(root,val);
				break;
			case 2:	traverse(root);
				break;
			default: exit(0);
		}
	}
}

struct bst *insert(struct bst *root,int val)
{
	struct bst *par=NULL,*newnode,*loc=root;
	while(loc!=NULL)
	{
		if(val==loc->info)
		{	printf("Duplicate Value\n");
		 	return root;
		}

		par=loc;
		if(val<loc->info)
			loc=loc->left;
		else
			loc=loc->right;
	
	}	
	newnode=(struct bst *)malloc(sizeof(struct bst));
	newnode->info=val;
	newnode->left=NULL;
	newnode->right=NULL;
	
	if(par==NULL)
		root=newnode;
	
	else if(val < par->info)
		par->left= newnode;
	
	else
		par->right= newnode;
	
	return root;
}

int push(int val)
{       if(full()==1)
                printf("\nStack Full !!\n");
        else
        {       top++;
                S[top]=val;
        }
        return 0;
}
int pop()
{
        int item;
        if(empty()==1)
        {
                printf("\nStack Empty !!\n");
                return -1000;
        }
        item=S[top];
        top--;
        return item;
}


void traverse(struct bst *root)
{
	struct bst *pn=root;
	while(pn!=NULL)
	{
		printf("\n%d\n",pn->info);
		if(pn->right!=NULL)
		{	top++;
			S[top]=pn->right;
		}
		if(pn->left != NULL)
			pn=pn->left;
		else
		{	pn=S[top];
			top--;
		}
	}
}


/*
void inorder(struct bst *root)
{
        struct bst *temp=root;
        if(temp!=NULL)
        {

                preorder(temp->left);
                printf("\n%d\n",temp->info);
                preorder(temp->right);
        }
}
struct bst *delete(struct bst *root,int val)
{
	struct bst *loc=root,*par=NULL;
	while(loc!=NULL && val!=loc->info)
	{
		par=loc;
		if(val < loc->info)
			loc=loc->left;
		else
			loc=loc->right;
	}
	if(loc==NULL)
	{
		printf("\nValue Not Found !! \n");
		return(root);
	}
	if(loc->left==NULL && loc->right==NULL)
		root=delA(root,loc,par);
	else if(loc->left!=NULL || loc->right!=NULL)
		root=delB(root,loc,par);
	else
		root=delC(root,loc,par);
	free(loc);
	return root;
}
struct bst *delA(struct bst *root,struct bst *loc,struct bst *par)
{
	struct bst *child=NULL;
	if(par!=NULL)
	{
		if(loc==par->left)
			par->left=child;
		else
			par->right=child;
	}
	else
		root=child;
	return root;
}
struct bst *delB(struct bst *root,struct bst *loc,struct bst *par)
{
	struct bst *child=NULL;
	if(loc->left != NULL)
		child = loc->left;
	else
		child = loc->right;
	if(par!=NULL)
	{
		if(loc==par->left)
			par->left=child;
		else
			par->right=child;
	}
	else
		root=child;
	return root;                       
}
struct bst *delC(struct bst *root,struct bst *loc, struct bst *par)
{
	struct bst *suc,*psuc;
	suc=loc->right;
	psuc = suc>left;
	suc->right = loc->right;

	return root;
*/
