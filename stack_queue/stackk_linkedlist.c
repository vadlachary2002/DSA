#include <stdio.h>
#include <stdlib.h>
int display();
struct node{
	int data;
	struct node *link;
};
struct node *head=NULL;
int top=0;
int push(){
	struct node *temp,*run;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(top==0){
		head=temp;
	}else{
		int i=top;
		run=head;
		while(i>1){
			run=run->link;
			i--;
		}
		run->link=temp;
	}
	top++;
	printf("%d pushed\n",temp->data);
	return 0;
}
int display(){
	if(top==0){
		printf("stack is underflow\n");
		return;
	}
	printf("viewing data\n");
	int i=top;
	struct node *run;
	run=head;
	while(i>0){
		printf("%d ",run->data);
		run=run->link;
		i--;
	}
	printf("\n");
}
int pop(){
	if(top==0){
		printf("stack is underflow\n");
		return;
	}
	struct node *run=head;
	while(run->link->link!=NULL){
		run=run->link;
	}
	printf("%d is poped\n",run->link->data);
	run->link=NULL;
	top--;
}
int main(){
	while(1){
		int ch;
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.exit\n->");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch){
			case 1:
				//system("cls");
				push();
				break;
			case 2:
				//system("cls");
				pop();
				break;
			case 3:
				system("cls");
				display();
				break;
			case 4:
				return 0;
			default:
				system("cls");
				printf("ERROR!...\n");	
		}
	}
}
