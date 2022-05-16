#include <stdio.h>
void main (){
	int i=100;
	int *p;
	p=&i;
	printf("i value %d \n",i);
	printf("p value %d \n",p);
	printf("address of i %u \n",&i);
	printf("address  of p %u \n",&p);
	printf("pointer to p %d \n",*p);
	printf("pointer of address of  i %d ",*(&i));
	
}
