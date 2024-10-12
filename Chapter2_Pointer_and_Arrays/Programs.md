# Prgm-1
```
#include <stdio.h>
int main()
{
	int s[3][2]={{1000,12},{1004,16},{1008,45}};
	int i;
	for(i=0;i<4;i++)
	{
		printf("\n Address of %dth 1-D array =%u",i,s[i]);
		printf("\n First value of %dth 1-D array =%d",i,s[i][1]);
	}
	return 0;
}
```
## Output of Prgm-1
```
Address of 0th 1-D array =2748615056
 First value of 0th 1-D array =12
 Address of 1th 1-D array =2748615064
 First value of 1th 1-D array =16
 Address of 2th 1-D array =2748615072
 First value of 2th 1-D array =45
 Address of 3th 1-D array =2748615080
 First value of 3th 1-D array =0
```
# Key Learnings
## Each row of a 2D array can be thought as a 1D array. This is a very powerful way to access array elements.
## Two dimensional array is nothing but a collection of a number of a 1D arrays placed one after another
## `*(arr+i)` is for accessing and is the same as arr[i]
## `&arr[i]` and `arr+i` are the same. Which one is better? Well accessing array elements using pointers is always faster than accessing them by subscripts. But while using pointers, be sure to access elements in a fixed order like, start to end or vice versa. 
## However big an array may be, its elements are always stored in contiguous memory locations.
## In C, there is no check to see if subscript exceeds the size of the array. Data entered with a subscript exceeding the array size will simply be placed in memory outside the array. This can lead to errors and for worse, there is no error message to warn you
## "No matter how much time you have spent with pointers you would always find some applications of it what would leave you guessing"
