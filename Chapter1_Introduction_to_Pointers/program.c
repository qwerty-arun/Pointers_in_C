#include <stdio.h>
int main()
{
	float *code(float *);
	float p=25.5,*q;
	q=&p;
	printf("Before call=%u\n",q);
	q=code(&p);
	printf("Before call=%u",q);
}
float *code(float *r)
{
	r=r+1;
	return r;
}
