#include<stdio.h>
void main(){
	system("color 01");
	int i,j,k;
	for(i=1;i<=9;i++){
		for(j=1;j<=11;j++){
			if(i==1 && (j==3||j==4||j==8||j==9)){
				printf("@ ");
			}else if(i==2 && (j==2||j==5||j==7||j==10)){
				printf("@ ");
			}else if((i==3 || i==4) && (j==1||j==6||j==11)){
				printf("@ ");
			}else if(i-3==j || i+j==15){
				printf("@ ");
			}else{
				printf("  ");
			}
		}
		printf("\n");
	}
}
