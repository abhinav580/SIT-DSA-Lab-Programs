#include<stdio.h>
#include<stdlib.h>
struct bst
{	int info;
	struct bst *left,*right;
};

struct bst *insert(struct bst *,int);
struct bst *delete(struct bst *,int);
struct bst *delA(struct bst *,struct bst *,struct bst *);
struct bst *delB(struct bst *,struct bst *,struct bst *);
struct bst *delC(struct bst *,struct bst *,struct bst *);
void preorder(struct bst *);
void postorder(struct bst *);
void inorder(struct bst *);
main()
{
	int ch,val;
	struct bst *root=NULL;
	while(1)
	{
		printf("\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.Delete\nEnter Your Choice  : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("\nEnter Value  : ");
				scanf("%d",&val);
				root=insert(root,val);
				break;
			case 2:	preorder(root);
				break;
			case 3:	postorder(root);
				break;
			case 4:	inorder(root);
				break;
			case 5:	printf("\nEnter Value To Be Deleted : ");
				scanf("%d",&val);
				root = delete(root,val);
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
		if(val < loc->info)
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
	
void preorder(struct bst *root)
{
	struct bst *temp=root;
	if(temp!=NULL)
	{

		printf("\n%d\n",temp->info);
		preorder(temp->left);
		preorder(temp->right);
	}
}	
void postorder(struct bst *root)
{
        struct bst *temp=root;
        if(temp!=NULL)
        {

                postorder(temp->left);
                postorder(temp->right);
                printf("\n%d\n",temp->info);
        }
}

void inorder(struct bst *root)
{
        struct bst *temp=root;
        if(temp!=NULL)
        {

                inorder(temp->left);
                printf("\n%d\n",temp->info);
                inorder(temp->right);
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
//	psuc = suc;
	while(suc->left!=NULL)
	{
		psuc = suc;	
		suc = suc->left;
	}
		
	if(suc->left == NULL && suc->right == NULL)
		root=delA(root,suc,psuc);
	else
		root=delB(root,suc,psuc);

	if(par!=NULL)
	{	if(loc==par->left)
			par->left=suc;
		else
			par->right=suc;
	}
	else
		root=suc;

	suc->left = loc->left;
	suc->right = loc->right;

	return root;
}
	

