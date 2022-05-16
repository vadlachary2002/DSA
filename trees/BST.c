#include <stdio.h>
#include <stdlib.h>
#define L 100
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
	
}Node;

Node *array[L];
int front=0,rear=0;
int QEmpty(){
	if(front==rear){
		front=0;
		rear=0;
		return 1;
	}else{
		return 0;
	}
}
void QInsert(Node *run){
	if(rear==L-1){
		printf("queue is overflow\n");
		return ;
	}
	array[rear]=run;
	rear++;
}
Node *QFront(){
	if(QEmpty()){
		printf("queue is empty\n");
		return ;
	}else{
		return array[front];
	}
}
void QDelete(){
	if(QEmpty()){
		printf("queue is empty");
		return ;
	}
//	Node *temp=array[front];
	front++;
	return ;
}
Node *createNode(int data){
	Node *run=malloc(sizeof(Node));
	run->data=data;
	run->left=NULL;
	run->right=NULL;
	return run;
}
Node *insert(Node *root,int data){
	if(root==NULL){	
		return createNode(data);
	}
	if(root->data>data){
		root->left=insert(root->left,data);
	}else{
		root->right=insert(root->right,data);
	}
	return root;
}
Node *findMin(Node *root){
	if(root->left==NULL){
		return root;
	}else{
		return findMin(root->left);
	}
}

//delete node in three cases

Node * del(Node *root,int data){
	if(root==NULL){
		return root;
	}else if(root->data>data){
		root->left=del(root->left,data);
	}else if(root->data<data){
		root->right=del(root->right,data);
	}else{
		//data mathches
		if(root->left==NULL){
			if(root->right==NULL){
				free(root);
				root=NULL;
			}else{
				Node *temp=root;
				root=root->right;
				free(temp);
				temp=NULL;
			}
		}else if(root->right==NULL){
			Node *temp=root;
			root=root->left;
			free(temp);
			temp=NULL;
		}else{
			Node *temp=findMin(root->right);
			printf("min value=%d\n",temp->data);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
			
		}
	}
	return root;
}


//display for me
int charyDisplay(Node *run,int spaces){
	if(run!=NULL){
		int i;
		printf("\t%d\n",run->data);
		for(i=0;i<spaces;i++){
			printf(" ");
		}
		printf("leftnode : ");
		charyDisplay(run->left,spaces+1);
		for(i=0;i<spaces;i++){
			printf(" ");
		} 
		printf("rightnode : ");
		charyDisplay(run->right,spaces+1);	
	}else{
		printf("null");
	}
	printf("\n");
}


int search(Node *root,int data){
	if(root==NULL){
		printf("%d data not found\n",data);
		return ;
	}
	if(root->data==data){
		printf("%d data found\n");
	}else{
		if(root->data>data){
			search(root->left,data);
		}else{
			search(root->right,data);
		}
	}
}
void preorder(Node  *root){
	if(root==NULL){
		return ;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	return ;
}
void inorder(Node  *root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	return ;
}
void postorder(Node  *root){
	if(root==NULL){
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	return ;
}

//level order 

void levelOrder(Node *root){
	if(root==NULL){
		return ;
	}
	QInsert(root);
	while(!QEmpty()){
		Node *current=QFront();
		printf("%d ",current->data);
		if(current->left!=NULL){
			QInsert(current->left);
		}if(current->right!=NULL){
			QInsert(current->right);
		}
		QDelete();
	}
}

int height(Node *root){
	if(root==NULL){
		return 0;
	}else{
		int left=height(root->left);
		int right=height(root->right);
		if(right>left){
			return right+1;
		}else{
			return left+1;
		}
	}
}
int main(){
	Node *root=NULL;
	while(1){
		printf("\n1.insert\n");
		printf("2.search\n");
		printf("3.preorder traverse\n");
		printf("4.inorder traverse\n");
		printf("5.postorder traverse\n");
		printf("6.delete data\n");
		printf("7.charyDisplay()\n");
		printf("8.level order\n->");
		printf("9.height of tree\n");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:
				system("cls");
				int data;
				printf("enter data\n");
				scanf("%d",&data);
				root=insert(root,data);
				printf("inserted\n");
				charyDisplay(root,0);
				break;
			case 2:
				fflush(stdin);
				int d;
				printf("enter data to search:");
				scanf("%d",&d);
				search(root,d);
				break;
			case 3:
				printf("preorder traverse \n");
				preorder(root);
				break;
			case 4:
				printf("inorder traverse\n");
				inorder(root);
				break;
			case 5:
				printf("postorder traverse\n");
				postorder(root);
				break;
			case 6:
				fflush(stdin);
				int val;
				printf("enter data:");
				scanf("%d",&val);
				del(root,val);
				break;
			case 7:
				system("cls");
				charyDisplay(root,0);
				break;
			case 8:
				printf("level order traverse\n");
				levelOrder(root);
			case 9:
				printf("height of tree=%d\n",height(root));
					
		}
		
	}
}
