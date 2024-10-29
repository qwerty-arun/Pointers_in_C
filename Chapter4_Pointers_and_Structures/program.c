#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
{
        int data;
        struct node *next;
    };
    struct node *p,*q;
    p=(struct node*)malloc(sizeof(struct node));
    q=(struct node*)malloc(sizeof(struct node));
    p->data=30;
    q->data=40;
    p->next=q;
    q->next=p;

    while(p!=NULL)
    {
        printf("\n%d",p->data);
        p=p->next;
    }
    free(p);
    free(q);
}
