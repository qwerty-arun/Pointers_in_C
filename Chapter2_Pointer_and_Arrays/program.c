#include <stdio.h>
void display(int *q,int row, int col);
void show(int (*q)[4],int row, int col);
void print(int q[][4],int row, int col);
int main()
{
	int a[3][4]={
			4,5,6,9,
			12,1,9,5,
			2,3,8,7
			};
	display(a,3,4);
	show(a,3,4);
        print(a,3,4);
	return 0;
}

void display(int *q,int row, int col)
{
	printf("\n");
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d ",*(q+i*col+j)); //even *(*(q+j)+i) works
		printf("\n");
	}
}
void show(int (*q)[4],int row, int col)
{
	printf("\n");
	int *p;
	int i,j;
	for(i=0;i<row;i++)
	{
		p=q+i;
		for(j=0;j<col;j++)
			printf("%d ",*(p+j));
		printf("\n");
	}
}
void print(int q[][4],int row, int col)
{
	printf("\n");
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d ",q[i][j]);
		printf("\n");
	}
}
