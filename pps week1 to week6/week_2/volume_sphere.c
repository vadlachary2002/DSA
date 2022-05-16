#include <stdio.h>
void main(){
	int r;
	float pi=3.14 ,area,volume;
	printf("enter radius of sphere :");
	scanf("%d",&r);
	if(r>=0){
		area=4*pi*r*r;
		volume=(4/3)*pi*r*r;
		printf("surface area : %f \nvolume : %f",area,volume);
	}else{
		printf("enter +ve radius");
	}
	
	
	
}
