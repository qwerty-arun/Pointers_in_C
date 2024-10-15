#include <stdio.h> 
#define SET 2
#define ROW 3
#define COL 4 
int *fun1();
int (*fun2())[COL];
int (*fun3())[ROW][COL];
int (*fun4())[SET][ROW][COL];
int main()
{
	int i,j,k;
	int *a;
	int (*b)[COL];
	int *p;
	
	int (*c)[ROW][COL];
	int (*d)[SET][ROW][COL]; 
	a=fun1();
	printf("\nArray a[][][] in main\n");

	for(i=0;i<SET;i++)
	{
	for(j=0;j<ROW;j++)
	{
		for(k=0;k<COL;k++)
			printf("%d ",*(a+i*ROW*COL+j*COL+k));
		printf("\n");
	}
		printf("\n");
	}

	b=fun2();
	printf("\n Array b[][][] in main()\n");
	for(i=0;i<SET;i++)
	{
		p=(int *)(b+i*ROW);
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("%d ",*p);
				p++;
			}
			printf("\n");
		}
		printf("\n");
	}
	
	c=fun3();
	printf("\n Array c[][][] in main(): \n");
	for(i=0;i<SET;i++)
	{
		p=(int *)(c+i);
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("%d ",*p);
				p++;
			}
			printf("\n");
		}
		printf("\n");
	}

	d=fun4();
	printf("\n Array d[][][] in main(): \n");
	for(i=0;i<SET;i++)
	{
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("%d ",(*d)[i][j][k]);
				p++;
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

int *fun1()
{
	static int a[SET][ROW][COL]= 
		{
			{
			1,2,3,4,
			5,6,7,8,
			9,0,1,6
			},
			{
			3,6,5,8,
			1,9,4,10,
			6,3,9,8
			}
		};
	int i,j,k;
	printf("\nArray a[][][] in fun1(): \n");
	for(i=0;i<SET;i++)
	{
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("%d ",a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return (int*)a;
}

int (*fun2())[COL]
{
	static int b[SET][ROW][COL]={
		{
		9,5,7,1,
		4,1,0,5,
		6,7,2,0
		},
		{
		3,8,9,18,
		7,9,4,2,
		3,2,1,0
		}
	};
	int i,j,k;
	printf("\nArray b[][][] in fun2():\n");
	for(i=0;i<SET;i++)
	{
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("%d ",b[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return (int(*)[COL])b;

}

int (*fun3())[ROW][COL]
{
	static int c[SET][ROW][COL]=
		{
			{
			6,9,8,3,
			4,0,8,1,
			3,1,2,7 
			},
			{
			3,5,8,1,
			0,9,7,4,
			1,1,9,6
			}
		};
	int i,j,k;
	printf("\nArray c[][][] in fun3():\n");
	for(i=0;i<SET;i++)
	{
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("%d ",c[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
		return (int (*)[ROW][COL])c;
}


int (*fun4())[SET][ROW][COL]
{
	static int d[SET][ROW][COL]=
		{
			{
			6,9,8,3,
			4,0,8,1,
			3,1,2,7 
			},
			{
			3,5,8,1,
			0,9,7,4,
			1,1,9,6
			}
		};
	int i,j,k;
	printf("\nArray d[][][] in fun3():\n");
	for(i=0;i<SET;i++)
	{
		for(j=0;j<ROW;j++)
		{
			for(k=0;k<COL;k++)
			{
				printf("%d ",d[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
		return (int (*)[SET][ROW][COL])d;
}
