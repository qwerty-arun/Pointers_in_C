## If we try something like *q+5, it will show an error. It says "invalid operands to binary expression ('struct general' and 'int')" 
# Prgm-6
```
# include <stdio.h>
int main()
{
	struct general 
	{
		char a; 
		double d;
	};
	struct general p[5][5];
	struct general *q;
	q=&p[0][0];
	p[0][0].a='0';
	p[0][0].d=3.14;
	(*(*(p+1)+1)).a='1';
	(*(*(p+1)+1)).d=2.718;
	printf("\n%c %lf",p[0][0].a,p[0][0].d);
	printf("\n%c %lf",p[1][1].a,p[1][1].d);
	printf("\n%c %lf",(*q).a,(*q).d);
}
```
## Output of Prgm-6
```
0 3.140000
1 2.718000
0 3.140000
```
# Prgm-5
```
# include <stdio.h>
int main()
{
	struct general 
	{
		char a; 
		double d;
	};
	struct general p[5][5];
	struct general *q[5][5];
	p[0][0].a='0';
	p[0][0].d=3.14;
	(*(*(p+1)+1)).a='1'; //same as p[1][1].a='1';
	(*(*(p+1)+1)).d=2.718;
	printf("\n%c %lf",p[0][0].a,p[0][0].d);
	printf("\n%c %lf",p[1][1].a,p[1][1].d);
}
```
## Output of Prgm-5
```
0 3.140000
1 2.718000
```
## What does `struct general p[5][5] mean?` Well, it is valid. The size of `p` will be 400 (16*25). The same for the pointers will be 200.
# Prgm-4
```
# include <stdio.h>
int main()
{
	struct general 
	{
		char a; 
		double d;
	};
	struct general p[5];
	struct general *q[5];
	printf("\nSize of array of structure: %d",sizeof(p));
	printf("\nSize of array of pointers to structure: %d",sizeof(q));
}
```
## Output of Prgm-4
```
Size of array of structure: 80
Size of array of pointers to structure: 40
```
## If you add a pointer to the same struct, then the size will be 32, indicating that the pointer size is 8.
# Prgm-3
```
# include <stdio.h>
int main()
{
	struct general 
	{
		int age;
		float huh;
		double d;
		char a; 
	};
	struct general p1;
	printf("\nSize of p1: %d",sizeof(p1));
}
```
## Output of Prgm-3
```
24
It should have been 4+4+8+1=17 right? Well this the concept of structure padding.
```
# Prgm-2
```
# include <stdio.h>
int main()
{
	struct player
	{
		char name[20];
		int age;
	};
	struct player p1;
	printf("\naddress of p1: %u",&p1);
	printf("\naddress of name: %u",&(p1.name));
	printf("\naddress of age: %u",&(p1.age));
	printf("\nSize of p1: %d",sizeof(p1));
}
```
## Output of Prgm-2
```
address of p1: 1813065416
address of name: 1813065416
address of age: 1813065436
Size of p1: 24
```
## For structure pointers, we use '->' to access the structure elements.
## ptr-> name is the same as (*ptr).name
# Prgm-1: Structure pointers
```
# include <stdio.h>
int main()
{
	struct player
	{
		char name[20];
		int age;
	};
	struct player p1={"Dhruv",26};
	struct player *ptr;
	ptr=&p1;
	printf("\n%s %d",p1.name,p1.age);
	printf("\n%s %d",ptr->name,ptr->age);
}
```
## Structure variables can be passed to function. Even individual elements or the structure itself. If we need to we pass address of structure elements or the structure itself.
```
struct college
{
    char address[20];
    char name[20];
};
struct student
{
    char name[20];
    char ID[10];
    struct college c1;
};
Accessing them: struct student s1; s1.c1.address=" ";
```
## Nested Structures are possible
## Value of one structure variable can be assigned to another structure variable of the same type. p2=p1; is valid.
## All of the below are correct
```
struct 
{
    char name[20];
    int age;
}p1={"Dhruv",30};
```
```
struct player
{
    char name[20];
    int age;
}p1={"Dhruv",30};
```
```
struct player
{
    char name[20];
    int age;
};
struct player p1={"Dhruv",30};
```
## struct account a[10]; is an array of 10 structures.
## It is mandatory to use 'struct' keyword while declaration. If we don't want to, then we can use typedef keyword where the struct itself is defined.
## '.' operator is used to access elements
# An expert C Programmer is one who avoids all errors except those related with pointers.

