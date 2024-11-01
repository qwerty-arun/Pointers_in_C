# Prgm-4 : Sorting Linked List
```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void append(struct Node** head, int data);
void display(struct Node* head);
void selectionSort(struct Node* head);
void bubbleSort(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data;

    // Sample input for the linked list
    append(&head, 5);
    append(&head, 2);
    append(&head, 9);
    append(&head, 1);
    append(&head, 7);

    printf("Original list:\n");
    display(head);

    // Prompt user to choose sorting method
    printf("\nChoose sorting technique:\n1. Selection Sort\n2. Bubble Sort\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        selectionSort(head);
        printf("\nList after Selection Sort:\n");
    } else if (choice == 2) {
        bubbleSort(head);
        printf("\nList after Bubble Sort:\n");
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    display(head);

    return 0;
}

// Function to append a new node to the end of the list
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Selection Sort on a linked list
void selectionSort(struct Node* head) {
    struct Node *temp1 = head, *temp2, *minNode;

    while (temp1 != NULL && temp1->next != NULL) {
        minNode = temp1;
        temp2 = temp1->next;

        // Find the minimum node in the remaining list
        while (temp2 != NULL) {
            if (temp2->data < minNode->data) {
                minNode = temp2;
            }
            temp2 = temp2->next;
        }

        // Swap the data if a smaller element is found
        if (minNode != temp1) {
            int temp = temp1->data;
            temp1->data = minNode->data;
            minNode->data = temp;
        }

        temp1 = temp1->next;
    }
}

// Bubble Sort on a linked list
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    // Check for empty list
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
```
## Output of Prgm-4
```
Original list:
5 -> 2 -> 9 -> 1 -> 7 -> NULL

Choose sorting technique:
1. Selection Sort
2. Bubble Sort
Enter choice: 1

List after Selection Sort:
1 -> 2 -> 5 -> 7 -> 9 -> NULL
>> vi trial.c 

>> ./a.out 
Original list:
5 -> 2 -> 9 -> 1 -> 7 -> NULL

Choose sorting technique:
1. Selection Sort
2. Bubble Sort
Enter choice: 2

List after Bubble Sort:
1 -> 2 -> 5 -> 7 -> 9 -> NULL
```
## Ways to sort a linked list: 1) Exchange only the data part of the two nodes, keeping the links as it is. 2) Keep the data intact and simply readjust the links such that effectively the order of the nodes changes.
## Well of the two methods, first one is very easy to implement, but the second one is likely to be more efficient.
# Prgm-3 : Mutiply two polynomials and simplify
```
#include <stdio.h>
#include <stdlib.h>

struct polynode {
    float coeff;
    int exp;
    struct polynode *link;
};

void poly_append(struct polynode **, float, int);
void poly_multiply(struct polynode *, struct polynode *, struct polynode **);
void padd(float, int, struct polynode **);
void display_poly(struct polynode *);
void simplify_poly(struct polynode **);

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
    simplify_poly(&mult);
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
    printf("\n");
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

// Function to simplify the polynomial by combining like terms
void simplify_poly(struct polynode **poly) {
    struct polynode *p1, *p2, *prev;

    p1 = *poly;
    while (p1 != NULL && p1->link != NULL) {
        prev = p1;
        p2 = p1->link;
        while (p2 != NULL) {
            if (p1->exp == p2->exp) {
                p1->coeff += p2->coeff;  // Add coefficients
                prev->link = p2->link;   // Remove duplicate node
                free(p2);                // Free memory of duplicate node
                p2 = prev->link;         // Move to the next node
            } else {
                prev = p2;
                p2 = p2->link;
            }
        }
        p1 = p1->link;
    }
}
```
## Output of Prgm-1
```
3.0x^5 + 2.0x^4 + 1.0x^2


1.0x^6 + 2.0x^5 + 3.0x^4

-----------------------------------------------------------

3.0x^11 + 8.0x^10 + 13.0x^9 + 7.0x^8 + 2.0x^7 + 3.0x^6
```
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
