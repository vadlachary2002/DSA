#include <stdio.h>
#include "stack_int.h"
#include <math.h>
int main(){
	char exp[20],*c;
	printf("enter expression\n:");
	scanf("%s",exp);
	c=exp;
	while(*c!='\0'){
		int res;
		if(isalnum(*c)){
			push(*c-48);
		}else if(*c=='*'){
			res=pop();
			res=pop()*res;
			push(res);
		}else if(*c=='/'){
			res=pop();
			res=pop()/res;
			push(res);
		}else if(*c=='+'){
			res=pop();
			res=pop()+res;
			push(res);
		}
		else if(*c=='-'){
			res=pop();
			res=pop()-res;
			push(res);
		}else if(*c=='^'){
			res=pop();
			res=pow(pop(),res);
			push(res);
		}
		c++;
	}
	printf("%d",pop());
	
}
