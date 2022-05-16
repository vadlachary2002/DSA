#include <stdio.h>

int main(){
	int n;
	printf("enter order of matrix :");
	scanf("%d",&n);
	int chary1[n][n],chary2[n][n],chary3[n][n],i,j,m,var;
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
	printf("multiplication   of two matrices is [chary1].[chary2]:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			var=0;
			for(m=0;m<n;m++){
				var=var +chary1[i][m]*chary2[m][j];
			}
			chary3[i][j]=var;
			printf(" %d ",var);
		
		}
		printf("\n");
	}
	
	return 0;
}
