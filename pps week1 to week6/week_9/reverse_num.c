#include <stdio.h>
int rem,sum=0;
int reverse_num(int n){
	if(n!=0){
		rem=n%10;
		sum=sum*10+rem;
		reverse_num(n/10);
	}else{
		return sum;
	}
}
int main(){
	int n,r;
	printf("enter your number :");
	scanf("%d",&n);
	r=reverse_num(n);
	printf("reversed number is %d",r);
}
