#include <stdio.h>
int main(){
	int n,loop=1,i,j,f=0;
	printf("Enter your number :");
	scanf("%d",&n);
	printf("primes are : \n");
		for(i=1;i<=n;i++){
			for(j=2;j<i;j++){
				if(i%j==0){
					f=1;
					break;
				}
			}
			if(f==0){
				if(i==1){
					printf("1 is nither prime nor composite \n");
				
				}
				else{
					printf("%d is prime \n",i);
				
				}
				
			}
			f=0;
	
	}
	
	return 0;
	
}
