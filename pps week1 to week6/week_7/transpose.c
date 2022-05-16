#include <stdio.h>

int main(){
	int n;
	printf("enter order of matrix :");
	scanf("%d",&n);
	int chary1[n][n],chary2[n][n],i,j;
	printf("enter elements in chary1 array \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%dth %dth elem : ",i+1,j+1);
			scanf("%d",&chary1[i][j]);
		}
	}
	printf("transpose of  matrices is \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf(" %d  ",chary1[j][i]);
			chary2[i][j]=chary1[j][i];
		
		}
		printf("\n");
	}
	
	return 0;
}


