#include <stdio.h>
int fib(int n){
	if(n==1){
		return 0;
	}else if(n==2){
		return 1;
	}else{
		return (fib(n-1)+fib(n-2));
	}
}
int main(){
	int n,f;
	printf("enter nth fibonacci term:");
	scanf("%d",&n);
	f=fib(n);
	printf("value is %d",f);
}
