#include <stdio.h>
int main()
{
	static int a[3][3][2]={
				{
				1,2,
				3,4,
				5,6
				},
				{
				3,4,
				1,2,
				5,6
				},
				{
				5,6,
				3,4,
				1,2
				}
				};
	printf("\n%d %d %d ",*(*(a[0]+2)+1),*(*(*(a+2)+1)+1),*(a[1][2]+1));
}
