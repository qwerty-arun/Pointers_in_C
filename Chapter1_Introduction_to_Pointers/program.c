#include <stdio.h>
int main()
{
	int i=20;
	int *ptr=&i;
	int *ptr1=ptr;
	printf("%u \n",ptr);
	printf("%d \n",++*ptr);
	printf("%d \n",(*ptr1)++);
	printf("%d \n",*ptr1);
}
