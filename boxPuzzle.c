#include <stdio.h>
#include <stdlib.h>
int count=0;
int print(int **arr,int n){
	printf("\n\n");
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
int isInRowCol(int **arr,int row,int col,int n,int key){
	int i,j;
	for(i=0;i<n;i++){
		if(key==arr[row][i]){
			return 1;
		}
		if(key==arr[i][col]){
			return 1;
		}
	}
	return 0;
}
int isInBox(int **arr,int rbox,int cbox,int key){
	int i,j;
	for(i=rbox-3;i<rbox;i++){
		for(j=cbox-3;j<cbox;j++){
			if(key==arr[i][j]){
				return 1;
			}
		}
	}
	return 0;
}
int sat=0;
int charySet(int **arr,int row,int col,int n,int rbox,int cbox){
	if(row<rbox && col<cbox){
		if(arr[row][col]==0){
			int i;
			for(i=1;i<=9;i++){
				if(isInBox(arr,rbox,cbox,i) || isInRowCol(arr,row,col,n,i)){
					continue;
					
				}else{
					arr[row][col]=i;
					if(charySet(arr,row,col+1,n,rbox,cbox)){
						printf("");
					}else{
						charySet(arr,row+1,cbox-3,n,rbox,cbox);
					}
					if(arr[rbox-1][cbox-1]!=0){
						if(cbox==9){
							charySet(arr,row+1,0,n,rbox+3,3);
						}else{
							charySet(arr,row-2,col+1,n,rbox,cbox+3);
						}
						printf("row=%d col=%d\n",row,col);
						print(arr,n);
						count++;
						
					}
//					print(arr,n);
					arr[row][col]=0;
				}
			}	
		}else{
			if(charySet(arr,row,col+1,n,rbox,cbox)){
				return 1;
			}else{
				charySet(arr,row+1,cbox-3,n,rbox,cbox);
			}
		}
	}else{
		return 0;
	}
}
int main(){
	int n,i,j;
	printf("enter no of rows=col:[n/n box]:");
	scanf("%d",&n);
	printf("enter values :\n");
	int **arr=malloc(sizeof(int *)*n);
	for(i=0;i<n;i++){
        *(arr+i)=malloc(n*sizeof(int));
        for(j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
        }
    }
   	charySet(arr,0,0,n,3,3);
   	print(arr,n);
	printf("possibilities=%d\n",count);
}
