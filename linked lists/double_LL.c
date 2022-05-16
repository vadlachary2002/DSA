#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *llink;
	struct node *rlink;
};

struct node *head=NULL;
int len_list(){
	int count=0;
	struct node *run;
	run=head;
	while(run!=NULL){
		count++;
		run=run->rlink;
	}
	//printf("len=%d\n",count);
	return count;
}
int append(int c){//c for append at node
	struct node *temp,*pass;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data:");
	scanf("%d",&temp->data);
	if(c>len_list()){
		if(head==NULL){
			head=temp;
			head->llink=NULL;
			head->rlink=NULL;
		}else{
			pass=head;
			while(pass->rlink!=NULL){
				pass=pass->rlink;
			}
			pass->rlink=temp;
			temp->llink=pass;
			temp->rlink=NULL;
		}
	}else if(c==0 || c==1){
		
		if(head==NULL){
			head=temp;
			head->llink=NULL;
			head->rlink=NULL;
		}else{
			temp->rlink=head;
			temp->llink=NULL;
			head->llink=temp;
			head=temp;
		}
		
		
		
	}else{
		pass=head;
		struct node *prev;
		prev=pass;
		pass=pass->rlink;
		while(c>2){
			prev=prev->rlink;
			pass=pass->rlink;
			c--;	
		}
		temp->rlink=pass;
		temp->llink=prev;
		prev->rlink=temp;
		pass->llink=temp;
		
	}
}
int display(){
	if(head==NULL){
		printf("no elements in list\n");
		return ;
	}
	struct node *run;
	run=head;
	while(run!=NULL){
		printf("%d\t",run->data);
		run=run->rlink;
	}
	printf("\ncompleted\n");
	return 0;
}

int rev(){
	struct node *temp=head;
	while(temp->rlink!=NULL){
		temp=temp->rlink;
	}
	while(temp->llink!=NULL){
		printf("%d ",temp->data);
		temp=temp->llink;
	}
	printf("%d \n",temp->data);
}
struct node * revDLL(struct node *root){
	if(root->rlink==NULL){
		return root;
	}else{
		struct node *temp=revDLL(root->rlink);
		temp->rlink=root;
		root->llink=temp;
		temp->llink=NULL;
		return temp;
	}
	
}
int del(){
	if(head==NULL){
		printf("no elements in list\n");
		return ;
	}
	int node;
	printf("enter node:");
	scanf("%d",&node);
	if(node==1){
		head=head->rlink;
		head->llink=NULL;
		printf("%d node data deleted\n\n",node);
	}else if(node==len_list()){
		struct node *pass;
		pass=head;
		while(pass->rlink!=NULL){
			pass=pass->rlink;
		}
		pass=pass->llink;
		pass->rlink=NULL;
		printf("last node is deleted\n\n");
	}else if(node>0 && node<len_list()){
		int t=node;
		struct node *pass1,*pass2;
		pass1=head;
		pass2=pass1->rlink;
		node=node-2;
		while(node--){
			pass1=pass1->rlink;
			pass2=pass2->rlink;
		}
		pass1->rlink=pass2->rlink;
		pass2=pass2->rlink;
		pass2->llink=pass1;
		printf("%d node data deleted\n\n",t);
		
	}else{
		printf("node  not found\n\n");
	}
	display();
	return ;
	
	
}
int update(){
	if(head==NULL){
		printf("no elements in list\n");
		return ;
	}
	int node,count=1,charu=0;
	printf("enter node ");
	scanf("%d",&node);
	struct node *run;
	run=head;
	while(run!=NULL){
		if(count==node && node<=len_list()){
			printf("previous data %d\n",run->data);
			printf("enter updated data:");
			scanf("%d",&run->data);
			printf("%d node data is updated with %d\n",node,run->data);
			charu=1;
			break;
			
		}else if (node>len_list()|| node<0){
			printf("node not found\n");
			charu=0;
			break;
		}
		count++;
		run=run->rlink;
	}
}
int search(){
	if(head==NULL){
		printf("no elements in list\n");
		return ;
	}
	int data,count=1,charu=0;
	printf("enter data:");
	scanf("%d",&data);
	struct node *run;
	run=head;
	while(run->rlink!=NULL){
		if(run->data==data){
			printf("%d found at node %d \n",data,count);
			charu=1;
			break;
		}	
		run=run->rlink;
		count++;
		
	}
	if(charu==0){
		printf("%d is not found in list\n",data);
	}
}
int sort(){
	if(head==NULL){
		printf("no elements in list\n");
		return ;
	}
	struct node *i,*j;
	int temp;
	for(i=head;i!=NULL;i=i->rlink){
		for(j=head;j!=NULL;j=j->rlink){
			if(i->data<j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
	printf("\ncompleted\n");
}
int charu(){
	int data;
	printf("enter data to be deleted\n");
	scanf("%d",&data);
	struct node *temp=head,*prev,*cha;
	prev=temp;
	while(temp->rlink!=NULL){
		if(temp->data==data){
			cha=temp;
			prev->rlink=temp->rlink;
			temp=temp->rlink;
			temp->llink=prev;
			cha->rlink=head;
			cha->llink=NULL;
			head->llink=cha;
			head=cha;
			break;
		}
		prev=temp;
		temp=temp->rlink;
	}
}
int main(){
	int ch;
	while(1){
		printf("1.APEND LAST\n");
		printf("2.Display\n");
		printf("3.Append begining\n");
		printf("4.append at a node__\n");
		printf("5.length of list\n");
		printf("6.Delete data\n");
		printf("7.Update list\n");
		printf("8.search\n");
		printf("9.print reverse\n");
		printf("10.sort list\n");
		printf("11.reverse \n");
		printf("12.delete and append begin\n");
		fflush(stdin);
		scanf("%d",&ch);
		switch(ch){
			case 1:
				system("cls");
				append(len_list()+1);
				display();
				break;
			case 2:
				system("cls");
				printf("viewing data\n");
				display();
				break;
			case 3:
				system("cls");
				append(0);
				display();
				break;
			case 4:
				system("cls");
				int n;
				printf("enter node:");
				fflush(stdin);
				scanf("%d",&n);
				append(n);
				break;
			case 5:
				system("cls");
				printf("len of list =%d\n\n",len_list());
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
				rev();
				break;
			case 10:
				system("cls");
				sort();
				display();
				break;
			case 11:
				system("cls");
				revDLL(head);
				display();
				break;
			case 12:
				charu();
				display();
				break;
			default:
				system("cls");
				printf("error\n");
				
		}
	}
	
}
