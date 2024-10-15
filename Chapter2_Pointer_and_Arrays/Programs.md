## Array of pointers is mainly used to store several strings in memory.
## Array of pointers: int *arr[4] defines an array of pointers for 4 integers. Then arr[0]=&i and so on for storing addresses. Each element in the array stores addresses. `*arr[m]` gives value at address.
# Prgm-11 (Returning a 3D array)
```
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
```
## Similarly, there are different ways to return a 3D array: a pointer to an integer, a pointer to the zeroth 1D array, a pointer to the zeroth 2D array or a pointer to the 3D array itself.
## There are 3 ways to return a 2D array: a pointer to an integer, a pointer to the zeroth 1D array, a pointer to the 2D array
# Prgm-10 (Returning a 2D array)
```
#include <stdio.h>
#define ROW 3
#define COL 4 
int *fun1();
int (*fun2())[COL];
int (*fun3())[ROW][COL];
int main()
{
	int i,j;
	int *a;
	int (*b)[COL];
	int *p;
	
	int (*c)[ROW][COL];
	a=fun1();

	printf("\nArray a[][] in main()\n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			printf("%d ",*(a+i*COL+j));
		printf("\n");
	}

	b=fun2();
	printf("\n Array b[][] in main()\n");
	for(i=0;i<ROW;i++)
	{
		p=b+i;
		for(j=0;j<COL;j++)
		{
			printf("%d ",*p);
		p++;
		}
		printf("\n");
	}
	
	c=fun3();
	printf("\n Array c[][] in main(): \n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			printf("%d ",(*c)[i][j]);
		printf("\n");
	}

	return 0;
}

int *fun1()
{
	static int a[ROW][COL]= {
			1,2,3,4,
			5,6,7,8,
			9,0,1,6
		};
	int i,j;
	printf("\nArray a[][] in fun1(): \n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return (int*)a;
}

int (*fun2())[COL]
{
	static int b[ROW][COL]={
		9,5,7,1,
		4,1,0,5,
		6,7,2,0
	};
	int i,j;
	printf("\nArray b[][] in fun2():\n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	return b;

}

int (*fun3())[ROW][COL]
{
	static int c[ROW][COL]={
		6,9,8,3,
		4,0,8,1,
		3,1,2,7 };
	int i,j;
	printf("\nArray c[][] in fun3():\n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
		return (int (*)[ROW][COL])c;
}
```  
## 
```
Array a[][] in fun1(): 
1 2 3 4 
5 6 7 8 
9 0 1 6 

Array a[][] in main()
1 2 3 4 
5 6 7 8 
9 0 1 6 

Array b[][] in fun2():
9 5 7 1 
4 1 0 5 
6 7 2 0 

 Array b[][] in main()
9 5 7 1 
4 1 0 5 
6 7 2 0 

Array c[][] in fun3():
6 9 8 3 
4 0 8 1 
3 1 2 7 

 Array c[][] in main(): 
6 9 8 3 
4 0 8 1 
3 1 2 7 
```
# Prgm-9 (Passing 3D array to a function)
```
#include <stdio.h>
void display(int *q,int ii,int jj, int kk);
void show(int (*q)[3][4],int ii, int jj, int kk);
void print(int q[][3][4], int ii, int jj, int kk);
int main()
{
	int a[2][3][4] = {
				{
					1,2,3,4,
					5,6,7,8,
					9,3,2,1
				},
				{
					2,3,5,7,
					4,3,9,2,
					1,6,3,6
				}
			};
	display(a,2,3,4);
	show(a,2,3,4);
	print(a,2,3,4);
	return 0;
}

void display(int *q,int ii,int jj, int kk)
{
	int i,j,k;
	for(i=0;i<ii;i++)
	{
		for(j=0;j<jj;j++)
		{
			for(k=0;k<kk;k++)
			{
				printf("%d ",*(q+i*jj*kk+j*kk+k));
			}
			printf("\n");
		}
		printf("\n");
	}
}

void show(int (*q)[3][4],int ii, int jj, int kk)
{
	int i,j,k;
	int *p;
	for(i=0;i<ii;i++)
	{
		for(j=0;j<jj;j++)
		{
			p=q[i][j];
			for(k=0;k<kk;k++)
			{
				printf("%d ",*(p+k));
			}
			printf("\n");
		}
		printf("\n");
	}
}

void print(int q[][3][4], int ii, int jj, int kk)
{
	int i,j,k;
	for(i=0;i<ii;i++)
	{
		for(j=0;j<jj;j++)
		{
			for(k=0;k<kk;k++)
			{
				printf("%d ",q[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}

}
```
## Output of Prgm-9
```
1 2 3 4 
5 6 7 8 
9 3 2 1 

2 3 5 7 
4 3 9 2 
1 6 3 6 

1 2 3 4 
5 6 7 8 
9 3 2 1 

2 3 5 7 
4 3 9 2 
1 6 3 6 

1 2 3 4 
5 6 7 8 
9 3 2 1 

2 3 5 7 
4 3 9 2 
1 6 3 6 
```
## a is pointer to zeroth element which is a 2D array. `*a` gives pointer to zeroth element of the 2-D array, hence **a whould give the zeroth element. But the zeroth element of the 2D array is a 1D array. On mentioning 1D array, we get the address of its zeroth element. `a+1` would give the address of the first 2D array. 
# Prgm-8 (3D array contd.)
```
#include <stdio.h>
int main()
{
	int a[3][4][2] = {
				{
					{2,4},
					{7,8},
					{3,4},
					{5,6}
				},
				{
					{7,6},
					{3,4},
					{5,3},
					{2,3}
				},
				{
					{8,9},
					{7,2},
					{3,4},
					{5,1}
				}
			};
	printf("\n%u",a);
	printf("\n%u",*a);
	printf("\n%u",**a);
	printf("\n%d",***a);
	printf("\n%u",a+1);
	printf("\n%u",*a+1);
	printf("\n%u",**a+1);
	printf("\n%d",***a+1);
	return 0;
}
```
## Output of Prgm-8
```
2072387152
2072387152
2072387152
2
2072387184
2072387160
2072387156
3
```
## `a[3][4][2]` can be interpreted in many ways: 3 two dimensional arrays with 4 rows and 2 columns, or 1D arrays of two elements is constructed first, then four of them one below the other and then finally these 2D arrays are place one behind the other.
# Prgm-7 (3D array)
```
#include <stdio.h>
int main()
{
	int a[3][4][2] = {
				{
					{2,4},
					{7,8},
					{3,4},
					{5,6}
				},
				{
					{7,6},
					{3,4},
					{5,3},
					{2,3}
				},
				{
					{8,9},
					{7,2},
					{3,4},
					{5,1}
				}
			};
	printf("a: %u \n",a);
	printf("a+1:%u \n",a+1);
	printf("a: %d \n",***a);
	printf("a+1:%d \n",***(a+1));

	printf("Address of 0th 2D array, and 0th 1D array: %u\n",**a);
	printf("Value of 0th 2D array, and 0th 1D array: %u\n",***a);

	printf("Address of 0th 2D array, and 1st 1D array: %u\n",*(*a+1));
	printf("Value of 0th 2D array, and 1st 1D array and 0th element: %d\n",**(*a+1));

	printf("Address of 1st 2D array, and 2nd 1D array: %u\n",*(*(a+1)+2));
	printf("Value of 0th 2D array, and 0th 1D array: %d\n",***((a+1)+2));

	return 0;
}
```
## Output of Prgm-7
```
a: 3784940864 
a+1: 3784940896
a: 2
a+1: 7
Address of 0th 2D array, and 0th 1D array: 894069952
Value of 0th 2D array, and 0th 1D array: 2
Address of 0th 2D array, and 1st 1D array: 894069960
Value of 0th 2D array, and 1st 1D array and 0th element: 7
Address of 1st 2D array, and 2nd 1D array: 894070000
Value of 0th 2D array, and 0th 1D array: 0
```
## num[i], i[num], *(num+i) and *(i+num) are all the same.
## General formula for accessing each array element is *(base address + row no. * no. of columns + column no.)
# Prgm-6 (Passing 2D array to a function)
```
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
			printf("%d ",*(p+j)); //we could still use q[i][j]
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
```
## Output of Prgm-6
```
4 5 6 9 
12 1 9 5 
2 3 8 7 

4 5 6 9 
12 1 9 5 
2 3 8 7 

4 5 6 9 
12 1 9 5 
2 3 8 7
```
## In the programs below, p is an integer pointer, q is a pointer to an array of 4 integers. Therefore incrementing p points to the next integer and q starts pointing to the next 1-D array of integers
## Pointer to an array is very useful while passing a 2D array to a function.
# Prgm-5 (Pointer to an array)
```
#include <stdio.h>
int main()
{
	int a[][4]={
			4,5,6,9,
			12,1,9,5,
			2,3,8,7
			};
	int *p;
	int (*q)[4];
	p=(int*)a;
	q=a;
	printf("\n Adresses of p and q: %p %p",p,q);
	printf("\n Values of p and q: %d %d",*p,**q);
	p++;
	q++;
	printf("\n Addresses of p and q %p %p",p,q);
	printf("\n Values of p and q: %d %d",*p,**q);
	return 0;
}
```
## Output of Prgm-5
```
 Adresses of p and q: 0x7ffc30732e40 0x7ffc30732e40
 Values of p and q: 4 4
 Addresses of p and q 0x7ffc30732e44 0x7ffc30732e50
 Values of p and q: 5 12
```
# Prgm-4
```
#include <stdio.h>
int main()
{
	int a[][4]={
			4,5,6,9,
			12,1,9,5,
			2,3,8,7
			};
	int *p;
	int (*q)[4];
	p=(int*)a;
	q=a;
	printf("\n Adresses of p and q: %u %u",p,q);
	printf("\n Values of p and q: %d %d",*p,*q);
	p++;
	q++;
	printf("\n Addresses of p and q %u %u",p,q);
	printf("\n Values of p and q: %d %d",*p,*q);
	return 0;
}
```
## Output of Prgm-4
```
 Adresses of p and q: 1162057424 1162057424
 Values of p and q: 4 1162057424
 Addresses of p and q: 1162057428 1162057440
 Values of p and q: 5 1162057440>> vi program.c
```
## Can we have pointer to an array? Yes, we can. int (*q)[4] means that q is a pointer to an array of 4 integers.
# Prgm-3
```
#include <stdio.h>
int main()
{
	int s[3][3]={{1000,12,1},{1004,16,2},{1008,45,3}};
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",*(*(s+i)+j));
		}
		printf("\n");
	}
	return 0;
}
```
## Result of Prgm-3
```
1000 12 1
1004 16 2
1008 45 3
```
## Suppose we want to refer to the element s[2][1], we know s[2] is *(s+2) and therefore (s[2]+1) would give us address of s[2][1] and then we need to dereference it. Therefore `*(s[2]+1)` will be the same as `*(*(s+2)+1)`
## In general for a 2D array, `s[i]` or `*(s+i)` will give the base address of the 'i'th 1D array
## We can see that 2D arrays are represented as series of 1D arrays.
# Prgm-2
```
#include <stdio.h>
int main()
{
	int s[3][3]={{1000,12,1},{1004,16,2},{1008,45,3}};
	int i;
	for(i=0;i<4;i++)
	{
		printf("\n Address of %dth 1-D array =%u",i,s[i]);
		printf("\n First value of %dth 1-D array =%d",i,s[i][1]);
	}
	return 0;
}
```
## Result of Prgm-2
```
Address of 0th 1-D array =4008659456
 First value of 0th 1-D array =12
 Address of 1th 1-D array =4008659468
 First value of 1th 1-D array =16
 Address of 2th 1-D array =4008659480
 First value of 2th 1-D array =45
 Address of 3th 1-D array =4008659492
 First value of 3th 1-D array =0
```
# Prgm-1
```
#include <stdio.h>
int main()
{
	int s[3][2]={{1000,12},{1004,16},{1008,45}};
	int i;
	for(i=0;i<4;i++)
	{
		printf("\n Address of %dth 1-D array =%u",i,s[i]);
		printf("\n First value of %dth 1-D array =%d",i,s[i][1]);
	}
	return 0;
}
```
## Output of Prgm-1
```
Address of 0th 1-D array =2748615056
 First value of 0th 1-D array =12
 Address of 1th 1-D array =2748615064
 First value of 1th 1-D array =16
 Address of 2th 1-D array =2748615072
 First value of 2th 1-D array =45
 Address of 3th 1-D array =2748615080
 First value of 3th 1-D array =0
```
# Key Learnings
## Each row of a 2D array can be thought as a 1D array. This is a very powerful way to access array elements.
## Two dimensional array is nothing but a collection of a number of a 1D arrays placed one after another
## `*(arr+i)` is for accessing and is the same as `*arr[i]`
## `&arr[i]` and `arr+i` are the same. Which one is better? Well accessing array elements using pointers is always faster than accessing them by subscripts. But while using pointers, be sure to access elements in a fixed order like, start to end or vice versa. 
## However big an array may be, its elements are always stored in contiguous memory locations.
## In C, there is no check to see if subscript exceeds the size of the array. Data entered with a subscript exceeding the array size will simply be placed in memory outside the array. This can lead to errors and for worse, there is no error message to warn you
## "No matter how much time you have spent with pointers you would always find some applications of it what would leave you guessing"
