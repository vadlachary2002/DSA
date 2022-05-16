#include <stdio.h>
#include <stdlib.h>
#define scan(a) scanf("%d",&a)
struct node {
	int data;
	char color;
	struct node *left,*right;
};

int height(struct node *root){
	if(root==NULL){
		return 0;
	}
	int left=height(root->left);
	int right=height(root->right);
	if(left>right){
		return left+1;
	}else{
		return right+1;
	}
}
int charyDisplay(struct node *run,int spaces){
	if(run!=NULL){
		int i;
		printf("\t%d[%c]\n",run->data,run->color);
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


//insertion 
struct node *createNode(int data,char color){
	struct node *run=malloc(sizeof(struct node ));
	run->data=data;
	run->color=color;
	run->left=NULL;
	run->right=NULL;
	return run;
}
int isChildRed(struct node *root){
	if(root->left==NULL && root->right==NULL){
		return 0;
	}else{
		if(root->left==NULL){
			if(root->color==root->right->color){
				return 1;
			}else{
				return 0;
			}
			
		}else if(root->right==NULL){
			if(root->color==root->left->color){
				return 1;
			}else{
				return 0;
			}
		}
		else{
			if(root->color==root->left->color || root->color==root->right->color){
				return 1;
			}else{
				return 0;
			}
		}
	}
}
int charu=0;
struct node *recolor(struct node *root){
	if(root->left->color=='r'){
		root->left->color='b';
	}else{
		root->left->color='r';
	}
	if(root->right->color=='r'){
		root->right->color='b';
	}else{
		root->right->color='r';
	}
	return root;
}
struct node *insert(struct node *root,int data){
	if(root==NULL){
		return createNode(data,'b');
	}
	if(root->data>data){
		if(root->left==NULL){
			root->left=createNode(data,'r');
		}else{
			root->left=insert(root->left,data);
		}
	}else{
		if(root->right==NULL){
			root->right=createNode(data,'r');
		}else{
			root->right=insert(root->right,data);
		}
	}
	if(isChildRed(root)){
		printf("yes %d child color is red\n",root->data);
		if(charu==0){
			charu=1;
		}
	}else{
		if(charu==1){
			//algo
			// if sibling not there or sibling is black
				//make proper rotation
			//else if sibling is there and it is red
				//recolor siblings and recheck 
			root=recolor(root);
			charu=0;
		}
	}
	
	return root;
	
}
int main(){
	struct node *root=NULL;
	while(printf("choose\n")){
		printf("1.insert\n");
		printf("2.display\n");
		int ch;
		scan(ch);
		switch(ch){
			case 1:
				system("cls");
				int data;
				printf("enter data:");
				scan(data);
				root=insert(root,data);
				charyDisplay(root,0);
				printf("height=%d\n",height(root));
				
		}
		
	}
	
}
