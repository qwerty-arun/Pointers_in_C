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
