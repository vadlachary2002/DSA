#include <stdio.h>
#include <stdlib.h>
#define L 10
struct node {
	int data;
};
struct node *head[L]={NULL};
struct node *createNode(int data){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	return temp;
}
int count=0;
int insert(){
	int data,hash1,hash2,fi=0,key,probes=1;
	printf("enter data");
	scanf("%d",&data);
	struct node *newNode;
	newNode=createNode(data);
	hash1=(2*data+3)%L;
	key=hash1;
	while(head[key]!=NULL){
		fi++;
		hash2=7-(data%7);
		key=(hash1+hash2*fi)%L;
		if(fi==L-1){
			if(count>=L){
				printf("table filled\n");
				return ;
			}
			printf("probes=%d\n",probes);
			printf("not possible\n");
			return ;
		}
		
		probes++;
	}
	if(count>=L){
		printf("no place is found\n");
	}else{
		head[key]=newNode;
		count++;
		printf("key-%d\n",key);
		printf("\nprobes=%d\n",probes);
	}
	
	
	
}
int display(){
	int i=0;
	while(i<L){
		if(head[i]==NULL){
			printf("%d   -NULL\n",i);
		}else{
			printf("%d   -%d \n",i,head[i]->data);
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
