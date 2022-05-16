#include<stdio.h>
#include<math.h>
int main(){
	int x,n,i;
	float s=0;
	printf("x-x^3/3!+x^5/5!-x^7/7!+.......\n");
	printf("enter x value");
	scanf("%d",&x);
	printf("how many terms you want to calculate :");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		s=s+(pow(-1,i)*(pow(x,(2*i)+1))/(fact((2*i)+1)));
		
	}
	printf("sum is %f",s);
	return 0;
}
int fact(int n){
	int fact=1;
	while(n>0){
		fact=fact*n;
		n--;
	}
	return fact;
}
