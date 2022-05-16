#include <stdio.h>
int odd(int);
int even(int);
int main(){
	int n,option;
	printf("1.odd\n");
	printf("2.even\n");
	printf("enter odd or even [1/2] ");
	scanf("%d",&option);
	switch (option){
		case 1:
			printf("upto how many numbers :");
			scanf("%d",&n);
			odd(n);
			break;
		case 2:
			printf("upto how many numbers :");
			scanf("%d",&n);
			even(n);
			break;
		default:
			printf("enter 1 or 2 only... ");
	
	}
	
	return 0;
}
int odd(int n){
	int i=1,j=1,s1=0;
	while(i<=n){
		if(i==n){
			printf("%d",j);
		}else{
			printf("%d+",j);
			
		}
		
		s1=s1+j;
		j=j+2;
		i++;
	}
	printf("=%d",s1);
	
}
int even(int n){
	int i=1,j=2,s1=0;
	while(i<=n){
		if(i==n){
			printf("%d",j);
		}else{
			printf("%d+",j);
			
		}
		
		s1=s1+j;
		j=j+2;
		i++;
	}
	printf("=%d",s1);
}
