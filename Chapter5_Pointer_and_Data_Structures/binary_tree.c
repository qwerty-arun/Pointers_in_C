#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void delete(struct btreenode**,int num);
void search(struct btreenode**root,int num,struct btreenode **par,struct btreenode**x,int *found);

int main()
{
	struct btreenode *bt;
	int req,i=0,num,a[]={11,9,13,8,10,12,14,15,7};
	bt=NULL;
	// printf("\nSpecify the number of data items to be inserted: \n");
	// scanf("%d",&req);

	while(i<= 8)
	{
		insert(&bt,a[i]);
		i++;
	}
	printf("\nBinary Tree before deletion: ");
	inorder(bt);

	delete(&bt,10);
	printf("\nBinary Tree after deletion: ");
	inorder(bt);

	delete(&bt,14);
	printf("\nBinary Tree after deletion: ");
	inorder(bt);

	delete(&bt,8);
	printf("\nBinary Tree after deletion: ");
	inorder(bt);

	delete(&bt,13);
	printf("\nBinary Tree after deletion: ");
	inorder(bt);
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

void delete(struct btreenode** root, int num)
{
	int found;
	struct btreenode *parent,*x,*xsucc;
	if(*root==NULL)
	{
		printf("\nTree is empty!");
		return;
	}
	parent=x=NULL;

	search(root,num,&parent,&x,&found);
	// void search(struct btreenode**root,int num,struct btreenode **par,struct btreenode**x,int *found)
	//returns the address of the node to be deleted, address of its parent and whether the node is found or not
	if(found==0)
	{
		printf("\nData to be deleted, not found!");
		return;
	}

	//x is the node to be deleted, par is its parent, xsucc is x's successor in the inorder traversal
	//if the node to be deleted has two children
	if(x->left!=NULL && x->right!=NULL)
	{
		parent=x;//x itself is the parent
		xsucc=x->right;//its right child is the successor

		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		x->data=xsucc->data;
		x=xsucc;
	}
	
	//if the node to be deleted has no child
	if(x->left==NULL && x->right==NULL)
	{
		//x has no child, so it will be either left child or right child to its parent
		if(parent->right==x)
			parent->right=NULL;
		else
			parent->left=NULL;
		free(x);
		return;
	}

	//if the node to be deleted has only right child
	if(x->left==NULL && x->right!=NULL)
	{
		if(parent->left==x)
			parent->left=x->right;
		else
			parent->right=x->right;
		free(x);
		return;
	}

	//if the node to be deleted has only left child
	if(x->left!=NULL && x->right==NULL)
	{
		if(parent->left==x)
			parent->left=x->left;
		else
			parent->right=x->left;
		free(x);
		return;
	}
}

//returns the address of the node to be deleted, address of its parent and whether the node is found or not
void search(struct btreenode**root,int num,struct btreenode **par,struct btreenode**x,int *found)
{
	struct btreenode *q;
	q=*root;
	*found=0;
	*par=NULL;
	while(q!=NULL)
	{
		if(q->data==num)
		{
			*found=1;
			*x=q;
			return;
		}
		if(q->data>num)
		{
			*par=q;
			q=q->left;
		}
		else
		{
			*par=q;
			q=q->right;
		}
	}
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
