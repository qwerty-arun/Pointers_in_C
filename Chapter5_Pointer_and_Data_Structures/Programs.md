# Prgm-2 : Multiplying two polynomials
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct polynode {
    float coeff;
    int exp;
    struct polynode *link;
};

void poly_append(struct polynode **, float, int);
void poly_multiply(struct polynode *, struct polynode *, struct polynode **);
void padd(float, int, struct polynode **);
void display_poly(struct polynode *);

int main() {
    struct polynode *first, *second, *mult;
    first = second = mult = NULL;
    int i = 1;

    poly_append(&first, 3, 5);
    poly_append(&first, 2, 4);
    poly_append(&first, 1, 2);

    display_poly(first);

    poly_append(&second, 1, 6);
    poly_append(&second, 2, 5);
    poly_append(&second, 3, 4);

    printf("\n\n");
    display_poly(second);

    printf("\n");
    while (i++ < 60)
        printf("-");
    printf("\n\n");

    poly_multiply(first, second, &mult);
    display_poly(mult);
    return 0;
}

void poly_append(struct polynode **q, float x, int y) {
    struct polynode *temp;
    temp = *q;

    if (*q == NULL) {
        *q = malloc(sizeof(struct polynode));
        temp = *q;
    } else {
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = malloc(sizeof(struct polynode));
        temp = temp->link;
    }
    temp->coeff = x;
    temp->exp = y;
    temp->link = NULL;
}

void display_poly(struct polynode *q) {
    while (q != NULL) {
        printf("%.1fx^%d", q->coeff, q->exp);
        q = q->link;
        if (q != NULL)
            printf(" + ");
    }
}

void poly_multiply(struct polynode *x, struct polynode *y, struct polynode **m) {
    struct polynode *y1;
    float coeff1;
    int exp1;
    y1 = y;

    if (x == NULL || y == NULL)
        return;

    while (x != NULL) {
        y = y1;  // Reset y to the start of the second polynomial
        while (y != NULL) {
            coeff1 = x->coeff * y->coeff;
            exp1 = x->exp + y->exp;
            padd(coeff1, exp1, m);
            y = y->link;
        }
        x = x->link;
    }
}

void padd(float c, int e, struct polynode **s) {
    struct polynode *r, *temp = *s;
    if (*s == NULL || e > (*s)->exp) {
        r = malloc(sizeof(struct polynode));
        r->coeff = c;
        r->exp = e;
        r->link = *s;
        *s = r;
    } else {
        while (temp->link != NULL && temp->link->exp > e)
            temp = temp->link;

        if (temp->exp == e) {
            temp->coeff += c;
        } else {
            r = malloc(sizeof(struct polynode));
            r->coeff = c;
            r->exp = e;
            r->link = temp->link;
            temp->link = r;
        }
    }
}
```
## Output of Prgm-2
```
3.0x^5 + 2.0x^4 + 1.0x^2

1.0x^6 + 2.0x^5 + 3.0x^4
-----------------------------------------------------------

3.0x^11 + 2.0x^10 + 6.0x^10 + 4.0x^9 + 9.0x^9 + 1.0x^8 + 6.0x^8 + 2.0x^7 + 3.0x^
```
## Remarks on Prgm-2: Although the multiplication is carried out successfully, there are terms which have the same exponent, which means that the expression is not simplified. We need to write another function which simplifies the expression.
# Prgm-1 : Adding two polynomials
```
// Add two polynomials 
#include <bits/types/siginfo_t.h>
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
```
## Output of Prgm-1
```
1.4x^5 + 1.5x^4 + 1.7x^2 + 1.8x^1 + 1.9x^0

1.5x^6 + 2.5x^5 + -3.5x^4 + 4.5x^3 + 6.6x^1
------------------------------------------------------------

1.5x^6 + 3.9x^5 + -2.0x^4 + 4.5x^3 + 1.7x^2 + 8.4x^1 + 1.9x^0
```
# No pointers, No Data Structures.
