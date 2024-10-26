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
