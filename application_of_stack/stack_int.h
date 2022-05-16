#include <stdio.h>
#define L 20
int stack_int[L],top=-1;
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
int push(int x){
	if(isfull()){
		return 0;
	}else{
		top++;
		stack_int[top]=x;
	}
}
int pop(){
	if(isempty()){
		return 0;
	}else{
		top--;
		return stack_int[top+1];		
	}
}
