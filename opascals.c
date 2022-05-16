#include <stdio.h>
int main(){
	int i,j,k,n;
	printf("Enter nth value :");
	scanf("%d",&n);
	for(i=n;i>0;i--){
		for(j=0;j<i;j++){
			printf("  ");
		}
		for(k=1;k<=n-i;k++){
			printf("%d ",k);
		}
		for(k=n-i-1;k>0;k--){
			printf("%d ",k);
		}
		printf("\n");
	}
	
	
}
