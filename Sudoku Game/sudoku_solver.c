#include <stdio.h>
#include <stdlib.h>
int solutions=0;
void print(int **arr,int n){
	int i,j;
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	if(j%3==0){
        		printf(" ");
			}
        	printf("%d ",arr[i][j]);
		}
		if(i%3==2){
			printf("\n");
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
int findBox(int row,int col){
	switch(row){
		case 0 ... 2:
			switch(col){
				case 0 ... 2:
					return 1;
					break;
				case 3 ... 5:
					return 2;
				case 6 ... 8:
					return 3; 
			}
		case 3 ... 5:
			switch(col){
				case 0 ... 2:
					return 4;
				case 3 ... 5:
					return 5;
				case 6 ... 8:
					return 6; 
			}
		case 6 ... 8:
			switch(col){
				case 0 ... 2:
					return 7;
				case 3 ... 5:
					return 8;
				case 6 ... 8:
					return 9; 
			}

	}
}
int isInBox(int **arr,int box,int key){
	if(box==1 || box==2 || box==3){
		int i=0,j=0,l=3,k;
		if(box==2){
			j=3;
		}else if(box==3){
			j=6;
		}
		l=j+3;
		for(i=0;i<3;i++){
			for(k=j;k<l;k++){
				if(key==arr[i][k]){
					return 1;
				}
			}
		}
		return 0;

	}else if(box==4 || box==5 || box==6){
		int i,j=0,l=3,k;
		if(box==5){
			j=3;
		}else if(box==6){
			j=6;
		}
		l=j+3;
		for(i=3;i<6;i++){
			for(k=j;k<l;k++){
				if(key==arr[i][k]){
					return 1;
				}
			}
		}
		return 0;

	}else if(box==7 || box==8 || box==9){
		int i=6,j=0,l=3,k;
		if(box==8){
			j=3;
		}else if(box==9){
			j=6;
		}
		l=j+3;
		for(i=6;i<9;i++){
			for(k=j;k<l;k++){
				if(key==arr[i][k]){
					return 1;
				}
			}
		}
		return 0;

	}

}
int isSafe(int **arr,int row,int col,int box,int n,int value){
	if(!isInBox(arr,box,value) && !isInRowCol(arr,row,col,n,value)){
		return 1;
	}else{
		return 0;
	}
}
int setSudoku(int **arr,int row,int col,int n){
	if(row<n && col<n){
		if(arr[row][col]==0){ 
			int box=findBox(row,col),i;
			for(i=1;i<=9;i++){

				if(isSafe(arr,row,col,box,n,i)){
					arr[row][col]=i;
					if(col==n-1){
						if(setSudoku(arr,row+1,0,n)){
							return 1;
						}else{
							arr[row][col]=0;
						}
					}else{
						if(setSudoku(arr,row,col+1,n)){
							return 1;
						}else{
							arr[row][col]=0;
						}
					}
				}
			}
			fflush(stdin);
		}else{
			if(col==n-1){
				return setSudoku(arr,row+1,0,n);
			}else{
				return setSudoku(arr,row,col+1,n);
			}

		}

	}else{
		if(col==0){
			printf("\n\none of its solutions:\n");
			print(arr,n);
			solutions++;
			return 1;
		}
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
   	setSudoku(arr,0,0,n);
    printf("\n\tSolution\n");
    print(arr,n);
	printf("no of solutions:%d\n",solutions);
}
