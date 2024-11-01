# include <stdio.h>
# include <stdlib.h>
#include <string.h>

struct polynode
{
	float coeff;
	int exp;
	struct polynode *link;
};

void poly_append(struct polynode **,float, int);
void poly_addition(struct polynode *,struct polynode*,struct polynode **);
void display_poly(struct polynode *);
int count(struct polynode *);

int main()
{
	struct polynode *first,*second,*total;
	first =second = total=NULL;
	poly_append(&first, 1.4,5);
	poly_append(&first, 1.5,4);
	poly_append(&first, 1.7,2);
	poly_append(&first, 1.8,1);
	poly_append(&first, 1.9,0);

	display_poly(first);

	poly_append(&second, 1.5,6);
	poly_append(&second, 2.5,5);
	poly_append(&second, -3.5,4);
	poly_append(&second, 4.5,3);
	poly_append(&second, 6.6,1);

	printf("\n\n");
	display_poly(second);

	int i=0;
	printf("\n");
	while(i++<60)
		printf("-");
	printf("\n\n");

	poly_addition(first, second, &total);
	display_poly(total);
}

void poly_append(struct polynode **q,float x,int y)
{
	struct polynode *temp;
	temp=*q;

	if(*q==NULL)
	{
		*q=malloc(sizeof(struct polynode));
		temp=*q;
	}
	else
	{
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=malloc(sizeof(struct polynode));
		temp=temp->link;
	}
	temp->coeff=x;
	temp->exp=y;
	temp->link=NULL;
}

void display_poly(struct polynode *q)
{
	while(q!=NULL)
	{
		printf("%.1fx^%d + ",q->coeff,q->exp);
		q=q->link;
		if(q->link==NULL)
		{
		printf("%.1fx^%d",q->coeff,q->exp);
			return;
		}
	}
}

void poly_addition(struct polynode *x,struct polynode *y, struct polynode **s)
{
	struct polynode *z;
	if(x==NULL && y==NULL)
		return;

	while(x!=NULL && y!=NULL)
	{
		if(*s==NULL)
		{
			*s=malloc(sizeof(struct polynode));
			z=*s;
		}
		else
		{
			z->link=malloc(sizeof(struct polynode));
			z=z->link;
		}

		if(x->exp < y->exp)
		{
			z->coeff=y->coeff;
			z->exp=y->exp;
			y=y->link;
		}
		else
		{
			if(x->exp > y->exp)
			{
				z->coeff = x->coeff;
				z->exp = x->exp;
				x=x->link;
			}
			else
			{
				if(x->exp == y->exp)
				{
					z->coeff = x->coeff + y->coeff;
					z->exp=x->exp;
					x=x->link;
					y=y->link;
				}
			}
		}
	}
	// While loop exits when one of the linked list if fully traversed.
	// Assign remaining terms of the first polynomial to the result
	while(x!=NULL)
	{
		if(*s==NULL)
		{
			*s=malloc(sizeof(struct polynode));
			z=*s;
		}
		else
		{
			z->link=malloc(sizeof(struct polynode));
			z=z->link;
		}
		z->coeff=x->coeff;
		z->exp=x->exp;
		x=x->link;
	}
	// Assign remaining terms of the second polynomial to the result
	while(y!=NULL)
	{
		if(*s==NULL)
		{
			*s=malloc(sizeof(struct polynode));
			z=*s;
		}
		else
	{
			z->link=malloc(sizeof(struct polynode));
			z=z->link;
		}
		z->coeff=y->coeff;
		z->exp=y->exp;
		y=y->link;
	}
	z->link=NULL;
}
