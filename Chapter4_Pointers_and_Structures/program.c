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
