#include <stdio.h>

struct a 
{
    char ch[7];
    char *str;
};

struct b 
{
    char *c;
    struct a ss1;
};

int main()
{
    struct b s2 = {"Bengaluru","Indore","Mizoram"};
    printf("\n%s %s",s2.c,s2.ss1.str);
    printf("\n%s %s",++s2.c,++s2.ss1.str);
}
