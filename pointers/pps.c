#include<stdio.h>
int main(){
	int i,j,k;
	for(i=1;i<=10;i++){
		if(i==1){
			for(j=1;j<=15;j++){
				
				if(j==1||j==2||j==5||j==6||j==11||j==12||j==13){
					printf("@ ");
				}else{
					printf("  ");
				}
			}
		}else if(i==2){
			for(j=1;j<=14;j++){
				if(j==1||j==3||j==5||j==7||j==10||j==14){
					printf("@ ");
				}else{
					printf("  ");
				}
			}
		}else if(i==3){
			for(j=1;j<=14;j++){
				if(j==1||j==4||j==5||j==8||j==10||j==15){
					printf("@ ");
				}else{
					printf("  ");
				}
			}
		}else if(i==4){
			for(j=1;j<=14;j++){
				if(j==1||j==4 ||j==5||j==8||j==11){
					printf("@ ");
				}else{
					printf("  ");
				}
					
			}
		}else if(i==5){
			for(j=1;j<=14;j++){
				if(j==1||j==2||j==3||j==5||j==6||j==7||j==12){
					printf("@ ");
				}else{
					printf("  ");
				}
			}
		}else if(i==6){
			for(j=1;j<=14;j++){
				if(j==1||j==5||j==13){
					printf("@ ");
				}else{
					printf("  ");
				}
				
			}
		}else if(i==7){
			for(j=1;j<=14;j++){
				if(j==1||j==5||j==14){
					printf("@ ");
				}else{
					printf("  ");
				}
				
			}
		}else if(i==8){
			for(j=1;j<=14;j++){
				if(j==1||j==5||j==10||j==14){
					printf("@ ");
				}else{
					printf("  ");
				}
				
			}
		}else if(i==9){
			for(j=1;j<=14;j++){
				if(j==1||j==5||j==10||j==14){
					printf("@ ");
				}else{
					printf("  ");
				}
				
				
			}
		}else if(i==10){
			for(j=1;j<=14;j++){
				if(j==1||j==5||j==11||j==12||j==13){
					printf("@ ");
				}else{
					printf("  ");
				}
				
			}
		}
			printf("\n");
		}
	}

