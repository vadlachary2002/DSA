#include <stdio.h>

int main(){
	int n;
	printf("enter order of matrix :");
	scanf("%d",&n);
	int chary1[n][n],chary2[n][n],chary3[n][n],i,j;
	printf("enter elements in chary1 array \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%dth %dth elem : ",i+1,j+1);
			scanf("%d",&chary1[i][j]);
		}
	}
	printf("enter elements in chary2 array \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%dth %dth emem :",i+1,j+1);
			scanf("%d",&chary2[i][j]);
			
		}
	}
	printf("substraction  of two matrices is [chary1]-[chary2]:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf(" %d  ",chary1[i][j]-chary2[i][j]);
			chary3[i][j]=chary1[i][j]-chary2[i][j];
		
		}
		printf("\n");
	}
	
	return 0;
}
