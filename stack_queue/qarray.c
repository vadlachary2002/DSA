#include <stdio.h>
#define L 5
int array[L],front=-1,rear=-1;
int enQueue(int data){
	if((rear+1)%L==front){
		printf("overflow\n");
		return;
	}
	if(rear==L-1){
		rear=0;
		array[rear]=data;
		printf("%d inserted\n",array[rear]);
	}else {
		if(front==-1){
			front++;
		}
		rear++;
		array[rear]=data;
		printf("%d inserted\n",array[rear]);
	}
	
}
int deQueue(){
	if(front==-1 && rear==-1){
		printf("underflow\n");
		return ;
	}
	if(front==L-1){
		if(front==rear){
			front=-1;
			rear=-1;
		}else{
			front=0;
		}
	}else{
		if(front==rear){
			front=-1;
			rear=-1;
		}else{
			front++;
		}	
	}
	
}

int display(){
	if((front==-1 &&  rear==-1) ){
		printf("Queue is underflow\n");
		return ;
	}
	int j=front,k=rear;
	if(k<j){
		while(j<L){
			printf("%d ",array[j]);
			j++;
		}
		j=0;
		while(j<=rear){
			printf("%d ",array[j]);
			j++;
		}
		
	}else{
		
		while(j<=k){
			//printf("j=%d\n",j);
			printf("%d ",array[j]);
			j++;
		}
		
	}
	printf("\n");
	printf("[front=%d rear=%d]\n",front,rear);
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
				system("cls");
				int data;
				printf("enter data:");
				scanf("%d",&data);
				enQueue(data);
				display();
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
		
	}
	
}
