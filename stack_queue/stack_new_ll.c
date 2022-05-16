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
		temp->link=head;
		head=temp;
		
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
	struct node *run=head;
	while(run->link!=NULL){
		printf("\t%d\t\n",run->data);
		run=run->link;
	}
	printf("\t%d\t\n\n",run->data);
	printf("\n");
}
int pop(){
	if(top==0){
		printf("stack is underflow\n");
		return;
	}
	printf("poped %d\n",head->data);
	head=head->link;
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
				system("cls");
				push();
				display();
				break;
			case 2:
				system("cls");
				pop();
				display();
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
