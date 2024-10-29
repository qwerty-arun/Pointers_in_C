#include <stdio.h>
#include <stdlib.h>

struct a
{
    char name[10];
    char address[20];
};
void print(struct a *aa);
int main()
{
    struct a aa ={
    "Arun","Bengaluru"
    };
    print(&aa);
}
void print(struct a *aa)
{
    printf("\n%s",aa->name);
    printf("\n%s",aa->address);
}

