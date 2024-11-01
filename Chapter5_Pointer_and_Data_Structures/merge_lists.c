#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void add(struct node **q,int num);
void display(struct node *q);
void merge(struct node *p,struct node *q,struct node **s);
int count(struct node *q);

int main()
{
	struct node *first,*second,*third;
	first=second=third=NULL;
	add(&first,1);
	add(&first,2);
	add(&first,3);
	add(&first,4);
	add(&first,5);
	add(&first,6);
	add(&first,7);

	printf("\nThe First Linked List: ");
	display(first);
	printf("\nThe No. of elements in the linked list: %d",count(first));

	add(&second,1);
	add(&second,2);
	add(&second,3);
	add(&second,4);
	add(&second,5);
	add(&second,6);
	add(&second,7);

	printf("\nThe Second Linked List: ");
	display(second);
	printf("\nThe No. of elements in the linked list: %d",count(second));

	merge(first,second,&third);
	printf("\nThe Concatenated List:");
	display(third);
	printf("\nThe no. of elements in the linked list: %d",count(third));
	return 0;
}

void add(struct node **q,int num)
{
	struct node *r,*temp=*q;
	r=malloc(sizeof(struct node));
	r->data=num;

	if(*q==NULL)
	{
		*q=r;
		(*q)->link=temp;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data<num && (temp->link->data>num || temp->link==NULL))
			{
				r->link=temp->link;
				temp->link=r;
				return;
			}
			temp=temp->link;
		}
		r->link=NULL;
		temp->link=r;
	}
}

void display(struct node *q)
{
	printf("\n");
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->link;
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

//merge two linked lists, restricting the common elements to occur only once in the final list

void merge(struct node *p,struct node *q,struct node **s)
{
	struct node *z;
	z=NULL;

	if(p==NULL && q==NULL)
		return;

	while(p!=NULL && q!=NULL)
	{
		if(*s==NULL)
		{
			*s=malloc(sizeof(struct node));
			z=*s;
		}
		else
		{
			z->link=malloc(sizeof(struct node));
			z=z->link;
		}

		if(p->data < q->data)
		{
			z->data = p->data;
			p=p->link;
		}
		else
		{
			if(q->data < p->data)
			{
				z->data=q->data;
				p=p->link;
			}
			else
			{
				if(p->data == q->data)
				{
					z->data=q->data;
					p=p->link;
					q=q->link;
				}
			}
		}
	}
	while(p!=NULL)
	{
		z->link=malloc(sizeof(struct node));
		z=z->link;
		z->data=p->data;
		p=p->link;
	}
	while(q!=NULL)
	{
		z->link=malloc(sizeof(struct node));
		z=z->link;
		z->data=q->data;
		q=q->link;
	}
	z->link=NULL;
}
