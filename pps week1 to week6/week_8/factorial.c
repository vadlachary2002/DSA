#include <stdio.h>
int factorial(int n){
	int i,fact=1;
	for(i=n;i>0;i--){
		fact=fact*i;	
	}
	return fact;
}
int main(){
	int n,fact;
	printf("enter factorial of ___number :");
	scanf("%d",&n);
	fact=factorial(n);
	printf("%d!=%d",n,fact);
	return 0;
}
