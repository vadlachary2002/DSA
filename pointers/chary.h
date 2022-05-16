#define CHARY 2002
void printint(int c){
	printf("%d",c);
}

void printstr(char str[]){
	printf("%s",str);
}


int printarray(int array[],int l){
	int i;
	for(i=0;i<l;i++){
		printf("%d,",array[i]);
		
	}
	return 0;
}	
void print(char string[],int c){
	int i=0;
	while(string[i]!='\0'){
		if(string[i]=='%'){
			if(string[i+1]=='d'){
				printf("%d",c);
			}else if(string[i+1]=='f'){
				printf("%f",c);
			}else if(string[i+1]=='i'){
				printf("%i",c);
			}else{
				printf("%c",string[i]);
			}
			
			i=i+2;
		}else{
			printf("%c",string[i]);
			i++;
		}
	}
}

void pps(){
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
void heart(char c){
	int i,j,k;
	for(i=1;i<=9;i++){
		for(j=1;j<=11;j++){
			if(i==1 && (j==3||j==4||j==8||j==9)){
				printf("%c ",c);
			}else if(i==2 && (j==2||j==5||j==7||j==10)){
				printf("%c ",c);
			}else if((i==3 || i==4) && (j==1||j==6||j==11)){
				printf("%c ",c);
			}else if(i-3==j || i+j==15){
				printf("%c ",c);
			}else{
				printf("  ");
			}
		}
		printf("\n");
	}
}

