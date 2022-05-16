struct charu{
        int data,hd;
        struct charu *left,*right;
};
struct charu * createNode(int data,int hd){
        struct charu *newNode=malloc(sizeof(struct charu));
        newNode->data=data;
        newNode->hd=hd;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
    }
 struct charu* preorder(struct node *root,struct charu *newr,int parent){
        if(root==NULL){
            return NULL;
        }
        newr=createNode(root->data,parent);
        newr->left=preorder(root->left,newr->left,parent-1);
        newr->right=preorder(root->right,newr->right,parent+1);
        return newr;
    }

struct charu *Queue[500]={NULL};
int front=0,rear=0;
void Qinsert(struct charu *temp){
    Queue[rear++]=temp;
}
struct charu *Qfront(){
    return Queue[front];
}
void Qdelete(){
    front++;
    if(front==rear){
        front=0;
        rear=0;
    }
    return ;
}
int Qempty(){
    if(front==rear){
        front=0;
        rear=0;
        return 1;
    }else{
        return 0;
    }
}
int stack1[500],top1=-1,stack2[500],top2=-1,stack3[500],top3=-1;
void push1(int data){
    stack1[++top1]=data;
    return ;
}
void push2(int data){
    stack2[++top2]=data;
    return ;
}
void push3(int data){
    stack3[++top3]=data;
    return ;
}
int pop1(){
    return stack1[top1--];
}
int pop2(){
    return stack2[top2--];
}
int pop3(){
    return stack3[top3--];
}
void levelorder(struct charu *root){
    if(root==NULL){
        return ;
    }
    Qinsert(root);
    int smallest=1000,greatest=-1000;
    struct charu *current=root;
    while(!Qempty()){
        current=Qfront();
        if(current->hd<smallest){
            push1(current->data);
            smallest=current->hd;
            if(greatest==-1000){
                greatest=current->hd;
            }
            
        }
        if(current->hd>greatest && current->hd!=0){
            push2(current->data);
            greatest=current->hd;
        }
        if(current->left!=NULL){
            Qinsert(current->left);
        }if(current->right!=NULL){
            Qinsert(current->right);
        }
        Qdelete();
        
        
    }
    while(top1>=0){
        printf("%d ",pop1());
    }while(top2>=0){
        push3(pop2());
    }
    int x;
    
    while(top3>=0){
        printf("%d ",pop3());
    }
    return ;
}
void topView( struct node *root) {
    
    struct charu *newRoot=NULL;
    newRoot=preorder(root,newRoot,0);
    levelorder(newRoot);
}

