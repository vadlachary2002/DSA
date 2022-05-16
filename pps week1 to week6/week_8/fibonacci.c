#include <stdio.h>
int fib(int n){
	int n1=0,n2=1,n3=1,i=3;
	while(i<n){
		n1=n2;
		n2=n3;
		n3=n1+n2;
		i++;
	}
	return n3;
}
int main(){
	int n,f;
	printf("enter nth fibonacci term :");
	scanf("%d",&n);
	f=fib(n);
	printf("value of %dth fibonacci term is %d",n,f);
	return 0;
}
