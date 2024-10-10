#include <stdio.h>
void exchange(int **c,int **d);
void swap(int *c, int *d);
int main()
{ 
	int c=10,d=20;
	printf("Before swap, c=%d d=%d\n",c,d);
	swap(&c,&d);
	printf("After swap, c=%d d=%d",c,d);
}

void swap(int *c, int *d)
{
	exchange(&c,&d);	
}

void exchange(int **cc,int **dd)
{
	int t;
	t=*cc;
	**cc=*dd;
	**dd=t;
}
