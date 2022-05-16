#include<stdio.h>
#include<math.h>
#include<complex.h>
int main(){
	int a,b,c,det;
	float x1,x2;
	printf("enter Quadratic equation : \n");
	printf("coeff of   x^2:");
	scanf("%d",&a);
	printf("coeff of      x:");
	scanf("%d",&b);
	printf("coeff of const:");
	scanf("%d",&c);
	det=(b*b)-4*a*c;
	if(det>=0){
		x1=((-b)+sqrt(det))/(2*a);
		x2=((-b)-sqrt(det))/(2*a);
		printf("roots are %.2f and %.2f",x1,x2);
		
	}else{
		x1=((-b)+sqrt(det))/(2*a);
		x2=((-b)-sqrt(det))/(2*a);
		printf("roots are complex %f+%fi and %f+%fi",creal(x1),cimag(x1),creal(x2),cimag(x2));
	}
	return 0;
	
}
