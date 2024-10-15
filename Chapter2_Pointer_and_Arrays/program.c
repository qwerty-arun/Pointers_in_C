#include <stdio.h>
int main()
{
	int a[]={0,1,2,3,4};
	int *p[]={a,a+1,a+2,a+3,a+4};
	printf("\nAddress of a: %u",a);
	printf("\np: %u, *p = %u ,*(*p) = %d",p,*p,*(*p));
	printf("\np[0] = %u",p[0]);
	printf("\np[1] = %u",p[1]);
}
