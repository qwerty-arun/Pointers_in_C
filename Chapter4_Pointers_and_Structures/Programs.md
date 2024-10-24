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

