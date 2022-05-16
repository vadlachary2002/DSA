#include<stdio.h>

int add(int x,int y){
	int z=x+y;
	return z;
}
int multi(int x,int y,int z){
	int c=x*y*z;
	return c;
}
void main(){
	int r1,r2,r3,r4;
	int (*ptr)(int,int);
	r1=add(10,20);
	r2=multi(2,3,4);
	printf("add %d \nmultiply %d\n",r1,r2);
	ptr=&add;
	r3=ptr(30,50);
	printf("by pointer func add %d\n",r3);
	/*ptr=&multi;
	r4=ptr(1,2);
	printf("by pointer func multiply %d",r4);
	one pointer can be used many time if its signature is same (i.e every time it taking x variables)*/
}
