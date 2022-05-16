#include <stdio.h>
int main(){
	int n,i,j,k,s,temp=1;
	printf("enter nth value");
	//int chary[n][2*n-1];
	scanf("%d",&n);
	int array[n][n];
	for(i=0;i<n;i++){
		printf(" ");
	}
	printf("%d\n",1);
	for(i=1;i<n;i++){
		for(k=0;k<n-i;k++){
			printf(" ");
		}
		printf("%d ",1);
		array[i][0]=1;
		for(j=1;j<i;j++){
			array[i][j]=array[i-1][j-1]+array[i-1][j];
			printf("%d ",array[i][j]);
		}
		printf("%d ",1);
		array[i][j]=1;
		printf("\n");
	}
}
