#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define L 10
#define M 100
#define scan(a) scanf("%d",&a)
struct vertex{
	int data;
	bool visited;
	int index;
	
};
int matrix[L][L]={0}; //matrix for edges 
struct vertex *array[L]={NULL}; //array for nodes address
int setVisited(int status){
	int i;
	for(i=0;i<L;i++){
		if(array[i]!=NULL){
			array[i]->visited=status;
		}
	}
}

//level order using queues
struct vertex *queue[M]={NULL};
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
void QInsert(struct vertex *run){
	if(rear==M-1){
		printf("queue is overflow\n");
		return ;
	}
	queue[rear++]=run;
}

struct vertex *QFront(){
	if(QEmpty()){
		printf("queue is empty\n");
		return ;
	}else{
		return queue[front];
	}
}
void QDelete(){
	if(QEmpty()){
		printf("queue is empty");
		return ;
	}
	front++;
	return ;
}

struct vertex *createVertex(int data){
	struct vertex *run=malloc(sizeof(struct vertex));
	run->data=data;
	run->visited=0;
	run->index=-1;
	return run;
	
}
int addVertex(){
	int data,i=0;
	printf("enter data:");
	scanf("%d",&data);
	struct vertex *temp=createVertex(data);
	while(i<L){
		if(array[i]==NULL){
			temp->index=i;
			array[i]=temp;
			break;
		}
		i++;
	}
	if(i==L){
		printf("vertices are full\n");
		return ;
	}
	
	 
}
int display(){
	int i=0;
	while(i<L){
		printf("[%d] -- ",i);
		if(array[i]==NULL){
			printf("NULL\n");
		}else{
			printf("%d\t",array[i]->data);
			printf("visited - %d\t",array[i]->visited);
			printf("index - %d\n",array[i]->index);
		}
		i++;
	}
}
int addEdge(int data1,int data2){
	int index1=-1,index2=-1,i=0;
	while(i<L && array[i]!=NULL){
		if(array[i]->data==data1){
			index1=i;
		}
		if(array[i]->data==data2){
			index2=i;
		}
		i++;
	}
	if(index1==-1 || index2==-1){
		printf("no node found with this data vales %d %d\n",data1,data2);
	}else{
		matrix[index1][index2]=1;
		matrix[index2][index1]=1;
		printf("edge added between %d------%d\n\n",data1,data2);
	}
}

int printMatrix(){
	printf("\tAdjancency Matrix\n");
	int i,j;
	for(i=0;i<L;i++){
		if(array[i]!=NULL){
			printf("\t%d",array[i]->data);
		}
		
	}
	printf("\n");
	for(i=0;i<L;i++){
		if(array[i]!=NULL){
			printf("  %d\t",array[i]->data);
		}
		
		for(j=0;j<L;j++){
			if(array[i]!=NULL && array[j]!=NULL){
				printf("%d\t",matrix[i][j]);
			}
			
			
		}
		printf("\n");
	}
}
int findIndex(int data){
	int i;
	for(i=0;i<L;i++){
		if(array[i]->data==data && array[i]!=NULL){
//			printf("index=%d\n",array[i]->index);
			return array[i]->index;
		}
	}
	return -1;
}

int levelOrder(int data){	
	int index=findIndex(data),i=0;
//	printf("index=%d\n",index);
	if(index==-1){
		printf("entered %d data not found in graph\n",data);
		return ;
	}
	setVisited(0);
	QInsert(array[index]);
	while(!QEmpty()){
		struct vertex *current=QFront();
		if(current->visited==0 ){
			printf("%d\t",current->data);
			current->visited=1;
		}
		i=0;
		index=current->index;
		while(i<L){
			if(matrix[index][i]==1){
//				printf("i=%d\t",i);
				if(array[i]->visited==0 && array[i]!=NULL){
					QInsert(array[i]);
				}	
			}
			i++;
		}
		QDelete();
	}
	printf("\n\n");
}
int dfs(int index){
	if(array[index]->visited==0){
		printf("%d ",array[index]->data);
		array[index]->visited=1;
	}else{
		return ;
	}
	int i=0;
	while(i<L){
		if(matrix[index][i]==1){
			dfs(i);
		}
		i++;
	}

	
	
}
int delEdge(int data1,int data2){
	int i,j,index1,index2;
	index1=findIndex(data1);
	index2=findIndex(data2);
	if(index1!=-1 && index2!=-1){
		matrix[index1][index2]=0;
		matrix[index2][index1]=0;
		printf("%d------%d\tedge is deleted\n",array[index1]->data,array[index2]->data);
	}else{
		printf("not data found %d %d\n",data1,data2);
		
	}
	return ;
	
	
}
int adjList(int data){
	int index=findIndex(data),i=0;
	printf("%d ->",array[index]->data);
	while(i<L){
		if(matrix[index][i]==1){
			printf("%d -- ",array[i]->data);
		}
		i++;
	}
	printf("\n\n");
	
}
int main(){
	while(1){
		printf("1.add vertex\n");
		printf("2.add edge\n");
		printf("3.level order\n");
		printf("4.depth for search\n");
		printf("5.display\n");
		printf("6.printf adj matrix\n");
		printf("7.delete  edge\n");
		printf("8.adj list[all connected nodes of data]\n");
		int ch;
		scanf("%d",&ch);
		switch(ch){
			case 1:
				system("cls");
				addVertex();
				display();
//				printMatrix();
				break;
			case 2:
				system("cls");
				int d1,d2;
				printf("enter 2 data values which you want connection:\ndata1->");
				scanf("%d",&d1);
				printf("data2->");
				scanf("%d",&d2);
				addEdge(d1,d2);
				printMatrix();
				break;
			case 3:
				system("cls");
				int data;
				printf("enter starting node data :");
				scanf("%d",&data);
				levelOrder(data);
				break;
			case 4:
				system("cls");
				int dfData;
				printf("enter which node to start:");
				scanf("%d",&dfData);
				setVisited(0);
				dfs(findIndex(dfData));
				printf("\n");
				break;
				
				
			case 5:
				system("cls");
				display();// not important
				break;
			case 6:
				system("cls");
				printMatrix();//not important
				break;
			case 7:
				system("cls");
				int val1,val2;
				printf("enter data1->\n");
				scanf("%d",&val1);
				printf("enter data2->");
				scanf("%d",&val2);
				delEdge(val1,val2);
				
				printMatrix();
				break;
			case 8:
				system("cls");
				int datatoggle;
				printf("enter data :");
				scan(datatoggle);
				adjList(datatoggle);
				break;
				
				
			default :
				system("cls");
				printf("\aError...!\n");
			
		}
	}
}
