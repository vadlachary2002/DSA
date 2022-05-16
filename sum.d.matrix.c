#include <stdio.h>
int main(){
	int i,n,j,d=0;
	printf("enter order of matrix :");
	scanf("%d",&n);
	char matrix[n][n];
	printf("enter matrix:");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("A[%d][%d]",i+1,j+1);
			scanf("%d",&matrix[i][j]);
		}
	}
	for(i=0;i<n;i++){
		d=d+matrix[i][i];
	}
	printf("sum of diagional elements is %d ",d);
}
