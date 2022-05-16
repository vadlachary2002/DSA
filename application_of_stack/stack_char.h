#include <stdio.h>
#define L 30
char stack_char[L];
int top=-1;
int isempty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}
int isfull(){
	if(top==L){
		return 1;
	}else{
		return 0;
	}
}

int  push(char x){
	top++;
	stack_char[top]=x;
	return 1;
}
char pop(){
	top--;
	return stack_char[top+1];
}
