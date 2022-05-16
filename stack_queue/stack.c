#include <stdio.h>
#define L 5
int array[L],top=-1;
int isempty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}
int isfull(){
	if(top==L-1){
		return 1;
	}else{
		return 0;
	}
}
int display(){
	if(isempty()){
		printf("stack is underflow\n");
		return;
	}
	int i=0;
	printf("Viewing data:\n");
	while(i<=top){
		printf("%d\t",array[i]);
		i++;
	}
	printf("\n");
	return 0;
}
int push(){
	if(isfull()){
		printf("stack is overflow\n");
	}else{
		int data;
		printf("enter data:");
		scanf("%d",&data);
		array[++top]=data;
		printf("pushed %d\n",data);
		display();
	}
}
int pop(){
	if(isempty()){
		printf("stack is underflow\n");
	}else{
		printf("%d poped\n",array[top]);
		top--;
		
		display();
	}
}
int main(){
	while(1){
	int ch;
	printf("1.PUSH\n");
	printf("2.POP\n");
	printf("3.Display\n");
	printf("4.Peak\n");
	printf("4.exit\n->");
	fflush(stdin);
	scanf("%d",&ch);
	switch(ch){
		case 1:
			system("cls");
			printf("PUSH\n");
			push();
			break;
		case 2:
			system("cls");
			printf("POP\n");
			pop();
			break;
		case 3:
			system("cls");
			display();
			break;
		case 4:
			system("cls");
			if(isempty()){
				printf("stack is underflow\n");
			}else{
				printf("%d \n",array[top]);
			}
			break;
		default:
			system("cls");
			printf("Error!\n");	
		}	
	}
}
