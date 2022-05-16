#include <stdio.h>
void main(){
	int a ,b;
	printf("enter two integers values :");
	scanf("%d %d",&a,&b);
	if(a>0 && b>0){
		if(a<b){
		printf("UP");
		}else if(b<a){
			printf("DOWN");
		}else if(a==b){
			printf("EQUAL");
		}else{
			printf("ERROR");
		}
		
	}else{
		printf("ERROR");
	}
	
}
