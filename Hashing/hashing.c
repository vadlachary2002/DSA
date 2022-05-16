#include <stdio.h>
#include <stdlib.h>
#define L 7
struct hash{
	int data;
	struct hash *link;
};
struct hash *head[L]={NULL};
struct hash *temp=NULL;
struct hash *createNode(int data){
	struct hash *temp;
	temp=(struct hash *)malloc(sizeof(struct hash));
	temp->data=data;
	temp->link=NULL;
	return temp;
}
int insert(){
	int data,hashKey;
	printf("enter data:");
	scanf("%d",&data);
	hashKey=data%L;
	struct hash *newNode;
	newNode=createNode(data);
	if(head[hashKey]==NULL){
		printf("head is null hashhkey=%d\n",hashKey);
		head[hashKey]=newNode;
		return ;
	}
	
	temp=head[hashKey];
	while(temp->link!=NULL){
		temp=temp->link;
	}
	temp->link=newNode;
	return ;
	
}
int display(){
	int i=0;
	while(i<L){
		printf("[%d]-->",i);
		temp=head[i];
		if(temp==NULL){
			printf("NULL");
		}
		while(temp!=NULL){
			printf("%d ->",temp->data);
			temp=temp->link;
		}
		printf("\n");
		i++;
	}
}
int search(int data){
	int hashKey=data%L,count=0;
	struct hash *run;
	run=head[hashKey];
	if(run==NULL){
		printf("%d data not found\n",data);
		return ;
	}
	while(run->link!=NULL ){
		if(run->data==data){
			printf("%d data found at %d node after %d chains\n",data,hashKey,count);
			return ;
		}
		run=run->link;
		count++;
	}
	if(run->data==data){
		printf("found at %d node after %d chains\n",hashKey,count);
		return ;
	}else{
		printf("%d data not found\n\n",data);
	}
	
}
int del(int data){
	int hashKey=data%L;
	struct hash *run,*prev;
	run=head[hashKey];
	if(run==NULL){
		printf("%d data not found\n",data);
		return ;
	}
	if(run->data==data){
		run=run->link;
		head[hashKey]=run;
		printf("%d data deleted\n",data);
		return ;
	}
	prev=run;
	while(run->link!=NULL){
		
		if(run->data==data){
			break;
		}
		prev=run;
		run=run->link;
		
	}
	if(run->link==NULL){
		if(run->data==data){
			prev->link=NULL;
		}else{
			printf("%d data not found\n",data);
			return ;
		}
	}else{
		prev->link=run->link;
	}
	printf("%d data deleted\n",data);
}

int main(){
	while(1){
		printf("1.insert\n");
		printf("2.Display\n");
		printf("3.seacrh\n");
		printf("4.delete\n");
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
				printf("Viewing Data:\n");
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
				scanf("%d",&d);
				del(d);
				break;
			default:
				system("cls");
				printf("invalid click\n\n");
				
		}
		
	}
	
}
