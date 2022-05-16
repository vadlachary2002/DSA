#include <stdio.h>
int swap(int a,int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
	printf("IN SWAP FUNCTION \n");
	printf("a=%d b=%d\n",a,b);
	return 0;
}
int main(){
	int a,b;
	printf("enter a value :");
	scanf("%d",&a);
	printf("enter b value :");
	scanf("%d",&b);
	swap(a,b);
	printf("IN MAIN FUNCTION \n");
	printf("a=%d b=%d\n",a,b);
	return 0;
}
