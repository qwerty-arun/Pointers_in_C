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
There is a difference of 3 in address. There should have been an error because pointer arithmetic on void* is not allowed unless the void pointer is appropriately typecasted. Actually some compilers do allow thisc gcc is one of them.
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
