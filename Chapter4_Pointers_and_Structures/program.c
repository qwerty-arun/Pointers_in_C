#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
	int data;
	struct node *link;
};

void delete(struct node **q,int num);
int count (struct node *q);
void display(struct node *q);
void addafter(struct node *q, int loc, int num);
void addatbeg(struct node **q,int num);
void append(struct node **q, int num);

int main()
{
	struct node *p=NULL;
	printf("\nThe number of elements in the list: %d",count(p));
	append(&p,1);
	append(&p,2);
	append(&p,3);
	printf("\nThe number of elements in the list: %d",count(p));
	display(p);
	addatbeg(&p,0);
	addatbeg(&p,-1);
	printf("\nThe number of elements in the list: %d",count(p));
	display(p);

	delete(&p,2);
	printf("\nThe number of elements in the list: %d",count(p));
	display(p);

	addafter(p,3,2);
	printf("\nThe number of elements in the list: %d",count(p));
	display(p);

	delete(&p,-1);
	printf("\nThe number of elements in the list: %d",count(p));
	display(p);
	free(p);
}


void delete(struct node **q,int num)
{
struct node *old, *temp;
	temp=*q;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp==*q)
			{
				*q=temp->link;
				free(temp);
				return;
			}
			else
			{
				old->link=temp->link;
				free(temp);
				return;
			}
		}
		else
		{
			old=temp;
			temp=temp->link;
		}
	}
	printf("\nElement %d not found",num);
}

int count (struct node *q)
{
	int c=0;
	while(q!=NULL)
	{
		q=q->link;
		c++;
	}
	return c;
}

void display(struct node *q)
{
	printf("The elements present in the list are: \n");
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->link;
	}
}

void addafter(struct node *q, int loc, int num)
{
	int i;
	struct node *temp=q;
	for(i=0;i<loc;i++)
	{
		temp=temp->link;
		if(temp==NULL)
		{
			printf("\nThere are less than %d elements in list",loc);
			return;
		}
	}
	struct node *p=(struct node*)malloc(sizeof(struct node));
	p->data=num;
	p->link=temp->link;
	temp->link=p;
}
void addatbeg(struct node **q,int num)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->link=*q;
	*q=temp;
}
void append(struct node **q, int num)
{
	struct node *temp=*q,*p;
	if(*q==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->link=NULL;
		*q=temp;
	}
	else
	{
		temp=*q;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	p=(struct node*)malloc(sizeof(struct node));
	p->data=num;
	p->link=NULL;
	temp->link=p;
	}
}
