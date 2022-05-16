//queue using array
#include <stdio.h>
#include <stdlib.h>
#define L 5
int display();
int array[L],front=0,rear=0;

int enQueue(){
	if(rear==L){
		printf("queue is overflow\n");
		return;
	}
	int data;
	printf("enter data:");
	scanf("%d",&data);
	array[rear]=data;
	printf("%d inserted\n\n",array[rear]);
	rear++;
	return;
}
int display(){
	if(rear==front){
		printf("queue is underflow\n");
		return;
	}
	printf("viewing data\n");
	int i;
	for(i=front;i<rear;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

int deQueue(){
	if(front==rear){
		printf("queue is underflow\n");
		return ;
	}
	int i;
	printf("%d is deleted\n",array[front]);
	for(i=0;i<rear-1;i++){
		array[i]=array[i+1];		
	}
	rear--;
	return;
}
int main(){
	while(1){
		int ch;
		printf("1.EnQueue\n");
		printf("2.DeQueue\n");
		printf("3.Display\n");
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
				return;
			default:
				system("cls");
				printf("ERROR!...\n");
		}
		
//	}
}
