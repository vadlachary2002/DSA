#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *link;
};
struct node *head=NULL;
int len_list(){
	struct node *run;
	int count=0;
	run=head;
	if(run==NULL){
		return 0;
	}else{
		do{
			run=run->link;
			count++;
		}while(run!=head);
		return count;
	}
}
int append(int c){
	struct node *temp,*pass;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&temp->data);
	if(head==NULL){
		head=temp;
		head->link=head;
	}else{
		if(c>len_list() || c==0|| c==1){
			pass=head;
			while(pass->link!=head){
				pass=pass->link;
			}
			pass->link=temp;
			temp->link=head;
			if(c==0 || c==1){
				head=temp;
			}
		}else{
			pass=head;
			while(c>2){
				pass=pass->link;
				c--;
			}
			temp->link=pass->link;
			pass->link=temp;
			
		}
	}
	display();
	return;
}
int display(){
	struct node *run;
	run=head;
	if(run==NULL){
		printf("list is empty\n");
		return;
	}
	do{
		printf("%d\t",run->data);
		run=run->link;
	}while(run!=head);
	printf("\ncompleted\n");
}
int del(){
	if(head==NULL){
		printf("list is empty\n");
		return ;
	}
	int node ;
	printf("enter node:");
	scanf("%d",&node);
	struct node *prev,*pass;
	if(node==1){
		if(head->link==head){
			printf("deleted %d\n",head->data);
			head=NULL;
			return ;
		}
		prev=head;
		pass=prev->link;
		while(prev->link!=head){
			prev=prev->link;
		}
		prev->link=pass;
		printf("deleted %d\n",head->data);
		head=pass;
	}else{
		if(head->link==head){
			printf("invaid node value\n");
			return ;
		}
		
		prev=head;
		pass=prev->link;
		while(node>2){
			prev=prev->link;
			pass=pass->link;
			node--;
			
		}
		printf("deleted %d\n",pass->data);
		prev->link=pass->link;
		
	}
	display();
	
}
int update(){
	if(head==NULL){
		printf("no elements to update\n");
		return;
	}
	int node;
	printf("enter node:");
	scanf("%d",&node);
	if(node>0 && node<=len_list()){
		struct node *pass;
		pass=head;
		while(node>1){
			pass=pass->link;
			node--;
		}
		printf("previous data %d\n",pass->data);
		printf("enter new data:");
		scanf("%d",&pass->data);
		system("cls");
		printf("updated node %d with %d data\n",node,pass->data);
		
	}else{
		printf("node not found\n");
	}
	display();
	return ;
}
int search(){
	if(head==NULL){
		printf("no elements to search\n");
		return ;
	}
	int data;
	printf("enter data:");
	scanf("%d",&data);
	struct node *run;
	int node=1;
	run=head;
	while(run->data!=data && run->link!=head){
		run=run->link;
		node++;
	}
	if(run->data==data){
		printf("%d found at node %d\n",data,node);
	}else{
		printf("%d data not found\n",data);
	}
	return;
}
int rev(struct node* run){
	if(run->link==head){
		printf("%d\t",run->data);
		return;
	}else{
		rev(run->link);
		printf("%d\t",run->data);
	}
	
}
int sort(){
	struct node *i,*j;
	int temp;
	for(i=head;i->link!=head;i=i->link){
		//printf("outer\n");
		for(j=i->link;j->link!=head->link;j=j->link){
			//printf("inner\n");
			if(i->data>j->data){
				//printf("if\n");
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
	printf("sorted list\n");
	display();
}
int main(){
	while(1){
		int ch;
		printf("1.append_last\n");
		printf("2.display\n");
		printf("3.append_begining\n");
		printf("4.append_at_node_\n");
		printf("5.length_of_list\n");
		printf("6.Delete_node\n");
		printf("7.update_node\n");
		printf("8.search\n");
		printf("9.reverse_order\n");
		printf("10.sort_list\n");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch){
			case 1:
				system("cls");
				append(len_list()+1);
				break;
			case 2:
				system("cls");
				printf("viewing data\n");
				display();
				break;
			case 3:
				system("cls");
				append(0);
				break;
			case 4:
				system("cls");
				int c;
				printf("enter node :");
				fflush(stdin);
				scanf("%d",&c);
				append(c);
				break;
				
			case 5:
				system("cls");
				printf("len of list %d\n",len_list());
				break;
			case 6:
				system("cls");
				del();
				break;
			case 7:
				system("cls");
				update();
				break;
			case 8:
				system("cls");
				search();
				break;
			case 9:
				system("cls");
				rev(head);
				printf("\ncompleted\n");
				break;
			case 10:
				system("cls");
				sort();
				break;
			default:
				system("cls");
				printf("error!...\n");
				
		}
	}
	
	
}
