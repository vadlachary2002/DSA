#include <stdio.h>
#include <stdlib.h>
#define L 7
struct node {
	int data;
};
struct node *head[L]={NULL};
struct node *createNode(int data){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node ));
	temp->data=data;
	return temp;
}
int count=0;
int insert(){
	int data,hash,fi=0,key,probes=1;
	printf("enter data:");
	scanf("%d",&data);
	struct node *newNode;
	newNode=createNode(data);
	hash=data%L;
	key=(hash+fi*fi)%L;
	while(head[key]!=NULL ){
		fi++;
		key=(hash+fi*fi)%L;
		probes++;
		if(fi>=L){
			break;
		}
		
	}
	if(fi>=L){
		printf("no place found for this data[%d] value\n",data);
	}else{
		head[key]=newNode;
		count++;
		printf("collisions=%d\n",probes);
	}	
}
int display(){
	int i=0;
	while(i<L){
		if(head[i]==NULL){
			printf("%d  -NULL\n",i);
		}else{
			printf("%d  -%d\n",i,head[i]->data);
		}
		i++;	
	}
	printf("\n");
}
int main(){
	while(1){
		printf("1.insert\n");
		printf("2.Display\n");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:
				system("cls");
				insert();
				display();
				break;
			case 2:
				printf("\n");
				system("cls");
				display();
				break;	
		}
	}
}
