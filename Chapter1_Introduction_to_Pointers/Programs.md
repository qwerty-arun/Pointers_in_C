# Prgm-21
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
## Output of Prgm-21
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
## Each row of a 2D array can be thought as a 1D array. This is a very powerful way to access array elements.
## Two dimensional array is nothing but a collection of a number of a 1D arrays placed one after another
## `*(arr+i)` is for accessing and is the same as arr[i]
## `&arr[i]` and `arr+i` are the same. Which one is better? Well accessing array elements using pointers is always faster than accessing them by subscripts. But while using pointers, be sure to access elements in a fixed order like, start to end or vice versa. 
## However big an array may be, its elements are always stored in contiguous memory locations.
## In C, there is no check to see if subscript exceeds the size of the array. Data entered with a subscript exceeding the array size will simply be placed in memory outside the array. This can lead to errors and for worse, there is no error message to warn you
## "No matter how much time you have spent with pointers you would always find some applications of it what would leave you guessing"
# Prgm-20
```
#include <stdio.h>
int main()
{
	int i=10;
	printf("\n Value of i=%d Address of i=%u",i,&i);
	&i=7800;
	printf("\n New Value of i=%d New Address of i=%u", i,&i);
}
```
## Results of Prgm-20
```
program.c:6:11: error: lvalue required as left operand of assignment
    6 |         &i=7800;
    
    If we change the code slightly:-
program.c:6:9: error: invalid type argument of unary ‘*’ (have ‘int’)
    6 |         *i=7800;
      |         ^~
```
## int *b = a * 2 -> If 'a' is a pointer to int, then we have `int` and `int*` as operands, we can't perform this type of arithmetic
# Prgm-19
```
#include <stdio.h>
int main()
{
	char *c = 4000;
	int *i = 4000;
	float *f = 4000;
	long *l = 4000;
	double *d = 4000;
	printf("\n c=%u , c+1 = %u",c,c+1);
	printf("\n i=%u , i+1 = %u",i,i+1);
	printf("\n f=%u , f+1 = %u",f,f+1);
	printf("\n l=%u , l+1 = %u",l,l+1);
	printf("\n d=%u , d+1 = %u",d,d+1);
}
```
## Results of Prgm-19
```
 c=4000 , c+1 = 4001
 i=4000 , i+1 = 4004
 f=4000 , f+1 = 4004
 l=4000 , l+1 = 4008
 d=4000 , d+1 = 4008
```
## Return addressing of a local variable results in an error
## **ptr***ptr will compute the square of the value stored in ptr
# Prgm-18
```
#include <stdio.h>
void exchange(int **c,int **d);
void swap(int *c, int *d);
int main()
{ 
	int c=10,d=20;
	printf("Before swap, c=%d d=%d\n",c,d);
	swap(&c,&d);
	printf("After swap, c=%d d=%d\n",c,d);
}

void swap(int *c, int *d)
{
	exchange(&c,&d);	
}

void exchange(int **cc,int **dd)
{
	int t;
	t=**cc;
	**cc=**dd;
	**dd=t;
}
```
### Results of Prgm-18
```
Before swap, c=10 d=20
After swap, c=20 d=10
```
# Prgm-17
```
#include <stdio.h>
void change(int c,int d);
void swap(int c, int d);
int main()
{ 
	int c=10,d=20;
	printf("We are in main().. \n");
	printf("Address of c=%u Address of d=%u\n",&c,&d);
	printf("\nBefore Swap(), c=%d d=%d\n",c,d);
	swap(c,d);
	printf("Back to main()..\n");
	printf("\n After swap(),c=%d,d=%d",c,d);
}

void swap(int c, int d)
{
	printf("We are in swap()..\n");
	printf("Address of c=%u Address of d=%u\n",&c,&d);
	printf("\nBefore Swap(), c=%d d=%d\n",c,d);
	change(c,d);
	printf("Back to swap()...\n");
	printf("After change(), c=%d, d=%d\n",c,d);
}

void change(int c,int d)
{
	int t;
	printf("We are in change()...\n");
	printf("Address of c=%u Address of d=%u\n",&c,&d);
	printf("\nBefore interchanging, c=%d d=%d\n",c,d);
	t=c;
	c=d;
	d=t;
	printf("After interchanging, c=%d, d=%d\n",c,d);
}
```
### Results of Prgm-17
```
We are in main().. 
Address of c=1288288048 Address of d=1288288052

Before Swap(), c=10 d=20
We are in swap()..
Address of c=1288288028 Address of d=1288288024

Before Swap(), c=10 d=20
We are in change()...
Address of c=1288287980 Address of d=1288287976

Before interchanging, c=10 d=20
After interchanging, c=20, d=10
Back to swap()...
After change(), c=10, d=20
Back to main()..
After main(),c=10,d=20
We never really passed any pointer here, so the swap happened inside functions, when control comes back to main(), the local variable 'c' and 'd' have the same values '10' and '20' respectively. 
```
# Prgm-16
```
#include <stdio.h>
int main()
{ 
	char c,*cc;
	int i; float f;long l;
	c='Z'; i=15;l=7777;f=3.14;
	cc=&c;
	printf("c=%c cc=%p\n",*cc,cc);
	cc=&i;
	printf("c=%d cc=%p\n",*cc,cc);
	cc=&l;
	printf("c=%ld cc=%p\n",*cc,cc);
	cc=&f;
	printf("c=%f cc=%p\n",*cc,cc);
}
```
### Results of Prgm-16
```
c=Z cc=0x7ffdd541b04f
c=15 cc=0x7ffdd541b050
c=97 cc=0x7ffdd541b058
c=0.000000 cc=0xffffffc3
```
## Learnings
- A null pointer is a pointer, which doesn't point anywhere. </br>
- A NULL macro is used to represent the null pointer in source code. It has a value 0 associated with it.</br>
- A null string is nothing but an empty string.</br>
- The ASCII NUL character has all its bits as 0 but doesn't have any relationship with the null pointer.</br>
- A NULL pointer is not the same as uninitialised pointer.</br>
- `int ***i` means 'i' is a pointer to a pointer to a pointer to an int.</br>
- `char ****k` means 'k' is a pointer to a pointer to a pointer to a pointer to a char.</br>
- `void f(int *,char*)` stands for 'f' is a function which receives an int pointer and a char pointer and returns nothing.</br>
- `float *g(float*,float**)` means 'g' is a function which receives a float pointer and a pointer to a float pointer and returns a float pointer.</br>
- `int **h(float *,char **)` 'h'receives a float pointer and a pointer to a char pointer and int turn returns a pointer to an int pointer.</br>
# Prgm-15
```
#include <stdio.h>
int main()
{
	int *p1,i=25;
	void *p2;
	p1=&i;
	p2=&i;
	p1=p2;
	p2=p1;
}
```
The above code won't show any error.
# Prgm-14
```
#include <stdio.h>
int main()
{
	int a[2] = { 1, 2 };
	void* ptr = &a;
	ptr = ptr + sizeof(int);
	printf("%d", *(int*)ptr);
	return 0;
}
```
### Output of Prgm-13
```
2
```
# Prgm-13
```
#include <stdio.h>
int main()
{
	int a = 10;
	void* ptr = &a;
	printf("%d", *(int*)ptr);
	return 0;
}
```
### Output of Prgm-13
```
10
We are type casting to int* and then dereferencing back to get the value.
```
# Prgm-12
```
#include <stdio.h>
int main()
{
	int a = 10;
	char b = 'x';

	void* p = &a;
	p = &b;
	printf("%c",*p);
}
```
### Output of Prgm-12
```
There will be an error because we are dereferencing a void pointer and thats not allowed.
```
## Learning: %p is used while handling pointers.
# Prgm-11
```
#include <stdio.h>
int main()
{
	float i=10,*j;
	void *k;
	j=k=&i;
	j++;
	k++;
	printf("%u %u",j,k);
}
```
### Output of Prgm-11
```
There is a difference of 3 in address. There should have been an error because pointer arithmetic on void* is not allowed unless the void pointer is appropriately typecasted. Actually some compilers do allow this and gcc is one of them.
```
# Prgm-10
```
#include <stdio.h>
int main()
{
	float i=10,*j;
	void *k;
	k=&i;
	j=k;
	printf("%f",*j);
}
```
### Output of Prgm-10
```
10.00000 
There is no error even though it looks like it should because, there is no need for typecasting while assigning the value to and from k because conversions are applied automatically when other pointer types are assigned to and from void*.
```
## Learning: *ptr++ increments the pointer and not the value pointed by it, whereas, ++*ptr increments the value being pointed to by ptr
# Prgm-9
```
#include <stdio.h>
int main()
{
	int i=10;
	int *ptr;
	ptr=&i;
	printf("%d\n",++*ptr);
	printf("%u\n",ptr);
	*ptr++;
	printf("%u\n",ptr);
	(*ptr)++;
	printf("%d\n",*ptr);
}
```
### Output of Prgm-9
```
11
106770460
106770464
-49914576 Of Course this will be a garbage value since ptr now points to prev address + 4
```
# Prgm-8
```
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
```
## Output of Prgm-8
```
342683476
21
21
22 Post increment is done here.
```
## Learnings: ++*ptr does the same job as (*ptr)++
# Prgm-7
```
#include <stdio.h>
int main()
{
	float *code(float *);
	float p=25.5,*q;
	q=&p;
	printf("Before call=%u\n",q);
	q=code(&p);
	printf("Before call=%u",q);
}
float *code(float *r)
{
	r=r+1;
	return r;
}
```
### Output of Prgm7
```
Before call=2152344508
Before call=2152344512
Every float is 4 bytes long. 
```
# Prgm-6
```
#include <stdio.h>
int check(int i);
int main ()
{
	int *c;
	c=check(10);
	printf("%u",c);
}

int check(int i) //int *check(int i) will produce no warnings
{
	int *p;
	p=&i;
	return p;
}
```
### Output of Prgm-5
```
Actually the error is called non portable pointer assignment in main. Just by declaring c as a pointer alone is not sufficient, all that ckech() can return is an integer.
warning: assignment to ‘int *’ from ‘int’ makes pointer from integer without a cast [-Wint-conversion]
    6 |         c=check(10)
   	warning: returning ‘int *’ from a function with return type ‘int’ makes integer from pointer without a cast [-Wint-conversion]
   14 |         return p;
```

# Prgm-5
```
#include <stdio.h>
int main ()
{
	float a=7.999999;
	float *b,*c;
	b=&a;
	c=b;
	printf("%u %u %u\n",&a,b,c);
	printf("%d %d %d %d",a,*(&a),*b,*c);
}
```
### Results of Prgm-5
```
2254392148 2254392148 2254392148
-1811692896 0 1 0
Explanation: a,*(&a),*b,*c all yield 7.9999, but when printed using %d, it creates a mess. So don't rely on printf() to truncate a float value to an integer or vice versa.
```
# Prgm-4
```
#include <stdio.h>
int main ()
{
	int a,b=5;
	a=b+NULL;
	printf("%d",a);
	printf("%d %d",sizeof(NULL),sizeof(""));
}
```
### Results of Prgm4
```
5 
8 This indicates that NULL needs 8 bytes.
1 Even though the string is empty, it will contain '\0' character.
```

# Prgm-3
```
#include <stdio.h>
int *fun();
int main()
{
	int *p;
	p=fun();
	printf("\n%u",p);
	printf("\n%d",*p);
}

int *fun()
{
	int i=20;
	return(&i);
}
```
### Results of Prgm3
```
Segmentation fault (Core Dumped)
Reason: This is because, when the control comes back from fun(),'i' dies. So even if we have its addreass in 'p', we can't access 'i' since it is already dead. If you want 'i' to survive and *p to give 20, then we need to use the 'static' keyword for 'i'.
```

# Prgm-2
```
#include <stdio.h>
int main()
{
	int i=54;
	float a=3.14;
	char *ii,*aa;

	ii=(char *)&i;
	aa=(char *)&a;
	printf("Address contained in ii= %u\n",ii);	
	printf("Address contained in aa= %u\n",aa);	
	printf("Value at the address contained in ii = %d\n",*ii);
	printf("Value at the address contained in aa = %d\n",*aa);
}
```

### Results of Prgm-2
```
Address contained in ii= 1897129152
Address contained in aa= 1897129156
Value at the address contained in ii = 54
Value at the address contained in aa = -61
```

# Prgm-1
```
#include <stdio.h>
int main()
{
	char c, *cc;
	int i, *ii;
	float a, *aa;
	
	c='A';
	i=54;
	a=3.14;
	cc=&c;
	ii=&i;
	aa=&a;
	printf("Address in cc= %u\n",cc);
	printf("Address in ii= %u\n",ii);
	printf("Address in aa= %u\n",aa);
	printf("Value of c= %c\n", *cc);
	printf("Value of i= %d\n", *ii);
	printf("Value of a= %f\n", *aa);
}
```
