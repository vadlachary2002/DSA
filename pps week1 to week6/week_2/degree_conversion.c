#include<stdio.h>
void main(){
	float c,f;
	
	printf("Enter temperature fahrenheit : ");
	scanf("%f",&f);
	c = ((f-32)*5)/9;
	printf("temperature of %.2f fahrenheit is  %.2f celcious",f,c);

	
}
