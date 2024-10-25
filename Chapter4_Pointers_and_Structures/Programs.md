# Prgm-8 : Single Linked List Ascending Order
```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void add(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // Special case for the head end
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Locate the node before the point of insertion
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    add(&head, 5);
    add(&head, 1);
    add(&head, 8);
    add(&head, 3);
    add(&head, 7);

    printf("Sorted Linked List: ");
    display(head);

    return 0;
}
```
## Output of Prgm-8
```
Sorted Linked List: 1 -> 3 -> 5 -> 7 -> 8 -> NULL
```
# Prgm-7: Single Linked List program
```
#include <stdio.h>
#include <stdlib.h>
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
	struct node *p;
	p=NULL;//empy linked list
	printf("\nNo. of elements in the Linked List = %d",count(p));
	append(&p,1);
	append(&p,2);
	append(&p,3);
	append(&p,4);
	append(&p,19);
	append(&p,61);

	display(p);
	
	addatbeg(&p,999);
	addatbeg(&p,888);
	addatbeg(&p,777);

	display(p);
	
	addafter(p,7,0);
	addafter(p,2,1);
	addafter(p,1,99);

	display(p);

	printf("\nNo. of elements in the linked list =%d",count(p));

	delete(&p,888);
	delete(&p,1);
	delete(&p,10);

	display(p);

	printf("\nNo. of elements in the linked list =%d",count(p));
	free(p);
}

void append(struct node **q, int num)
{
	struct node *temp,*r;
	temp=*q;

	if(*q==NULL)
	{
		temp=malloc(sizeof(struct node));
		temp->data=num;
		temp->link=NULL;
		*q=temp;
	}
	else
	{
		temp=*q;
		while(temp->link!=NULL)
			temp=temp->link;

		r=malloc(sizeof(struct node));
		r->data=num;
		r->link=NULL;
		temp->link=r;
	}
	free(temp);
	free(r);
}

void addatbeg(struct node **q,int num)
{
	struct node *temp;
	temp=malloc(sizeof(struct node));
	temp->data=num;
	temp->link=*q;
	*q=temp;
	free(temp);
}

void addafter(struct node *q, int loc, int num)
{
	struct node *temp,*r;
	int i;
	temp=q;
	for(i=0;i<loc;i++)
	{
		temp=temp->link;
		if(temp==NULL)
		{
			printf("\nThere are less than %d elements in list",loc);
			return ;
		}
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
```
## Output of Prgm-7
```
No. of elements in the Linked List = 0
1 2 3 4 19 61 
777 888 999 1 2 3 4 19 61 
777 888 999 1 2 3 4 19 61 
No. of elements in the linked list =9
Element 10 not found
777 999 2 3 4 19 61 
No. of elements in the linked list =7
```
## If we try something like *q+5, it will show an error. It says "invalid operands to binary expression ('struct general' and 'int')" 
# Prgm-6
```
# include <stdio.h>
int main()
{
	struct general 
	{
		char a; 
		double d;
	};
	struct general p[5][5];
	struct general *q;
	q=&p[0][0];
	p[0][0].a='0';
	p[0][0].d=3.14;
	(*(*(p+1)+1)).a='1';
	(*(*(p+1)+1)).d=2.718;
	printf("\n%c %lf",p[0][0].a,p[0][0].d);
	printf("\n%c %lf",p[1][1].a,p[1][1].d);
	printf("\n%c %lf",(*q).a,(*q).d);
}
```
## Output of Prgm-6
```
0 3.140000
1 2.718000
0 3.140000
```
# Prgm-5
```
# include <stdio.h>
int main()
{
	struct general 
	{
		char a; 
		double d;
	};
	struct general p[5][5];
	struct general *q[5][5];
	p[0][0].a='0';
	p[0][0].d=3.14;
	(*(*(p+1)+1)).a='1'; //same as p[1][1].a='1';
	(*(*(p+1)+1)).d=2.718;
	printf("\n%c %lf",p[0][0].a,p[0][0].d);
	printf("\n%c %lf",p[1][1].a,p[1][1].d);
}
```
## Output of Prgm-5
```
0 3.140000
1 2.718000
```
## What does `struct general p[5][5] mean?` Well, it is valid. The size of `p` will be 400 (16*25). The same for the pointers will be 200.
# Prgm-4
```
# include <stdio.h>
int main()
{
	struct general 
	{
		char a; 
		double d;
	};
	struct general p[5];
	struct general *q[5];
	printf("\nSize of array of structure: %d",sizeof(p));
	printf("\nSize of array of pointers to structure: %d",sizeof(q));
}
```
## Output of Prgm-4
```
Size of array of structure: 80
Size of array of pointers to structure: 40
```
## If you add a pointer to the same struct, then the size will be 32, indicating that the pointer size is 8.
# Prgm-3
```
# include <stdio.h>
int main()
{
	struct general 
	{
		int age;
		float huh;
		double d;
		char a; 
	};
	struct general p1;
	printf("\nSize of p1: %d",sizeof(p1));
}
```
## Output of Prgm-3
```
24
It should have been 4+4+8+1=17 right? Well this the concept of structure padding.
```
# Prgm-2
```
# include <stdio.h>
int main()
{
	struct player
	{
		char name[20];
		int age;
	};
	struct player p1;
	printf("\naddress of p1: %u",&p1);
	printf("\naddress of name: %u",&(p1.name));
	printf("\naddress of age: %u",&(p1.age));
	printf("\nSize of p1: %d",sizeof(p1));
}
```
## Output of Prgm-2
```
address of p1: 1813065416
address of name: 1813065416
address of age: 1813065436
Size of p1: 24
```
## For structure pointers, we use '->' to access the structure elements.
## ptr-> name is the same as (*ptr).name
# Prgm-1: Structure pointers
```
# include <stdio.h>
int main()
{
	struct player
	{
		char name[20];
		int age;
	};
	struct player p1={"Dhruv",26};
	struct player *ptr;
	ptr=&p1;
	printf("\n%s %d",p1.name,p1.age);
	printf("\n%s %d",ptr->name,ptr->age);
}
```
## Structure variables can be passed to function. Even individual elements or the structure itself. If we need to we pass address of structure elements or the structure itself.
```
struct college
{
    char address[20];
    char name[20];
};
struct student
{
    char name[20];
    char ID[10];
    struct college c1;
};
Accessing them: struct student s1; s1.c1.address=" ";
```
## Nested Structures are possible
## Value of one structure variable can be assigned to another structure variable of the same type. p2=p1; is valid.
## All of the below are correct
```
struct 
{
    char name[20];
    int age;
}p1={"Dhruv",30};
```
```
struct player
{
    char name[20];
    int age;
}p1={"Dhruv",30};
```
```
struct player
{
    char name[20];
    int age;
};
struct player p1={"Dhruv",30};
```
## struct account a[10]; is an array of 10 structures.
## It is mandatory to use 'struct' keyword while declaration. If we don't want to, then we can use typedef keyword where the struct itself is defined.
## '.' operator is used to access elements
# An expert C Programmer is one who avoids all errors except those related with pointers.

