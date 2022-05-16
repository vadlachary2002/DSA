#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head=NULL;
int front=0,rear=0;
int enQueue(){
	struct node *temp,*run;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(front==rear){
		head=temp;
	}else{
		int i=rear;
		run=head;
		while(run->link!=NULL){
			run=run->link;
			i--;
		}
		run->link=temp;	
	}
	printf("%d inserted\n\n",temp->data);
	rear++;
	return;
}
int display(){
	if(front==rear){
		printf("queue is underflow\n");
		return;
	}
	struct node *run;
	run=head;
	int i=rear;
	while(i--){
		printf("%d ",run->data);
		run=run->link;
	}
	printf("\n\n");
	return ;
}
int deQueue(){
	if(front==rear){
		printf("queue is underflow\n");
		return ;
	}
	printf("%d data is deleted\n",head->data);
	head=head->link;
	rear--;
	return;
}
int main(){
	while(1){
		int ch;
		printf("1.EnQueue\n");
		printf("2.DeQueue\n");
		printf("3.display\n");
		printf("4.exit\n->");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch){
			case 1:
				//system("cls");
				enQueue();
				break;
			case 2:
				//system("cls");
				deQueue();
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

