#include <stdio.h>
#include <string.h>
#define L 10
int s1[L],s2[L],top1=-1,top2=-1,count=0;
int push1(int data){
	if(top1==L-1){
		return 0;
	}else{
		count++;
		s1[++top1]=data;
	}
}
int push2(int data){
	if(top2==L-1){
		return 0;
	}
	else{
		s2[++top2]=data;
	}
}
int pop1(){
	if(top1!=-1){
		int data=s1[top1];
		top1--;
		return data;
	}
}
int pop2(){
	if(top2!=-1){
		int data=s2[top2];
		top2--;
		return data;
	}
}

int enQueue(int data){
	push1(data);
}
int display(){
	int i;
	for(i=0;i<=top1;i++){
		printf("%d ",s1[i]);
	}
	printf("\n\n");
}
int deQueue(){
	int i=top1;
	while(i>=0){
		push2(pop1());
		i--;
	}
	printf("dequeued=%d\n",pop2());
	i=top2;
	while(i>=0){
		push1(pop2());
		i--;
	}

	
}
int main(){
	while(1){
		printf("1.EnQueue\n");
		printf("2.DeQueue\n");
		printf("3.Display\n");
		printf("4.exit\n");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				fflush(stdin);
				int data;
				printf("enter data:");
				scanf("%d",&data);
				enQueue(data);
				display();
				break;
			case 2:
				deQueue();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("error");
		}
	}
}
