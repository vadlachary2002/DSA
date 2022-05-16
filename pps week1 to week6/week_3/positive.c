#include <stdio.h>
int main(){
	int a;
	printf("enter any value :");
	scanf("%d",&a);
	if(a>0){
		printf("your value %d is positive ",a);
	}else if(a<0){
		printf("your value %d is negative ",a);
	}else{
		printf("your value %d is zero",a);
	}
	return 0;
}
