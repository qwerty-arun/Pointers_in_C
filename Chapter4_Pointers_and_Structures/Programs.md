# Prgm-23
```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct a
    {
        struct b
        {
            char name[20];
            int age;
        }bb;
        struct c
        {
            char address[40];
            int sal;
        }cc;
    };
    struct a *ptr;
    struct a aa ={
    {"Raju",30},
    {"Rajajinagar, Bengaluru",40000}
    };
    ptr=&aa;
    printf("\n%s %s %d %d",ptr->bb.name,ptr->cc.address,ptr->bb.age,ptr->cc.sal);
}
```
## Output of Prgm-23
```
Raju Rajajinagar, Bengaluru 30 40000
```
# Prgm-22
```
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
{
        int data;
        struct node *prev;
        struct node *next;
    };
    struct node *p,*q;
    p=(struct node*)malloc(sizeof(struct node));
    q=(struct node*)malloc(sizeof(struct node));
    p->data=30;
    q->data=40;
    p->prev=NULL;
    p->next=q;
    q->prev=p;
    q->next=NULL;

    while(p!=NULL)
    {
        printf("\n%d",p->data);
        p=p->next;
    }
    free(p);
    free(q);
}
```
## Output of Prgm-22
```
30
40
```
# Prgm-21
```
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
{
        int data;
        struct node *link;
    };
    struct node *p,*q;
    p=(struct node*)malloc(sizeof(struct node));
    q=(struct node*)malloc(sizeof(struct node));
    p->data=30;
    p->link=q;
    q->data=40;
    q->link=NULL;
    printf("\n%d",p->data);
    p=p->link;
    printf("\n%d",p->data);
}
```
## Output of Prgm-21
```
30
40
This is a small linked list if observed closely
```
# Prgm-20
```
#include <stdio.h>

struct s1
{
    char *str;
    struct s1 *next;
};

void swap(struct s1 *p1, struct s1 *p2);
int main()
{
    static struct s1 arr[]={
    {"Alpha",arr+1},
    {"Beta",arr+2},
    {"Gamma",arr}
    };
    struct s1 *p[3];
    int i;
    for(i=0;i<3;i++)
    {
        p[i]=arr[i].next;
    }

    printf("\n%s %s %s",p[0]->str,(*p)->str,(**p).str);

    swap(*p,arr);

    printf("\n%s",p[0]->str);
    printf("\n%s",(*p)->str);
    printf("\n%s",(*p)->next->str);

    swap(p[0],p[0]->next);

    printf("\n%s",p[0]->str);
    printf("\n%s",(*++p[0]).str);
    printf("\n%s",++(*++(*p)->next).str);
}
void swap(struct s1 *p1, struct s1 *p2)
{
    char *temp;
    temp=p1->str;
    p1->str=p2->str;
    p2->str=temp;
}
```
## Output of PRgm-20
```
Beta Beta Beta
Alpha
Alpha
Gamma
Gamma
Alpha
amma
```
# Prgm-19
```
#include <stdio.h>

int main()
{
struct s1 
{
    char *str;
    struct s1 *ptr;
};
    static struct s1 a[] = {
    {"Noida",a+1},
    {"Kochi",a+2},
    {"Chennai",a}
    };
    struct s1 *p[3];
    int i;
    for(i=0;i<=2;i++)
        p[i]=a[i].ptr;
    printf("\n%s",p[0]->str);
    printf("\n%s",(*p)->str);
    printf("\n%s",**p);
}
```
## Output of Prgm-19
```
Kochi
Kochi
Kochi
```
# Prgm-18
```
#include <stdio.h>

int main()
{
struct s1 
{
    char *z;
    int i;
    struct s1 *p;
};
    static struct s1 a[] = {
    {"Noida",1,a+1},
    {"Kochi",2,a+2},
    {"Chennai",3,a}
    };
    struct s1 *ptr = a;
    printf("\n%s",++(ptr->z));
    printf("\n%s",a[(++ptr)->i].z);
    printf("\n%s",a[--(ptr->p->i)].z);
}
```
## Output of PRgm-18
```
oida
Chennai
Chennai
```
# Prgm-17
```
#include <stdio.h>

int main()
{
struct s1 
{
    char *str;
    int i;
    struct s1 *ptr;
};
    static struct s1 a[] = {
    {"Noida",1,a+1},
    {"Kochi",2,a+2},
    {"Chennai",3,a}
    };
    struct s1 *p = a;
    int j;
    for(j=0;j<=2;j++)
    {
        printf("\n%d ",--a[j].i);
        printf("%s",++a[j].str);
    }
}
```
## Output of Prgm-17
```
0 oida
1 ochi
2 hennai
```
# Prgm-16
```
#include <stdio.h>


int main()
{
struct s1 
{
    char *z;
    int i;
    struct s1 *p;
};
    static struct s1 a[] = {
    {"Noida",1,a+1},
    {"Kochi",2,a+2},
    {"Chennai",3,a}
    };
    struct s1 *ptr = a;
    printf("\n%s %s %s",a[0].z,ptr->z,a[2].p->z);
}
```
## Output of Prgm-16
```
Noida Noida Noida
```
# Prgm-15
```
#include <stdio.h>

struct a 
{
    char ch[7];
    char *str;
};

struct b 
{
    char *c;
    struct a ss1;
};

int main()
{
    struct b s2 = {"Bengaluru","Indore","Mizoram"};
    printf("\n%s %s",s2.c,s2.ss1.str);
    printf("\n%s %s",++s2.c,++s2.ss1.str);
}
```
## Output of Prgm-15
```
Bengaluru Mizoram
engaluru izoram
```
## `*s1.str` signifies the value at address contained in s1.str
# Prgm-14
```
#include <stdio.h>

struct a 
{
    char ch[7];
    char *str;
};

int main()
{
    struct a s1 = {"Delhi","Mumbai"};
printf("\n%c %c",s1.ch[0],*s1.str);
printf("\n%s %s",s1.ch,s1.str);
}
```
## Output of Prgm-14
```
D M
Delhi Mumbai
```
## Note that structure padding is happening here.
## m[] has been declared as an array of structures. Each structure consists of dissimilar data types, more than one similar structures are capable of formind an array.
# Prgm-13
```
#include <stdio.h>
#include <string.h>

struct  
{
    char mess[50];
    int num;
    float f;
}m[2];

int main()
{
printf("\n%u %u %u",m[0].mess,&m[0].num,&m[0].f);
printf("\n%u %u %u",m[1].mess,&m[1].num,&m[1].f);
}
```
## Output of Prgm-13
```
4104974400 4104974452 4104974456
4104974460 4104974512 4104974516
```
# Prgm-12 : Double Linked List
```
#include <stdio.h>
#include <stdlib.h>

struct dnode
{
    struct dnode *prev;
    int data;
    struct dnode *next;
};

void d_append(struct dnode **s, int num);
void d_delete(struct dnode **s,int num);
int d_count(struct dnode *q);
void d_display(struct dnode *q);
void d_addafter(struct dnode *q,int loc,int num);
void d_addatbeg(struct dnode **s,int num);
int main()
{
    struct dnode *p;

    p=NULL;

    d_append(&p,11);
    d_append(&p,21);

    d_display(p);
    printf("\nNo. of elements in the DLL = %d\n",d_count(p));

    d_addatbeg(&p,33);
    d_addatbeg(&p,55);

    d_display(p);
    printf("\nNo. of elements in the DLL = %d\n",d_count(p));

    d_addafter(p,1,4000);
    d_addafter(p,2,9000);

    d_display(p);
    printf("\nNo. of elements in the DLL = %d\n",d_count(p));

    d_delete(&p,51);
    d_delete(&p,21);

    d_display(p);
    printf("\nNo. of elements in the DLL = %d\n",d_count(p));
    return 0;
}

void d_append(struct dnode **s, int num)
{
    struct dnode *r,*q=*s;
    if(*s==NULL)
    {
        *s=(struct dnode*)malloc(sizeof(struct dnode));
        (*s)->prev=NULL;
        (*s)->data=num;
        (*s)->next=NULL;
    }
    else
    {
        while(q->next!=NULL)
            q=q->next;
        r=(struct dnode*)malloc(sizeof(struct dnode));
        r->data=num;
        r->next=NULL;
        r->prev=q;
        q->next=r;
    }
}

void d_addatbeg(struct dnode **s,int num)
{
    struct dnode *q;
    q=(struct dnode*)malloc(sizeof(struct dnode));
    q->prev=NULL;
    q->data=num;
    q->next=*s;

    (*s)->prev=q;
    *s=q;
}

void d_addafter(struct dnode *q,int loc,int num)
{
    struct dnode *temp;
    int i;
    for(i=0;i<loc;i++)
    {
        q=q->next;
        if(q==NULL)
        {
            printf("\nThere are less than %d elements",loc);
            return;
        }
    }
    
    q=q->prev;
    temp=(struct dnode*)malloc(sizeof(struct dnode));
    temp->data=num;
    temp->prev=q;
    temp->next=q->next;
    temp->next->prev=temp;
    q->next=temp;
}

void d_display(struct dnode *q)
{
    printf("\n");

    while(q!=NULL)
    {
        printf("%2d <-->",q->data);
        q=q->next;
    }
    printf("---> NULL\n");
}

int d_count(struct dnode *q)
{
    int c=0;

    while(q!=NULL)
    {
        q=q->next;
        c++;
    }
    return c;
}

void d_delete(struct dnode **s,int num)
{
    struct dnode *q=*s;
    while(q!=NULL)
    {
        if(q->data==num)
        {
            if(q==*s)
            {
                *s=(*s)->next;
                (*s)->prev=NULL;
            }
            else
            {
                if(q->next==NULL)
                    q->prev->next=NULL;
                else
                {
                    q->prev->next=q->next;
                    q->next->prev=q->prev;
                }
                free(q);
            }
            return;
        }
        q=q->next;
    }
    printf("\n%d Not Found!",num);
}
```
## Output of Prgm-12
```
11 <-->21 <-->---> NULL

No. of elements in the DLL = 2

55 <-->33 <-->11 <-->21 <-->---> NULL

No. of elements in the DLL = 4

55 <-->4000 <-->9000 <-->33 <-->11 <-->21 <-->---> NULL

No. of elements in the DLL = 6

51 Not Found!
55 <-->4000 <-->9000 <-->33 <-->11 <-->---> NULL

No. of elements in the DLL = 5
```
# Prgm-11 : Deque 
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* link;
};

void addqatend(struct node**, struct node**, int);
void addqatbeg(struct node**, struct node**, int);
void q_display(struct node* q);
int count(struct node *q);
int delqatbeg(struct node**, struct node**);
int delqatend(struct node**, struct node**);

int main()
{
    struct node *front,*rear;
    int item;
    front=rear=NULL;

    addqatend(&front,&rear,11);
    addqatbeg(&front,&rear,12);
    addqatend(&front,&rear,13);
    addqatend(&front,&rear,14);
    addqatend(&front,&rear,15);
    addqatend(&front,&rear,16);
    addqatend(&front,&rear,17);
    addqatend(&front,&rear,17);

    q_display(front);
    printf("No. of items in stack = %d",count(front));
    
    printf("\nItems exracted from stack: ");
    item = delqatbeg(&front,&rear);
    printf("%d ",item);

    item = delqatbeg(&front,&rear);
    printf("%d ",item);

    item = delqatbeg(&front,&rear);
    printf("%d ",item);

    item = delqatend(&front,&rear);
    printf("%d ",item);

    printf("\n");
    q_display(front);
    printf("\nNo. of items in queue= %d",count(front));
}

void addqatend(struct node** f,struct node **r,int item)
{
    struct node *q;
    q=malloc(sizeof(struct node));
    q->data=item;
    q->link=NULL;
    if(*f==NULL)
        *f=q;
    else
        (*r)->link=q;
    *r=q;
}

void addqatbeg(struct node** f,struct node **r,int item)
{
    struct node *q;
    int *temp;
    q=malloc(sizeof(struct node));
    q->data=item;
    q->link=NULL;
    if(*f==NULL)
        *f=q;
    else
    {
        q->link=*f;
        *r=*f;
        *f=q;
    }
}

int delqatbeg(struct node **f,struct node **r)
{
    int item;
    struct node *q;
    
    if(*f==NULL)
        printf("\nQueue is empty!");
    else
    {
        q=*f;
        item=q->data;
        *f=q->link;
        free(q);

        if(*f==NULL)
            *r=NULL;
        return(item);
    }
}

int delqatend(struct node **f,struct node **r)
{
    int item;
    struct node *q,*rleft,*temp;
    
    temp=*f;
    if(*r==NULL)
        printf("\nQueue is empty!");
    else
    {
        while(temp!=*r)
        {
            rleft=temp;
            temp=temp->link;
        }
        q=*r;
        item=q->data;
        free(q);
        *r=rleft;
        (*r)->link=NULL;

        if(*r==NULL)
            *f=NULL;
        return(item);
    }
}

void q_display(struct node* q)
{
    printf("\nfront-> ");
    while(q!=NULL)
    {
        printf("%2d ",q->data);
        if(q->link==NULL)
            printf(" <-rear");

        q=q->link;
    }
    printf("\n");
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

```
## Output of Prgm-11
```
front-> 12 11 13 14 15 16 17 17  <-rear
No. of items in stack = 8
Items exracted from stack: 12 11 13 17 

front-> 14 15 16 17  <-rear

No. of items in queue= 4
```
## A deque is a queue in which elements can be added or deleted from both the ends.
# Prgm-10 : Queue as a linked list
```
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

void addq(struct node**, struct node**, int);
int delq(struct node**,struct node**);
void q_display(struct node* q);
int count(struct node *q);

int main()
{
    struct node *front,*rear;
    int item;
    front=rear=NULL;

    addq(&front,&rear,11);
    addq(&front,&rear,12);
    addq(&front,&rear,13);
    addq(&front,&rear,14);
    addq(&front,&rear,15);
    addq(&front,&rear,16);
    addq(&front,&rear,17);

    q_display(front);
    printf("No. of items in stack = %d",count(front));
    
    printf("\nItems exracted from stack: ");
    item = delq(&front,&rear);
    printf("%d ",item);

    item = delq(&front,&rear);
    printf("%d ",item);

    item = delq(&front,&rear);
    printf("%d ",item);

    q_display(front);
    printf("\nNo. of items in stack= %d",count(front));
}

void addq(struct node** f,struct node **r,int item)
{
    struct node *q;
    q=malloc(sizeof(struct node));
    q->data=item;
    q->link=NULL;
    if(*f==NULL)
        *f=q;
    else
        (*r)->link=q;
    *r=q;
}

int delq(struct node **f,struct node **r)
{
    int item;
    struct node *q;
    
    if(*f==NULL)
        printf("\nQueue is empty!");
    else
    {
        q=*f;
        item=q->data;
        *f=q->link;
        free(q);
        if(*f==NULL)
            *r=NULL;
        return(item);
    }
}

void q_display(struct node* q)
{
    printf("\nfront-> ");
    while(q!=NULL)
    {
        printf("%2d ",q->data);
        if(q->link==NULL)
            printf(" <-rear");

        q=q->link;
    }
    printf("\n");
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
```
## Output of Prgm-10
```
front-> 11 12 13 14 15 16 17  <-rear
No. of items in stack = 7
Items exracted from stack: 11 12 13 
front-> 14 15 16 17  <-rear
No. of items in stack= 4
```
# Prgm-9 : Stack as a linked list
```
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

void push(struct node**,int );
int pop(struct node**);
int count(struct node *q);
void stack_display(struct node* q);

int main()
{
    struct node *top;
    int item;
    top=NULL;

    push(&top,11);
    push(&top,12);
    push(&top,13);
    push(&top,14);
    push(&top,15);
    push(&top,16);
    push(&top,17);

    stack_display(top);
    printf("No. of items in stack = %d",count(top));
    
    printf("\nItems exracted from stack: ");
    item = pop(&top);
    printf("%d ",item);

    item = pop(&top);
    printf("%d ",item);

    item = pop(&top);
    printf("%d ",item);

    stack_display(top);
    printf("No. of items in stack= %d",count(top));
}

void push(struct node** s, int item)
{
    struct node *q;
    q=malloc(sizeof(struct node));
    q->data=item;
    q->link=*s;
    *s=q;
}

int pop(struct node **s)
{
    int item;
    struct node *q;
    
    if(*s==NULL)
        printf("\nStack is empty!");
    else
    {
        q=*s;
        item=q->data;
        *s=q->link;
        free(q);
        return(item);
    }
}

void stack_display(struct node* q)
{
    printf("\n");
    while(q!=NULL)
    {
        printf("%2d ",q->data);
        q=q->link;
    }
    printf("\n");
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
```
## Output of Prgm-9
```
17 16 15 14 13 12 11 
No. of items in stack = 7
Items exracted from stack: 17 16 15 
14 13 12 11 
No. of items in stack= 4
```
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
        r=malloc(sizeof(struct node));
        r->data=num;
        r->link=temp->link;
        temp->link=r;
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
