#include <stdio.h>

int main(){
	int x,y,z;
	printf("enter values of x , y and z :");
	scanf("%d%d%d",&x,&y,&z);
	if(x>y && x>z){
		printf("%d is greater than %d and %d",x,y,z);
		
	}
	else if(y>z){
		printf("%d is greater than %d and %d",y,x,z);
		
	
	}
	else{
		printf("%d is greaterthan %d %d ",z,y,x);
	}
	return 0;
}
