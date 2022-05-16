#include <stdio.h>
#include <malloc.h>
int isInRowCol(int **arr,int row,int col,int n,int key){
	int i,j;
	for(i=0;i<n;i++){
		if(key==arr[row][i]){
			return 0;
		}
		if(key==arr[i][col]){
			return 0;
		}
	}
	return 1;
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
		if(box==2){
			j=3;
		}else if(box==3){
			j=6;
		}
		l=j+3;
		for(i=3;i<6;i++){
			for(k=j;k<l;k++){
				if(key==arr[i][k]){
					return 0;
				}
			}
		}
		return 1;
		
	}else if(box==7 || box==8 || box==9){
		int i=6,j=0,l=3,k;
		if(box==2){
			j=3;
		}else if(box==3){
			j=6;
		}
		l=j+3;
		for(i=6;i<9;i++){
			for(k=j;k<l;k++){
				if(key==arr[i][k]){
					return 0;
				}
			}
		}
		return 1;
		
	}
	
}
int setSudoku(int **arr,int row,int col,int n,int value){
	if(row<n && col<n && value<=9){
		if(arr[row][col]==0){ 
			int box=findBox(row,col);
			printf("box=%d\n",box);
			if(isInBox(arr,box,value)==0){
				printf("value=%d not in box=%d\n",value,box);
				if(isInRowCol(arr,row,col,n,value)){
					printf("value=%d not in row col\n",value);
					arr[row][col]=value;
					if(row==n-1){
						return 1;
					}
					if(setSudoku(arr,row,col+1,n,1)){
						setSudoku(arr,row+1,0,n,1);
						return 1;
					}else{
						arr[row][col]=value+1;
						setSudoku(arr,row,col+1,n,1);
					}	
				}else{
					value++;
					setSudoku(arr,row,col,n,value);
				}
			}else{
				value++;
				setSudoku(arr,row,col,n,value);
			}	
		}
		else{
			printf("row=%d next col=%d\n",row,col);
			setSudoku(arr,row,col+1,n,value);
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
   setSudoku(arr,0,0,n,1);
	
    printf("\noriginal \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
}
