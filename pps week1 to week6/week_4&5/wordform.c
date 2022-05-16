#include <stdio.h>
#include <string.h>
#include <math.h>
int length(int);
void print_digit(int,int);
void main (){
	int i,n,count,var,value;
	printf("enter any number");
	scanf("%d",&n);
	count=length(n);
	while(count>0){
		print_digit(count,n);
		/* why im using the print_digit function rather than 
		typing the code right here because when we call a function 
		out of main it gives localvariables that is in that function 
		only and not effect in main function  */	
		var=n/(pow(10,count-1));
		n=n-(var*(pow(10,count-1)));
		count=length(n);
	}
}
int length(int n){
	int count=0;
	while(n!=0){
		n=n/10;
		count++;
		
	}
	return count;
}
void print_digit(int i,int n){
	int value;
	char array[9][20]={"units","tens","hundereds","thousands","ten_thousands","lakhs","ten_lakhs","crore","ten_crore"};
	value=n/(pow(10,i-1));
	printf(" %d %s  ",value,array[i-1]);
	
}

