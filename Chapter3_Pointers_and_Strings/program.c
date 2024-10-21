#include <stdio.h>
#include <string.h>

int main()
{
	 char names[5][10];
	printf("\nEnter 5 name:");
	for(int i=0;i<5;i++)
	{
		scanf("%s",names[i]);
	}
	printf("\nThe 5 names which you entered are:");
	for(int i=0;i<5;i++)
	{
		printf("\n%s",names[i]);
	}
}
