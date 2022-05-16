#include <stdio.h>
#include "stack_char.h"
#include <math.h>
#include <string.h>
int priority(char x){
	
	switch(x){
		case '(':
		case ')':
			return 0;
		case '-':
		case '+':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	
	}
}
int main(){
	char exp[40],*c,x,postExp[40],*pc;
	printf("enter expression\n:");
	scanf("%s",exp);
	c=exp;
	pc=postExp;
	while(*c!='\0'){
		if(isalnum(*c)){
			*pc=*c;
			pc++;

		}else if(top==-1 || *c=='('){ 
			push(*c);
		}else if(*c==')'){
			while((x=pop())!='('){
				*pc=x;
				pc++;
				
			}
		}
		else{
			while((priority(stack_char[top]) >=priority(*c) ) && top>=0){
				*pc=pop();
				pc++;
			}
			push(*c);
		}
		c++;
	}
	while(top>=0){
		*pc=pop();
		pc++;
	}
	printf("postfix=%s\n",postExp);
	
	
	
}
