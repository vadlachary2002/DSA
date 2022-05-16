#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	int priority;
	struct node *link;
};
struct node *head=NULL;
int insert(int data,int p){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->priority=p;
	temp->link=NULL;
	if(head==NULL){
		head=temp;
		return ;
	}else{
		struct node *pass=head,*pass2;
		if(pass->link==NULL){
			if(p>pass->priority){
				temp->link=head;
				head=temp;
			}else{
				head->link=temp;
			}
			return ;
		}
		while(p<=pass->priority && pass->link!=NULL){
			pass2=pass;
			pass=pass->link;
		}
		if(pass->link==NULL){
			if(p>pass->priority){
				pass2->link=temp;
				temp->link=pass;
			}else{
				pass->link=temp;
			}
			
		}else if(pass==head){
			temp->link=head;
			head=temp;
		}else{
			pass2->link=temp;
			temp->link=pass;
		}
	}
}

int display(){
	struct node *temp=head;
	if(head==NULL){
		printf("ll is null\n");
		return ;
	}
	while(temp!=NULL){
		printf("%d(%d) ",temp->data,temp->priority);
		temp=temp->link;
	}
	printf("\n\n");
}
int deQueue(){
	if(head==NULL){
		printf("list is empty\n");
		return;
	}
	head=head->link;
	return;
	
}

int outAll(int p){
	struct node *temp=head,*prev;
	if(temp->priority<=p){
		head=NULL;
		return ;
	}
	while(temp->link!=NULL){
		if(temp->priority<=p){
			prev->link=NULL;
			printf("entered");
			return ;
			
		}
		prev=temp;
		temp=temp->link;
		
	}
	if(temp->link==NULL){
		if(temp->priority<=p){
			prev->link=NULL;
		}
		
	}
	
}
int main(){
	while(1){
		int choice;
		printf("1.pEnQueue()\n");
		printf("2.deQueue\n");
		printf("3.display\n");
		printf("4.delete priority less than:\n");
		printf("5.clear Screen\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				system("cls");
				int data,p;
				printf("enter data:");
				scanf("%d",&data);
				printf("enter Priority:");
				scanf("%d",&p);
				insert(data,p);
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
				system("cls");
				int np;
				printf("enter priority value [which whill delete all node which are less than this priority\n]");
				scanf("%d",&np);
				outAll(np);
				display();
				break;
			case 5:
				system("cls");
				break;
				
				
		}
	}
	
}
