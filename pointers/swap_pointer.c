#include <stdio.h>
void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}
void main(){
	int a=10,b=20;
	printf("before swap %d %d \n",a,b);
	swap(&a,&b);
	printf("after swap %d %d",a,b);
}
