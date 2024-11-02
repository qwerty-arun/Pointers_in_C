# Prgm-7: Binary Tree
```
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
```
## Output of Prgm-7
```
Inorder Traversal: 0 1 5 8 9 
Preorder Traversal: 8 1 0 5 9 
Postorder Traversal: 0 5 1 9 8 
```
# Trees are non linear data structures.
# Binary trees are those whose nodes have at most two children.
# Strictly Binary tree: Every non-leaf node has non-empty left and right subtrees.
# The root of the tree has level 0. Level of any other node in the tree is one more than the level of its father.
# The depth of a binary tree is the maximum level of any leaf in the tree. This equals the length of the longest path from the root to any leaf.
# A complete bianry tree of depth d is a strictly binary tree all of whose leaves are at level d.
# There are three popular methods of traversal: Inorder, preorder and postorder. Traversal means visiting each node in the tree exactly once.
# preorder: visit the root, traverse the left subtree in preorder, traverse the right subtree in preorder.
# inorder:  traverse the left subtree in preorder, visit the root, traverse the right subtree in preorder.
# preorder: traverse the left subtree in preorder, traverse the right subtree in preorder, visit the root.
# A binary tree that has elements of a left subtree of a node 'n' that are less than the contents of 'n' and all the elements int eh right subtree of 'n' are greater than or equal to the contents of 'n': Binary Search Tree.
# If a binary search tree is traversed in inorder and elements are printed, they will be in ascending order.
# Prgm-6 : Circular Queue
```
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};
void addcirq(struct node **, struct node **, int);
void delcirq(struct node **, struct node **);
void cirq_display(struct node *);
int main()
{
	struct node *front, *rear;
	front=rear=NULL;

	addcirq(&front,&rear,10);
	addcirq(&front,&rear,11);
	addcirq(&front,&rear,12);
	addcirq(&front,&rear,13);
	addcirq(&front,&rear,14);
	addcirq(&front,&rear,15);

	printf("\nThe circular linked list: \n");
	cirq_display(front);

	delcirq(&front,&rear);
	delcirq(&front,&rear);
	delcirq(&front,&rear);

	printf("\nAfter Deletion: \n");
	cirq_display(front);
}

void addcirq(struct node **f, struct node **r, int item)
{
	struct node *q;
	q=malloc(sizeof(struct node));
	q->data=item;
	if(*f==NULL)
		*f=q;
	else
		(*r)->link=q;
	*r=q;
	(*r)->link=*f;
}

void delcirq(struct node **f,struct node **r)
{
	struct node *q;
	int item;

	if(*f==NULL)
	{
		printf("\nQueue is empty!");
	}
	else
	{
		if(*f==*r)
		{
			item=(*f)->data;
			free(*f);
			*f=NULL;
			*r=NULL;
		}
		else
		{
			q=*f;
			item=q->data;
			*f=(*f)->link;
			(*r)->link=*f;
			free(q);
		}
	}
}

void cirq_display(struct node *f)
{
	struct node*q=f,*p=NULL;
	printf("\nFront-->");

	while(q!=p)
	{
		printf("%2d ",q->data);
		q=q->link;
		p=f;
	}
	printf("--> ... front\n");
}
```
## Output of Prgm-6
```
The circular linked list: 

Front-->10 11 12 13 14 15 --> ... front

After Deletion: 

Front-->13 14 15 --> ... front
```
# Prgm-5 : Sorting Linked List: Pointers
```
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void selection_sort(struct node **start);
void displaylist(struct node *q);
void append(struct node **q, int num);
void bubble_sort(struct node **start);

int main() {
    struct node *start = NULL;
    append(&start, 1);
    append(&start, 4);
    append(&start, 2);
    append(&start, 3);

    printf("Linked List Before Sorting:\n");
    displaylist(start);

    selection_sort(&start);
    printf("\nLinked List After Selection Sorting:\n");
    displaylist(start);

    // Recreate the list for bubble sort test
    // start = NULL;
    append(&start, 8);
    append(&start, 6);
    append(&start, 9);
    append(&start, 10);

    printf("\nLinked List Before Bubble Sorting:\n");
    displaylist(start);

    bubble_sort(&start);
    printf("\nLinked List After Bubble Sorting:\n");
    displaylist(start);

    return 0;
}

void append(struct node **q, int num) {
    struct node *temp = *q;
    if (*q == NULL) {
        *q = malloc(sizeof(struct node));
        temp = *q;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
    }
    temp->data = num;
    temp->next = NULL;
}

void displaylist(struct node *q) {
    struct node* temp = q;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Selection sort using pointer manipulation
void selection_sort(struct node **start) {
    struct node **p, **q, **min, *temp;

    for (p = start; *p && (*p)->next; p = &(*p)->next) {
        min = p;
        for (q = &(*p)->next; *q; q = &(*q)->next) {
            if ((*q)->data < (*min)->data) {
                min = q;
            }
        }
        if (min != p) {
            // Swap the nodes by manipulating pointers
            temp = *p;
            *p = *min;
            *min = temp;

            temp = (*p)->next;
            (*p)->next = (*min)->next;
            (*min)->next = temp;
        }
    }
}

// Bubble sort using pointer manipulation
void bubble_sort(struct node **start) {
    int swapped;
    struct node **p, *temp;

    if (*start == NULL)
        return;

    do {
        swapped = 0;
        p = start;

        while ((*p)->next != NULL) {
            if ((*p)->data > (*p)->next->data) {
                // Swap the nodes by pointer manipulation
                temp = *p;
                *p = (*p)->next;
                temp->next = (*p)->next;
                (*p)->next = temp;

                swapped = 1;
            }
            p = &(*p)->next;
        }
    } while (swapped);
}
```
## Output of Prgm-5
```
Linked List Before Sorting:
1	4	2	3	

Linked List After Selection Sorting:
1	2	3	4	

Linked List Before Bubble Sorting:
1	2	3	4	8	6	9	10	

Linked List After Bubble Sorting:
1	2	3	4	6	8	9	10
```
## Explanation of Prgm-5
```
Selection Sort:

We use double pointers (p, q, and min) to keep track of the addresses of the nodes we’re comparing. This makes it easier to swap nodes by changing the pointers directly. </br>
For each node *p, we find the minimum node (min) in the remaining list.</br>
If a node with a smaller value is found, we swap the nodes *p and *min by adjusting their next pointers.</br>

Bubble Sort:

This function uses a do-while loop to perform multiple passes through the list until no swaps are necessary.</br>
We again use double pointers (p) to track the current and next nodes. If the current node has a greater value than the next, we swap them by adjusting the next pointers.</br>
This process repeats until the list is fully sorted.</br>
```
# Prgm-4 : Sorting Linked List: Data
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
