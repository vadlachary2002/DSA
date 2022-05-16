#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int data;
	struct node *link;
};
struct node *head=NULL;

int append(int c){
	struct node *temp,*pass;
	temp=(struct node*)malloc(sizeof(struct node));
//	pass=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(c==0){//0 indicates append at last
		if(head==NULL){
			head=temp;
			return;
		}
			pass=head;
			while(pass->link!=NULL){
				pass=pass->link;
			}
			pass->link=temp;	
		
	}else if(c==1){ //1 indicates append at begining
		temp->link=head;
		head=temp;		
	}else {
		struct node *pass2;
		pass=head;
		pass2=pass->link;
		while(c>2){
			pass=pass->link;
			pass2=pass2->link;
			c--;
		}
		pass->link=temp;
		temp->link=pass2;
	}
	display();
}
int display(){
	struct node *travel;
	travel=(struct node*)malloc(sizeof(struct node));
	travel=head;
	if(head==NULL){
		printf("list is empty\n");
		return;
	}
	while(travel!=NULL){
		printf("%d\t",travel->data);
		travel=travel->link;
	}
	printf("\ncompleted\n");
}
int len_list(){
	struct node *run;
	int count=0;
	run=head;
	while(run!=NULL){
		count++;
		run=run->link;
	}return count;
}
int del(){
	int node;
	printf("enter node:");
	scanf("%d",&node);
	if(node==1){
		head=head->link;
		printf("%d node data deleted\n",node);
	}else if(node==len_list()){
		struct node *pass1,*pass2;
		pass1=head;
		pass2=pass1->link;
		while(pass2->link!=NULL){
			pass1=pass1->link;
			pass2=pass2->link;
		}
		pass1->link=NULL;
		printf("%d node data deleted\n",node);
	}else if(node>0 && node<len_list()){
		int t=node;
		node=node-2;
		struct node *pass1,*pass2;
		pass1=head;
		pass2=pass1->link;
		while(node--){
			pass1=pass1->link;
			pass2=pass2->link;
		}
		pass1->link=pass2->link;
		printf("%d node data deleted\n",t);
	}else{
		printf("node not found\n");
	}
	display();
	return 0;	
}
int update(){
	int c;
	printf("1.do u want to chage the data of a node by entering node :\n");
	printf("2.do u want to chnage tha data by entering data\n->");
	scanf("%d",&c);
	struct node *pass;
	pass=head;
	if(c==1){
		int n;
		printf("enter node number:");
		scanf("%d",&n);
		n--;
		while(n>0 && pass!=NULL){
			n--;
			pass=pass->link;
		}
		if(pass==NULL){
			printf("node not found\n");
		}else if(n==0){
			printf("previous data is %d\n",pass->data);
			printf("enter new data:");
			scanf("%d",&pass->data);
			printf("updated successfully\n");
		}else{
			printf("something wrong\n");
		}
	}else if(c==2){
		int pdata,ndata;
		if(head==NULL){
			printf("list is empty\n");
			return;
		}
		printf("enter  previous data:");
		scanf("%d",&pdata);
		while(pass->data!=pdata && pass->link!=NULL ){
			printf("while\n");
			pass=pass->link;
		}
		if(pass->data==pdata){
			printf("found tha data \nenter new data:");
			scanf("%d",&ndata);
			pass->data=ndata;
			printf("updated successfully\n");
		}else{
			printf("no %d data found in list\n",pdata);
		}
	}else{
		printf("entered wrong number\n");
	}
}
int search(){
	int data,i=0;
	if(head==NULL){
		printf("list is empty\n");
		return;
	}
	printf("enter search element:");
	scanf("%d",&data);
	struct node *pass;
	pass=head;
	while(pass!=NULL){
		if(pass->data==data){
			printf("%d found at index %d\n",data,i);
			break;
		}
		pass=pass->link;
		i++;
	}
}
//int rev(struct node *h){
//	struct node *run;
//	run=h;
//	if(run==NULL){
//		return;	
//	}else{
//		rev(run->link);
//		printf("%d\t",run->data);
//	}
//}
int rev(struct node *run){
	if(run->link!=NULL)
		rev(run->link);
	printf("%d ",run->data);
	
	return ;
	
}
struct node *reverse(struct node *head){
	if(head->link==NULL){
		return head;
	}else{
		struct node *temp,*run;
		temp=head;
		struct node *last=reverse(head->link);
		temp->link=NULL;
		run=last;
		while(run->link!=NULL){
			run=run->link;
		}
		run->link=temp;
		return last;
	}
}
int sort(){
	if(head==NULL){
		printf("no elemens to sort\n");
		return ;
	}
	struct node *i,*j;
	int temp;
	for(i=head;i!=NULL;i=i->link){
		for(j=i;j!=NULL;j=j->link){
			if(i->data>j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;		
			}
		}
	}
	printf("\ncompleted\n");
}
int main(){
	while(1){
		int choice;
		printf("1.APEND LAST\n");
		printf("2.Display\n");
		printf("3.Append begining\n");
		printf("4.append at a node__\n");
		printf("5.length of list\n");
		printf("6.Delete data\n");
		printf("7.Update list\n");
		printf("8.search\n");
		printf("9.reverse order\n");
		printf("10.sort list\n");
		printf("11.count node\n");
		printf("12.reverse the list\n");
		fflush(stdin);
		scanf("%d",&choice);
		switch(choice){
			case 1:
				system("cls");
				printf("Appending\n");
				append(0);
				display();
				break;
			case 2:
				system("cls");
				printf("Viewing Data\n");
				display();
				break;
			case 3:
				system("cls");
				printf("Append Begining\n");
				append(1);
				break;
			case 4:
				system("cls");
				int _pos;
				printf("enter position :");
				fflush(stdin);
				scanf("%d",&_pos);
				if(_pos==1 || _pos==0){
					append(1);
				}else if(_pos>len_list()){
					
					append(0);
				}
				else{
					if(_pos<0){
						printf("index should be positive\n");
					}else{
						append(_pos);
					}	
				}
				break;
			case 5:
				system("cls");
				display();
				printf("Length of list  = %d \n",len_list());
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
				display();
				break;
			case 11:
				system("cls");
				printf("length of list %d\n\n",len_list());
				break;
			case 12:
				system("cls");
				display();
				head=reverse(head);
				printf("reversed\n");
				display();
				break;
			default:
				system("cls");
				printf("Error!..\n");
		}
	}
}
