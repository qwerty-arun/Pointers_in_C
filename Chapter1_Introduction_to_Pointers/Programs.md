# Prgm-1
```
#include <stdio.h>
int main()
{
	char c, *cc;
	int i, *ii;
	float a, *aa;
	
	c='A';
	i=54;
	a=3.14;
	cc=&c;
	ii=&i;
	aa=&a;
	printf("Address in cc= %u\n",cc);
	printf("Address in ii= %u\n",ii);
	printf("Address in aa= %u\n",aa);
	printf("Value of c= %c\n", *cc);
	printf("Value of i= %d\n", *ii);
	printf("Value of a= %f\n", *aa);
}
```

# Prgm-2
```
#include <stdio.h>
int main()
{
	int i=54;
	float a=3.14;
	char *ii,*aa;

	ii=(char *)&i;
	aa=(char *)&a;
	printf("Address contained in ii= %u\n",ii);	
	printf("Address contained in aa= %u\n",aa);	
	printf("Value at the address contained in ii = %d\n",*ii);
	printf("Value at the address contained in aa = %d\n",*aa);
}
```

### Results of Prgm-2
```
Address contained in ii= 1897129152
Address contained in aa= 1897129156
Value at the address contained in ii = 54
Value at the address contained in aa = -61
```

# Prgm-3
```
#include <stdio.h>
int *fun();
int main()
{
	int *p;
	p=fun();
	printf("\n%u",p);
	printf("\n%d",*p);
}

int *fun()
{
	int i=20;
	return(&i);
}
```
### Results of Prgm3
```
Segmentation fault (Core Dumped)
Reason: This is because, when the control comes back from fun(),'i' dies. So even if we have its addreass in 'p', we can't access 'i' since it is already dead. If you want 'i' to survive and *p to give 20, then we need to use the 'static' keyword for 'i'.
```