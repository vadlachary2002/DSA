#include<stdio.h>
main(){
	float r,a,pi = 3.14;
	printf("enter radius of circle = ");
	scanf("%f",&r);
	if(r>=0){
		a = pi * r * r;
		printf("area of the circle is = %f",a);
		
	}else{
		printf("please enter +ve radius");
	}
	
	
}
