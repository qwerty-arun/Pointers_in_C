#include <stdio.h>
#include <stdlib.h>

struct btreenode
{
	struct btreenode *left;
	int data;
	struct btreenode *right;
};

void insert(struct btreenode **sr,int num);
void inorder(struct btreenode *sr);
void preorder(struct btreenode *sr);
void postorder(struct btreenode *sr);
int main()
{
	struct btreenode *bt;
	int req,i=1,num;
	bt=NULL;
	printf("\nSpecify the number of data items to be inserted: \n");
	scanf("%d",&req);

	while(i++ <= req)
	{
		printf("\nEnter the data: ");
		scanf("%d",&num);
		insert(&bt,num);
	}

	printf("\nInorder Traversal: ");
	inorder(bt);

	printf("\nPreorder Traversal: ");
	preorder(bt);

	printf("\nPostorder Traversal: ");
	postorder(bt);
}

void insert(struct btreenode **sr, int num)
{
	if(*sr==NULL)
	{
		*sr=malloc(sizeof(struct btreenode));
		(*sr)->left=NULL;
		(*sr)->data=num;
		(*sr)->right=NULL;
		return;
	}
	else{
		if(num < (*sr)->data)
			insert(&((*sr)->left),num);
		else
			insert(&((*sr)->right),num);
	}
	return;
}

void inorder(struct btreenode *sr)
{
	if(sr!=NULL)
	{
		inorder(sr->left);
		printf("%d ",sr->data);
		inorder(sr->right);
	}
	else
		return;
}
void preorder(struct btreenode *sr)
{
	if(sr!=NULL)
	{
		printf("%d ",sr->data);
		preorder(sr->left);
		preorder(sr->right);
	}
	else
		return;
}
void postorder(struct btreenode *sr)
{
	if(sr!=NULL)
	{
		postorder(sr->left);
		postorder(sr->right);
		printf("%d ",sr->data);
	}
	else
		return;
}
