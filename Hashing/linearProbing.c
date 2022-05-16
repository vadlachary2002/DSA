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
int insert(){
	int data,hash,fi=0,key,count=0,collisions=1;
	printf("enter data");
	scanf("%d",&data);
	struct node *newNode;
	newNode=createNode(data);
	hash =data%L;
	key=(hash+fi)%L;
	while(head[key]!=NULL){
		fi++;
		key=(hash+fi)%L;
		count++;
		collisions++;
		if(count>=L){
			break;
		}
	}
	if(count>=L){
		printf("no place is found\n");
	}else{
		head[key]=newNode;
		printf("collisions=%d\n",collisions);
	}
	
	
	
}
int search(int data){
	int hash,fi=0,probes=1,key,count=0;
	hash=data%L;
	key=(hash+fi)%L;
	while(head[key]!=NULL){
		if(head[key]->data==data){
			printf("%d found at index %d\n",data,key);
			return ;
		}
		if(count>=L){
			printf("%d data not found\n",data);
			return ;
		}
		fi++;
		key=(hash+fi)%L;
		count++;
	}
	if(head[key]==NULL){
		printf("%d data not found\n",data);
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
int del(int data){
	int hash,fi=0,probes=1,key,count=0;
	hash=data%L;
	key=(hash+fi)%L;
	while(count<L){
		if(head[key]!=NULL){
			if(head[key]->data==data){
				free(head[key]);
				printf("%d found at index[%d] and deleted\n",data,key);
				head[key]=NULL;
				printf("searches=%d\n",count+1);
				return ;
			}
			
		}
		fi++;
		key=(hash+fi)%L;
		count++;
	}
	printf("%d data not found\n",data);
}
int main(){
	while(1){
		printf("1.insert\n");
		printf("2.Display\n");
		printf("3.Search\n");
		printf("4.Delete\n");
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
			case 3:
				system("cls");
				int data;
				printf("enter data to search:");
				scanf("%d",&data);
				search(data);
				display();
				break;
			case 4:
				system("cls");
				int d;
				printf("enter data to be deleted:");
				scanf("%d",&d);
				del(d);
				display();
				break;
				
		}
		
	}
}
