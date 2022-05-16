#include <stdio.h>
#include <stdlib.h>
#define scan(a) scanf("%d",&a) 
struct node {
	int data;
	struct node *left,*right;
};

//display for me
int charyDisplay(struct node *run,int spaces){
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
struct node *createNode(int data){
	struct node *run=malloc(sizeof(struct node));
	run->data=data;
	run->left=NULL;
	run->right=NULL;
	return run;
}
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
int balFactor(struct node *root){
	if(root==NULL){
		return 0;
	}
	int left=height(root->left);
	int right=height(root->right);
	return left-right;
}
struct node *llrot(struct node *root){
	struct node *temp=root;
	temp=temp->left;
	root->left=temp->right;
	temp->right=root;
	root->right=NULL;
	return temp;
}
struct node *lrrot(struct node *root){
	struct node *a;
	a=root->left->right;
	a->left=root->left;
	a->left->right=NULL;
	root->left=a->right;
	a->right=root;
	return a;
}
struct node *rrrot(struct node *root){
	struct node *temp=root;
	temp=temp->right;
	root->right=temp->left;
	temp->left=root;
	root->left=NULL;
	return temp;
}
struct node *rlrot(struct node *root){
	struct node *a;
	a=root->right->left;
	a->right=root->right;
	a->right->left=NULL;
	root->right=a->left;
	a->left=root;
	return a;
	
}
struct node *makeAVL(struct node *root){
	printf("okok");
	int factor=balFactor(root);
	printf("factor=%d\n",factor);
	if(factor==1 || factor==0 || factor==-1){
		if(root!=NULL){
			printf("balanced at %d\n",root->data);
		}
		printf("mmm");
		return root;
	}else{
		printf("not balanced at %d factor=%d\n",root->data,factor);
		if(factor>0){
			if(root->left->left==NULL){
				printf("lr\n");
				root=lrrot(root);
			}else{
				if(height(root->left->left)<height(root->left->right)){
					printf("lr\n");
					root=lrrot(root);
				}else{
					printf("ll\n");
					root=llrot(root);
				}
				
			}
		}else{
			if(root->right->right==NULL){
				printf("rl\n");
				root=rlrot(root);
			}else{
				if(height(root->right->left)>height(root->right->right)){
					printf("rl\n");
					root=rlrot(root);
				}else{
					printf("rr\n");
					root=rrrot(root);
				}
			}
		}
		return root;
	}
}
struct node *insert(struct node *root,int data){
	if(root==NULL){
		root=createNode(data);
		return root;
	}
	if(root->data>data){
		if(root->left==NULL){
			root->left=createNode(data);
		}else{
			root->left=insert(root->left,data);
		}
	}else{
		if(root->right==NULL){
			root->right=createNode(data);
		}else{
			root->right=insert(root->right,data);
		}
	}
	root=makeAVL(root);
	return root;
}
void preorder(struct node *root){
	if(root==NULL){
		return ;
	}
	printf("%d ",root->data );
	preorder(root->left);
	preorder(root->right);
}
struct node *findMin(struct node *root){
	if(root->left==NULL){
		return root;
	}else{
		return findMin(root->left);
	}
}
struct node*del(struct node *root,int data){
	if(root==NULL){
		return root;
	}
	if(root->data>data){
		root->left=del(root->left,data);
	}else if(root->data<data){
		root->right=del(root->right,data);
	}else{
		//data matches
		if(root->left==NULL){
			if(root->right==NULL){
				free(root);
				root=NULL;
			}else{
				struct node *run=root;
				root=root->right;
				free(run);
				run=NULL;
			}
		}else{
			if(root->right==NULL){
				struct node *runn=root;
				root=root->left;
				free(runn);
				runn=NULL;
			}else{
				struct node *temp=findMin(root->right);
				root->data=temp->data;
				root->right=del(root->right,temp->data);
			}
		}
	}
	root=makeAVL(root);
	return root;
}
int main(){
	struct node *root=NULL;
	
	while(printf("choose\n")){
		printf("0.auto insert(14,17,11,7,53,4,13,12,8,60,19,16,20)\n");
		printf("1.insert\n");
		printf("2.preorder\n");
		printf("3.height of tree\n");
		printf("4.delete node\n");
		int ch;
		scan(ch);
		switch(ch){
			case 0:
				root=insert(root,14);
				root=insert(root,11);
				root=insert(root,17);
				root=insert(root,7);
				root=insert(root,53);
				root=insert(root,4);
				root=insert(root,13);
				root=insert(root,12);
				root=insert(root,8);
				root=insert(root,60);
				root=insert(root,19);
				root=insert(root,16);
				root=insert(root,20);
				charyDisplay(root,0);
				printf("height=%d\n",height(root));
				break;
			case 1:
				system("cls");
				int data;
				printf("enter data:");
				scan(data);
				root=insert(root,data);
				charyDisplay(root,0);
				printf("height=%d\n",height(root));
				break;
			case 2:
				system("cls");
				preorder(root);
				break;
			case 3:
				printf("height=%d\n",height(root));
				break;
			case 4:
				system("cls");
				int d;
				printf("enter data to delete:");
				scan(d);
				root=del(root,d);
				charyDisplay(root,0);
				printf("height=%d\n",height(root));
				break;
				
				
		}
	}	
}
