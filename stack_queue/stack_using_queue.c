#include <stdio.h>
#define L 7
int Queue1[L],front1=0,rear1=0;
int Queue2[L],front2=0,rear2=0;
int Queue3[L],front3=0,rear3=0;
int enQueue1(int data){
	if(rear1==L){
		return 0;
	}
	Queue1[rear1]=data;
	rear1++;
	return 1;
}
int enQueue2(int data){
	if(rear2==L){
		return 0;
	}
	Queue2[rear2]=data;
	rear2++;
	return 1;
}
int enQueue3(int data){
	if(rear3==L){
		printf("stack is overflow\n");
		return 0;
	}
	Queue3[rear3]=data;
	rear3++;
	return 1;
}

int display1(){
	if(rear1==front1){
		printf("queue1 is underflow\n");
		return 0;
	}
	int i;
	for(i=front1;i<rear1;i++){
		printf("%d ",Queue1[i]);
	}
	printf("\n");
}
int display2(){
	if(rear2==front2){
		printf("queue2 is underflow\n");
		return 0;
	}
	int i;
	for(i=front2;i<rear2;i++){
		printf("%d ",Queue2[i]);
	}
	printf("\n");
}
int display3(){
	if(rear3==front3){
		printf("queue is underflow\n");
		return 0;
	}
	int i;
	for(i=front3;i<rear3;i++){
		printf("%d\n",Queue3[i]);
	}
	printf("\n");
}



int deQueue1(){
	if(front1==rear1){
		return 0;
	}
	int i,data=Queue1[front1];
	for(i=0;i<rear1-1;i++){
		Queue1[i]=Queue1[i+1];		
	}
	rear1--;
	return data;
}
int deQueue2(){
	if(front2==rear2){
		return 0;
	}
	int i,data=Queue2[front2];
	for(i=0;i<rear2-1;i++){
		Queue2[i]=Queue2[i+1];		
	}
	rear2--;
	return data;
}
int deQueue3(){
	if(front3==rear3){
		printf("stack is full\n");
		return 0;
	}
	int i,data=Queue3[front3];
	for(i=0;i<rear3-1;i++){
		Queue3[i]=Queue3[i+1];		
	}
	rear3--;
	return data;
}
int push(int data){
	enQueue3(data);
	return 1;
}
int pop(){
	int i=rear3, dataD;
	while(i>0){
		enQueue2(deQueue3());
		if(i>1){
			enQueue1(deQueue2());
		}else{
			dataD=deQueue2();
		}
		
		i--;
	}
	printf("poped %d\n",dataD);
	i=rear1;
	while(i>0){
		enQueue3(deQueue1());
		i--;
	}
	
}
int main(){
	while(1){
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				system("cls");
				int data;
				printf("enter data:");
				scanf("%d",&data);
				push(data);
				display3();
				break;
			case 2:
				system("cls");
				pop();
				display3();
				break;
			case 3:
				system("cls");
				display3();
				break;
			default:
				system("cls");
				printf("error\n");
		}
		
	}
	

}
