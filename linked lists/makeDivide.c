#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *link;
};
struct node *root=NULL;
struct node *createNode(int data){
	struct node *run=malloc(sizeof(struct node ));
	run->data=data;
	run->link=NULL;
	return run;
}
int insert(int data){
	if(root==NULL){
		root=createNode(data);
		root->link=root;
		return ;
	}
	struct node *temp=createNode(data);
	struct node *last=root;
	while(last->link!=root){
		last=last->link;
	}
	last->link=temp;
	temp->link=root;
	root=temp;
	
}
int display(struct node *r){
	if(r==NULL){
		printf("empty\n");
		return ;
	}
	
	struct node *run=r;
	do{
		printf("%d ",run->data);
		run=run->link;
	}while(run!=r);
	printf("\n");
}
struct node *divide(struct node *run,int data){
	struct node *temp=run,*prev,*chary;
	while(temp->link!=run){
		if(temp->data==data){
			if(temp==run){
				chary=temp;
				break;
			}
			printf("matched\n");
			chary=temp;
			prev->link=run;
			break;
		}
		prev=temp;
		temp=temp->link;
	}
	struct node *ru=chary;
	
	while(chary->link!=run){
		chary=chary->link;
	}
	chary->link=ru;
	chary=chary->link;
	if(ru==run){
		run=NULL;
	}
	return chary;
	
}
int main(){
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(70);
	insert(80);
	insert(90);
	insert(100);
	display(root);
	struct node *one=root;
	struct node *two=divide(root,100);
	display(one);
	display(two);
}
