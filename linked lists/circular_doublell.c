#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *llink;
	struct node *rlink;
};
struct node *head=NULL;
int len_list(){
	if(head==NULL){
		return 0;
	}else{
		struct node *run=head;
		int count=0;
		do{
			count++;
			run=run->rlink;
		}while(run!=head);
		return count;
	}
}
int insert(int data,int node){
	struct node *temp,*pass;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	if(head==NULL){
		head=temp;
		temp->llink=head;
		temp->rlink=head;
		return ;
	}
	if(node==0 || node>=len_list()){
		temp->rlink=head;
		temp->llink=head->llink;
		head->llink=temp;
		head=head->llink;
		temp=temp->llink;
		temp->rlink=head;
		if(node>len_list()){
			head=head->rlink;
		}
	}else{
		hbu
	}
	
	
}
int display(){
	struct node *run;
	if(head==NULL){
		printf("list is empty\n");
		return;
	}
	run=head;
	do{
		printf("%d \t",run->data);
		run=run->rlink;
	}while(run!=head);
	printf("\n\n");
}
int main(){
	insert(10,0);//insert at last
	insert(20,0);
	insert(30,99);
	insert(40,0);
	
	display();

	printf("len of list=%d\n",len_list());
}
