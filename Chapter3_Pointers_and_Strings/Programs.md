## *(ch+i)=ASCII is the same as ch[i]=ASCII, when you print using %s, the characters are printed. Don't forget to terminate using *(char+i)='\0'
## `printf(5+"CodingOnLinux")` will print "gOnLinux". Explanation: base address + 5 is being passed. So address of 'g' is indeed 'base+5', so characters from g onwards are printed.
# Prgm-14
```
#include <stdio.h>
int main()
{
	char s[]="Fullerene";
	printf("\n%d",*(s+strlen(s)));
}
```
## Output of Prgm-14
```
0 is printed indicating `\0` at the end of the string.
Try subtracting different number like 1,2,3 etc. and corresponding ASCII values of the characters are printed.
```
# Prgm-13: Overcoming the limitation of Array of Pointers to strings
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *names[5];
	char str[10];
	int i;
	for(i=0;i<5;i++)
	{
		printf("\nEnter a string: ");
		scanf("%s",str);	
		names[i]=(char*)malloc(strlen(str));
		strcpy(names[i],str); 
	}
	printf("\nThe names are:");
	for(i=0;i<5;i++)
	{
		printf("\n%s",names[i]);
	free(names[i]);
	}
}
```
## Remarks on Prgm-13: We used malloc to allocate memory to each pointer in the array of pointers to strings. Then we free the allocated memory one by one after printing the names.
## What's the solution? First we need to allocate space using malloc and then store the address returned by malloc() in the array of pointers to strings.
## Why doesn't it work? Because when we are declaring the array it is containing garbage values. And it would be wrong to send to scanf() as the addresses where it should keep the strings received from the keyboard.
## When we are using a 2D array of characters, we can either intialisw the strings where we are declaring the array, or receive the strings using scanf(). However using array of pointers to strings, we can initialise the strings at the place where we are declaring the array, but can't receive using scanf().
## Our own swap function would look like this:
```
swap(char **s1,char **s2)
{
	char *t;
	t=*s1;
	*s1=*s2;
	*s2=t;
}
```
# Prgm-12: Array of Pointers to Strings
```
#include <stdio.h>
#include <string.h>
int main()
{
	char *names[]={
		"arun",
		"ram",
		"dhruv",
		"ganesh",
		"dinesh"
	};
	char *temp;
	printf("\nOriginal: %s %s",names[2],names[3]);
	temp=names[2];
	names[2]=names[3];
	names[3]=temp;
	printf("\n=New %s %s",names[2],names[3]);
}
```
## Remarks onn Prgm-12: The program exchanges the names dhruv and ganesh.
# Prgm-11: Two Dimensional Array of Characters
```
#include <stdio.h>
#include <string.h>

int main()
{
	 char names[5][10];
	printf("\nEnter 5 name:");
	for(int i=0;i<5;i++)
	{
		scanf("%s",&names[i][0]); //even names[i] works fine
	}
	printf("\nThe 5 names which you entered are:");
	for(int i=0;i<5;i++)
	{
		printf("\n%s",names[i]);
	}
}
```
## Remarks on Prgm-11: Enters 5 names and displays them
# Prgm-10
```
#include <stdio.h>
#include <string.h>

int main()
{
	 char names[5][10]={
			"ryan",
		"shreyas",
		"gopal",
		"aakash",
		"ram"
	};
	char name[10];
	int a,flag;
	printf("\nEnter your name:");
	scanf("%s",name);
	for(int i=0;i<5;i++)
	{
		a=strcmp(&names[i][0],name);	
		if(a==0)
		{
			printf("\nFound!");
			flag=1;
			break;
		}
	}

	if(flag==0)
	{
		printf("\nNot found!");
	}
}
```
## Trying to assign a const string to non-const string yields the warning: Assigning to `char*` from `const char*` discards qualifiers.
# Prgm-9
```
#include <stdio.h>
int main()
{
	const char *fun();
	const char *p;
	p=fun();
	*p='A';
	printf("\n%s",p);
	return 0;
}

const char* fun()
{
	return "Code";
}
```
## Remarks on Prgm-9
```
fun() is returning a constant string, we can't modify it using 'p'. Further more, main() can't assign the return value to a pointer to a non const string and main() can pass the return value to a function that is expecting a pointer to a non-const string. 
```
## The program below illustrates the ideas of const keyword
# Prgm-8
```
#include <stdio.h>
int main()
{
	char *p="Hello"; //pointer is variable and even string
	*p='M';
	p="Bye";

	char const *q="Hello"; //string is constant pointer is not
	*q='M';//error
	q="Bye";

	const char *r="Hello"; //string is constant pointer is not
	*r='M';//error
	r="Bye";

	char *const s="Hello"; //pointer is constant string is not
	*s='M';
	s="Bye";//error

	const char *const t="Hello"; //string is constant and even pointer
	*t='M';// error 
	t="Bye";//error
	return 0;
}
```
## `#define` used inside main can also be accessed in other functions, it is a pre-processor, so its global even if it is defined inside the main function.
## Why using const is a better idea than #define? Well we can control the scope of const variables but not of #define.
## We cannot assign a string to another, whereas, we can assign a char pointer to another char pointer.
## The program below doesn't use malloc but the downside is we need to know array size beforehand.
# Prgm-7
```
#include <stdio.h>

int xstrlen(char *s);
char* xstrcpy(char *dest, const char *src);
char* xstrcat(char *dest, const char *src);
int xstrcmp(char *s1,char *s2);
int main()
{
    char arr[] = "Pointerzzz";
    int len1 = xstrlen(arr);
    int len2 = xstrlen("Stringswithpointers");

    printf("\nstring = %s length= %d", arr, len1);
    printf("\nstring = %s length= %d", "Stringswithpointers", len2);

    // Declare a destination array with enough space for the copied string
    char str[50];  // Make sure this is large enough to hold the copied string
    xstrcpy(str, arr);
    printf("\nCopied string = %s length= %d", str, xstrlen(str));

    // Declare a destination array with enough space for the concatenated string
    char cat_String[50];  // Make sure this is large enough for concatenation
    xstrcpy(cat_String, "Arun");
    xstrcat(cat_String, "isCoding");
    printf("\nConcatenated string = %s length= %d", cat_String, xstrlen(cat_String));
    char str1[10]="rat";
    char str2[10]="sat";
    int cmp=xstrcmp(str1,str2);
    printf("\nCompare value: %d",cmp);
    return 0;
}

int xstrlen(char *s)
{
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

char* xstrcpy(char *dest, const char *src)
{
    char *original_dest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Null-terminate the destination string
    return original_dest;
}

char* xstrcat(char *dest, const char *src)
{
    char *original_dest = dest;

    // Move dest to the end of the string
    while (*dest != '\0') {
        dest++;
    }

    // Copy src to the end of dest
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Null-terminate the concatenated string
    return original_dest;
}
int xstrcmp(char *s1,char *s2)
{
    while(*s1 == *s2)
    {
        if(*s1=='\0')
            return 0;
        s1++;
        s2++;
    }
    return(*s1-*s2);
}
```
## What if I didn't wanna use malloc in the below program? Well there is a way but we use arrays of large enough size instead.
# Prgm-6
```
#include <stdio.h>
#include <stdlib.h>

int xstrlen(char *s);
char* xstrcpy(char *dest, const char *src);
char* xstrcat(char *dest, const char *src);

int main()
{
    char arr[] = "Pointerzzz";
    int len1 = xstrlen(arr);
    int len2 = xstrlen("Stringswithpointers");

    printf("\nstring = %s length= %d", arr, len1);
    printf("\nstring = %s length= %d", "stringswithpointers", len2);

    char *str = (char*)malloc((len1 + 1) * sizeof(char));
    if (str == NULL) {
        printf("\nMemory allocation failed");
        return 1;
    }
    str = xstrcpy(str, arr);
    printf("\nCopied string = %s length= %d", str, xstrlen(str));

    char *cat_String = (char*)malloc((xstrlen("Arun") + xstrlen("isCoding") + 1) * sizeof(char));
    if (cat_String == NULL) {
        printf("\nMemory allocation failed");
        free(str);  // Clean up allocated memory before exiting
        return 1;
    }
    cat_String = xstrcpy(cat_String, "Arun");
    cat_String = xstrcat(cat_String, "isCoding");
    printf("\nConcatenated string = %s length= %d", cat_String, xstrlen(cat_String));

    free(str);
    free(cat_String);

    return 0;
}

int xstrlen(char *s)
{
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

char* xstrcpy(char *dest, const char *src)
{
    char *original_dest = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Null-terminate the destination string
    return original_dest;
}

char* xstrcat(char *dest, const char *src)
{
    char *original_dest = dest;
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';  // Null-terminate the concatenated string
    return original_dest;
}
```
## Output of Prgm-6
```
string = Pointerzzz length= 10
string = stringswithpointers length= 19
Copied string = Pointerzzz length= 10
Concatenated string = ArunisCoding length= 12
```
# Prgm-5
```
#include <stdio.h>
int xstrlen(char *);
char* xstrcpy(char *,char *);
char *xstrcat(char *,char *);
int main()
{
	char arr[]="Pointerzzz";
	int len1,len2;
	len1=xstrlen(arr);
	len2=xstrlen("Stringswithpointers");
	printf("\nstring = %s length= %d",arr,len1);
	printf("\nstring = %s length= %d","stringswithpointers",len2);
	char *str;
	str=xstrcpy(str,arr);
	printf("\nstring = %s length= %d",str,xstrlen(str));
	char * cat_String=xstrcat("Arun\0","isCoding\0");
	printf("\nstring = %s length= %d",cat_String,xstrlen(cat_String));
}

int xstrlen(char *c)
{
	int length=0;
	while(*c!='\0')
	{
		length++;
		c++;
	}
	return length;
}

char* xstrcpy(char *s,char *t)
{
	while(*t!='\0')
	{
		*s=*t;
		s++;
		t++;
	}
	*s='\0';
	return s;
}

char *xstrcat(char *s1,char *s2)
{
	char *final_str;
	while(*s1)
	{
		*final_str=*s1;
		final_str++;
		s1++;
	}
	while(*s2)
	{
		*final_str=*s2;
		final_str++;
		s2++;
	}
	*final_str='\0';
	return final_str;
}
```
## Output of Prgm-5
```
string = Pointerzzz length= 10
Segmentation fault (core dumped)
What is the problem here:

The errors in the code are mainly due to incorrect memory handling and assignment. Here’s what needs to be fixed:

Uninitialized Pointers:
In the xstrcpy and xstrcat functions, you are trying to copy strings into pointers (str and final_str), but these pointers are not initialized with any valid memory locations. As a result, they point to random memory locations, which leads to undefined behavior.

Returning incorrect pointers:
In xstrcpy, you return the pointer after the copying process has finished. Instead, you should return the original pointer to the beginning of the destination string.
Similarly, in xstrcat, the final_str should point to a memory location that can hold the concatenated string. Also, you should return the original pointer to the start of the concatenated string.
```

# Prgm-4
```
#include <stdio.h>
#include <string.h>
int main()
{
	char str1[20]="Bamboozled";
	char str2[]="Champ";
	char str3[20];
	int l,k;
	l=strlen(str1);
	printf("\nSizeof str1[] = %d",sizeof(str1));
	printf("\nSizeof str2[] = %d",sizeof(str2));
	printf("\nSizeof str3[] = %d",sizeof(str3));
	printf("\nLength of string str1= %d",l);
	l=strlen(str2);
	printf("\nLength of string str2= %d",l);
	l=strlen(str3);
	printf("\nLength of string str3= %d",l);
	
	char str4[20]="";
	printf("\nLength of string str4= %d",strlen(str4));
	printf("\nSizeof str4[] = %d",sizeof(str4));
	printf("\nSizeof("")= %d",sizeof(""));

	strcpy(str3,str1);
	printf("\nAfter copying, String st3 = %s",str3);
	printf("\nLength of string str3= %d",strlen(str3));

	k=strcmp(str1,str2);
	printf("\nComparing str1 and str2,k = %d",k);

	k=strcmp(str3,str1);
	printf("\nComparing str3 and str1,k = %d",k);

	strcat(str1,str2);
	printf("\nConcatinating str1 with str2 = %s",str1);
	printf("\nLength of string str1= %d",strlen(str1));
	return 0;
}
```
## Output of Prgm-4
```
Sizeof str1[] = 20
Sizeof str2[] = 6
Sizeof str3[] = 20
Length of string str1= 10
Length of string str2= 5
Length of string str3= 0
Length of string str4= 0
Sizeof str4[] = 20
Sizeof()= 1
After copying, String st3 = Bamboozled
Length of string str3= 10
Comparing str1 and str2,k = -1
Comparing str3 and str1,k = 0
Concatinating str1 with str2 = BamboozledChamp
Length of string str1= 15
```
## Standard Library String Functions: strlen(), strcat(), strcmp(), strcpy()
# Prgm-3
```
#include <stdio.h>
int main()
{
	char name[]="Robert Green";
	printf("%s\n",name);
	char str[8];
	scanf("%s",str);
	printf("\n%s",str);
	return 0;
}
```
## Output of Prgm-3
```
Robert Green
Robert Green -> entered value
Robert
```
# Prgm-2
```
#include <stdio.h>
int main()
{
	char name[]="Arun";
	char *c=name;
	while(*c!='\0')
	{
		printf("\n%c",*c);
		c++;
	}
	return 0;
}
```
## Output of Prgm-2
```
A
r
u
n
```
# Prgm-1
```
#include <stdio.h>
int main()
{
	char name[]="Arun";
	int i;
	i=0;
	while(name[i])
	{
		printf("\n%c %c %c %c",name[i],*(name+i),*(i+name),i[name]);
		i++;
	}
	return 0;
}
```
## Output of Prgm-1
```
A A A A
r r r r
u u u u
n n n n
```
## `\0` and `0` are not the same. ASCII value of `\0` is 0, whereas ASCII value of `0` is 48.
## The null character is important because it is the only way the functions that work with string can know where a string ends.
## In fact, a string not terminated by `\0` is not really a string, but merely a collection of characters.
# "The likelihood of a program crashing is in direct proportion to the number of pointers used in it."
