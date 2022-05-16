#include <stdio.h>
#include "chary.h"
void main(){
	
	int i=10;
	int *ptr1;
	ptr1=&i;
	int **ptr2;
	ptr2=&ptr1;
	int ***ptr3;
	ptr3=&ptr2;
	int ****ptr4;
	ptr4=&ptr3;
	printf("value of i %d\n",i);
	printf("value of ptr %d\n",ptr1);
	printf("*ptr1 pointing to %d\n",*ptr1);
	printf("value of ptr2 %d\n",ptr2);
	printf("*ptr2 pointing to %d\n",*ptr2);
	printf("**ptr2 pointing to %d\n",**ptr2);
	printf("value of ptr3 %d\n",ptr3);
	printf("*prt3 pointing to %d\n",*ptr3);
	printf("**ptr3 pointing to %d\n",**ptr3);
	printf("***ptr3 pointing to %d\n",***ptr3);
	printf("value of ptr4 %d\n",ptr4);
	printf("*ptr4 pointing to %d\n",*ptr4);
	printf("**ptr4 pointing to %d\n",**ptr4);
	printf("***ptr4 pointing to %d\n",***ptr4);
	printf("****ptr4 is pointing to %d\n",****ptr4);
	
	
	pps();
	heart('&');
	
	
}
