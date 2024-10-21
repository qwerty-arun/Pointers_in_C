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
