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
