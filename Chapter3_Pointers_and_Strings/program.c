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
