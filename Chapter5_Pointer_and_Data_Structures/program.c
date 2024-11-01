#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
	int data;
	struct node *link;
}*newnode,*start,*visit;

void getdata();
void append(struct node **q,int num);
void displaylist(struct node *);
void selection_sort(int n);
void bubble_sort(int n);
int count(struct node *q);

int main()
{
	int n;
	start=NULL;
	append(&start,1);
	append(&start,8);
	append(&start,5);
	append(&start,0);
	// getdata();
	printf("\nLinked List Before Sorting: ");
	displaylist(start);

	n=count(start);

	bubble_sort(n);
	printf("\nLinked List After Selection Sorting: ");
	displaylist(start);

	// getdata();
	append(&start,3);
	append(&start,7);
	append(&start,2);
	append(&start,1);

	printf("\nLinked List Before Sorting: ");
	displaylist(start);
	n=count(start);
	bubble_sort(n);
	printf("\nLinked List After Bubble Sorting: ");
	displaylist(start);
}

void getdata()
{
	int val,n;
	char ch;
	struct node *new;

	new=NULL;
	do{
		printf("\nEnter a value: ");
		scanf("%d",&val);
		append(&new,val);
		printf("\nAny More Nodes (Y/N): ");
		scanf("%c",&ch);
	}while(ch=='y' || ch=='Y');
	start=new;
}

void append(struct node **q,int num)
{
	struct node *temp;
	temp=*q;
	if(*q==NULL)
	{
		*q=malloc(sizeof(struct node));
		temp=*q;
	}
	else
	{
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=malloc(sizeof(struct node));
		temp=temp->link;
	}
	temp->data=num;
	temp->link=NULL;
}

void displaylist(struct node* q)
{
	visit = q;
	while(visit!=NULL)
	{
		printf("%d ",visit->data);
		visit=visit->link;
	}
}

int count(struct node *q)
{
	int c=0;
	while(q!=NULL)
	{
		q=q->link;
		c++;
	}
	return c;
}

void selection_sort(int n)
{
	int i,j,k,temp;
	struct node *p,*q;

	p=start;
	for(i=0;i<n-1;i++)
	{
		q=p->link;
		for(j=i+1;j<n;j++)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->link;
		}
		p=p->link;
	}
}

void bubble_sort(int n)
{
	int i,j,k,temp;
	struct node *p,*q;

	k=n;
	for(i=0;i<n-1;i++,k--)
	{
		p=start;
		q=p->link;
		for(j=i;j<k;j++)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->link;
			p=p->link;
		}
	}
}
