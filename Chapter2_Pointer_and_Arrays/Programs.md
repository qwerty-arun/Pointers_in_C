# Prgm-31
```
#include <stdio.h>
int main()
{
	int arr[3][3][3];
	printf("\n%u %u %u",arr,arr+1,arr+2);
	printf("\n%u %u %u",arr[0],arr[0]+1,arr[1]);
	printf("\n%u %u %u",arr[1][1],arr[1][0]+1,arr[0][1]);
}
```
## Output of Prgm-31
```
3757839504 3757839540 3757839576
3757839504 3757839516 3757839540
3757839552 3757839544 3757839516
```
## If we pass name of a 1D array  to a function it decays into a pointer to an int. If we pass name of a 2D array of integers to a function, it decays into a pointer to an array and not a pointer to a pointer.
## char **str , char *str[], char str[][] are not the same declarations. 
# Prgm-30
```
#include <stdio.h>
int main()
{
	char arr[]="Aura";
	char *ptr = "Aura";
	arr="Newstr";
	ptr="Huh";
	printf("\n%c %c",arr[3],ptr[3]);
}
```
## The above program gives an error because we can assign a new string to a pointer but not to an array.
## Whenever mentioning the array name gives its base address it is said that the array has decayed into a pointer. This doesn't take place in two situations: 1) When array name is used with `sizeof` operator. 2) When array name is an operand of the & operator.
## Even though, arr and &arr give the same address, they are different. `arr` gives adddress of the first int wheras `&arr` gives the address of array of ints.
## char a[] and char *a are treated as same by compiler when using them as formal parameters while defining function.
# Prgm-29
```
#include <stdio.h>
int main()
{
	static int a[3][3]= {
			2,4,3,
			6,8,5,
			3,5,1
			};
	static int *ptr[3] = {a[0],a[1],a[2]};
	int **ptr1=ptr;
	int i;

	printf("\n");
	for(i=0;i<=2;i++)
		printf("%d ",*ptr[i]);

	printf("\n");
	for(i=0;i<=2;i++)
		printf("%d ",*a[i]);

	printf("\n");
	for(i=0;i<=2;i++)
	{
		printf("%d ",**ptr1);
		ptr1++;
	}
}
```
## Output of Prgm-29
```
2 6 3
2 6 3
2 6 3
```
# Prgm-28
```
#include <stdio.h>
int main()
{
	static int a[] = {0,1,2,3,4};
	static int *p[] = {a,a+1,a+2,a+3,a+4};
	
	int **ptr=p;

	**ptr++;
	printf("\n%d %d %d",ptr-p,*ptr-a,**ptr);

	*++*ptr;
	printf("\n%d %d %d",ptr-p,*ptr-a,**ptr);

	++**ptr;
	printf("\n%d %d %d",ptr-p,*ptr-a,**ptr);
}
```
## Output of Prgm-28
```
1 1 1
1 2 2
1 2 3
Explanation: **ptr++ increments the pointer.
			So the first printf prints 1 1 1
	
			*++*ptr is evaluated as*(++(*ptr)) increments the value at ptr to next one. Now p[1] and p[2] will be same
			Note that ptr itself is not incremented so its is still p+1.
			
			++**ptr is evaluated as ++(*(*ptr)) and 2 is incremented to 3
			ptr is still p+1
			*ptr-a will be a+2-a which is 2
			**ptr will be 3 now.
```
# Prgm-27
```
#include <stdio.h>
int main()
{
	static int a[] = {0,1,2,3,4};
	static int *p[] = {a,a+1,a+2,a+3,a+4};
	
	int **ptr=p;

	ptr++;
	printf("\n%d %d %d",ptr-p,*ptr-a,**ptr);

	*ptr++;
	printf("\n%d %d %d",ptr-p,*ptr-a,**ptr);

	*++ptr;
	printf("\n%d %d %d",ptr-p,*ptr-a,**ptr);

	++*ptr;
	printf("\n%d %d %d",ptr-p,*ptr-a,**ptr);
}
```
## Output of Prgm-27
```
1 1 1
2 2 2 
3 3 3
3 4 4
Explanation: ptr++ will point to next integer pointer in the array p[].
	Now ptr will contain the address of p+1. Therefore ptr-p will give us p+1-p which is 1.
	*ptr will give us &a[1] and then *ptr-a will give us &a[1]-&a[0] which is again 1.
	**ptr will yield 1.

	*ptr++ will increment the pointer. 
	ptr-p will give us p+2-p which is 2.
	*ptr-a will give us a+2-a which is 2.
	**ptr will give us a[2] which is 2.

	In *++ptr, ptr is incremented and then the value at this address is obtained. Similarly, the output will be 3 3 3

	In ++*ptr, the value at the ptr is incremented which is a+3 incrementing to a+4.
	ptr-p will give us the same 3.
	*ptr-a will be a+4-a which will be 4.
	**ptr will give us a[4] which is 4 again.
```
## a is the base address of a[], *a will be '0'.
## p will the base address of p[], *p will be 'a' or base address of a[], **p will give us '0' or a[0]
## ptr will hold the base address of p[], *ptr will be &a[0], and **ptr will give us '0' or a[0]
# Prgm-26
```
int main()
{
	static int a[] = {0,1,2,3,4};
	static int *p[] = {a,a+1,a+2,a+3,a+4};
	int **ptr=p;
	printf("\n%u %d",a,*a);
	printf("\n%u %u %d",p,*p,**p);
	printf("\n%u %u %d",ptr,*ptr,**ptr);
}
```
## Output of Prgm-26
```
119775280 0
119775312 119775280 0
119775312 119775280 0
```
## But what is ptr[-i]? Its nothing but *(ptr-i), as 'i' increments  we access elements from the end of the array
# Prgm-25
```
#include <stdio.h>
int main()
{
	int arr[]={1,2,3,4,5};
	int i,*ptr;
	for(ptr=arr+4,i=0;i<=4;i++)
		printf("%d ",ptr[-i]);
}
```
## Output of Prgm-25
```
5 4 3 2 1
```
# Prgm-24
```
#include <stdio.h>
int main()
{
	int arr[]={1,2,3,4,5};
	int *ptr;
	for(ptr=arr+4;ptr>=arr;ptr--)
		printf("%d ",arr[ptr-arr]);
}
```
## Output of Prgm-24
```
5 4 3 2 1
```
## `ptr+i <= arr+4`. In this expression, '+' enjoys a higher priority than <=. Therefore, `Ptr+i` and `arr+4` are performed and then the `<=` goes to work.  
# Prgm-23
```
#include <stdio.h>
int main()
{
	int arr[]={1,2,3,4,5};
	int i,*ptr;
	for(ptr=arr,i=0;ptr+i<=arr+4;ptr++,i++)
		printf("%d ",*(ptr+i));
}
```
## Output of Prgm-23
```
1 3 5
```
# Prgm-22
```
#include <stdio.h>
int main()
{
	int arr[]={1,2,3,4,5};
	int i,*ptr;
	for(ptr=&arr[0],i=0;i<=4;i++)
}
```
## Output is the array
# Prgm-21
```
#include <stdio.h>
int main()
{
	int arr[]={1,2,3,4,5};
	int *ptr;
	for(ptr=&arr[0];ptr<=&arr[4];ptr++)
		printf("%d ",*ptr);
}
```
## Output is the array
# Prgm-20
```
#include <stdio.h>
void f(int *y);
int main()
{
	int a[]={1,2,3,4,5};
	int i;
	f(a);
	for(i=0;i<=4;i++)
		printf("%d ",a[i]);
}

void f(int *y)
{
	int i;
	for(i=0;i<=4;i++)
	{
		*y=*y+1;
		y++;
	}
}
```
## Output of Prgm-20
```
2 3 4 5 6
```
## a[i], *(a+i), *(i+a) and i[a] all refer to the ith element fo the base address if a is a 1D array
## Therefore, *(a+i) = a[i] + i[a] will double the elements of the array.
# Prgm-19
```
#include <stdio.h>
void fun(int **p);
int main()
{
	int a[2][3][4]=
	{
		{
		1,2,3,4,
		5,6,7,8,
		9,0,1,5
		},
		{
		4,9,10,8,
		1,9,7,3,
		0,5,7,1
		}
	};
	int i,j,k;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<4;k++)
			{
				printf("%d ",*(*(*(a+i)+j)+k));
			}
			printf("\n");
		}
			printf("\n");
	}
}
```
## Output of Prgm-19
```
Prints the array.
To remember: a[i][j][k] = *(*(*(a+i)+j)+k)
Also: a,*a,**a will all give the base address
```
# Prgm-18
```
#include <stdio.h>
void fun(int **p);
int main()
{
	int a[3][4]={
 		1,2,3,4,
		5,6,7,8,
		9,0,1,5
	};
	printf("%u\n",a);
	int *ptr;
	ptr=&a[0][0];
	fun(&ptr);
}

void fun(int **p)
{
	printf("%u\n",p);
	printf("%u\n",*p);
	printf("%d",**p);
}
```
## Output of Prgm-17
```
2133768496
2133768488
2133768496
1
Why?
Well 'p' holds the address of the pointer 'ptr' and *p holds the address of a[0][0].
```
# Prgm-17
```
#include <stdio.h>
int main()
{
	int a[3][4]={
		1,2,3,4,
		5,6,7,8,
		9,0,1,5
	};
	printf("\na: %u",a);
	printf("\na+1: %u &a+1: %u\n",a+1,&a+1);
}
```
## Output of Prgm-17
```
a: 1784710912
a+1: 1784710928 &a+1: 1784710960
Explanation: 'a+1' gives address of next 1D array whereas '&a+1' gives address of next 2D array
```
# Prgm-16
```
#include <stdio.h>
int main()
{
	int a[]={1,2,3,4,5};
	printf("%u %u\n",a,&a);
	printf("%u %u\n",a+1,&a+1);
}
```
## Output of Prgm-16
```
1472112416 1472112416
1472112420 1472112436
Explanation: Both 'a' and '&a' gives the base address. However, a+1 gives address of next integer and &a+1 gives address of next array of 5 integers.
```
# Prgm-15
```
#include <stdio.h>
#include <string.h>
int main()
{
	char a[]="Visual C++";
	char *b="Visual C++";
	printf("\n%d %d",sizeof(a),sizeof(b));
	printf("\n%d %d",sizeof(*a),sizeof(*b));
}
```
## Output of Prgm-15
```
11 8 Why 8? 11 is understandable because of '\0' at the end of a[].
1 1
Is it because it takes only one string which is 'Visual' and then '\0' but where did the extra byte come from? Turns out this wrong way to calculate.
Correct Explanation: The size of a pointer is typically 4 bytes on a 32-bit system or 8 bytes on a 64-bit system. Assuming we are on a 64-bit system, sizeof(b) will return 8 bytes.
```
# Prgm-14
```
#include <stdio.h>
#include <string.h>
int main()
{
	char a[]="Visual C++";
	char *b="Visual C++";
	printf("\n%d %d",strlen(a),strlen(b));
	printf("\n%d %d",sizeof(*a),sizeof(*b));
}
```
## Output of Prgm-14
```
10 10
1 1
*a and *b both yield a character 'V', whose size is one byte.
```
# Prgm-13
```
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int b[]= {10,20,30,40,50};
	int i,*k;
	k=&b[4]-4;
	for(i=0;i<=4;i++)
	{
		printf("%d ",*k);
		k++;
	}
}
```
## Output of Prgm-13
```
10 20 30 40 50
At first it looks like `&b[4]-4` will point to 4th element of array which is '40' but it actually means address of integer which is 4 integers to the left of the integer whose address if `&b[4]`.
Remember its the same as pointer arithmetic like `b+1` which points to the next element.
```
# Prgm-12
```
#include <stdio.h>
int main()
{
	int a[]={10,20,30,40,50};
	int j;
	for(j=0;j<5;j++)
	{
		printf("\n%d",*a);
		a++;
	}
	return 0;
}
```
## Output of Prgm-12
```
error: cannot increment value of type 'int[5]'
                a++;
                ~^
```
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
	display(**a,2,3,4);
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
	display(*a,3,4);
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
		p=*(q+i);
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
