#include <stdio.h>
#define charyMain main
#define scan(a) scanf("%d",&a)
int swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int printArray(int *array,int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}
//minheap
int minInsertHeap(int *array,int index){
	while(index>=1){
		int parent=(index-1)/2;
		if(array[parent]>array[index]){
			swap(&array[parent],&array[index]);
		}
		index=parent;		
	}
}

int minHepify(int *array,int n){
	int i=0;
	int leftChild,rightChild,greatest;
	while(i<n){
//		printf("ok");
		leftChild=2*i+1;
		rightChild=2*i+2;
		greatest=i;
		if(array[rightChild]<=array[leftChild] && rightChild<n){
			greatest=rightChild;
		}else if(array[leftChild]<array[rightChild] && leftChild<n){
			greatest=leftChild;
		}
		if(greatest!=i){
//			printf("small %d !=i $%d\n",smallest,i);
			swap(&array[greatest],&array[i]);
			i=greatest;
		}else{
			i=n;
		}
	}
}
//max heap
int maxInsertHeap(int *array,int index){
	while(index>=1){
		int parent=(index-1)/2;
		if(array[parent]<array[index]){
			swap(&array[parent],&array[index]);
		}
		index=parent;		
	}
}
int print(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int maxHepify(int *array,int n){
	int i=0;
	int leftChild,rightChild,smallest;
	while(i<n){
//		printf("ok");
		leftChild=2*i+1;
		rightChild=2*i+2;
		smallest=i;
		if(array[rightChild]>=array[leftChild] && rightChild<n){
			smallest=rightChild;
		}else if(array[leftChild]>array[rightChild] && leftChild<n){
			smallest=leftChild;
		}
		if(smallest!=i){
//			printf("small %d !=i $%d\n",smallest,i);
			swap(&array[smallest],&array[i]);
			i=smallest;
		}else{
			break;
		}
	}
}
int charyMain(){
	int n,i;
	printf("enter length of array:");
	scan(n);
	int array[n],index=0;
	ch:
	printf("1.Build Max heap[decending order]\n");
	printf("2.Build Min heap[ascending order]\n->");
	int choice;
	scan(choice);
	if(choice==1){
		goto maxheap;
	}else if(choice==2){
		goto minheap;
	}else{
		system("cls");
		printf("Enter Valid Choice\n");
		goto ch;
	}
	maxheap:
	for(i=0;i<n;i++){
		printf("->");
		scan(array[index++]);
		maxInsertHeap(array,index-1);
		printf("level order :");
		print(array,index);
	}
	printf("decending order\n");
	while(index>0){
//		printf("%d ",array[0]);
		swap(&array[0],&array[index-1]);
		maxHepify(array,index-1);
		index--;
	}
	if(array[0]>array[1]){
		swap(&array[0],&array[1]);
	}
	printArray(array,n);
	return ;
	minheap:
	for(i=0;i<n;i++){
		printf("->");
		scan(array[index++]);
		minInsertHeap(array,index-1);
		printf("level order :");
		print(array,index);
	}
	printf("asscending order\n");
	while(index>0){
		printf("%d ",array[0]);
		array[0]=array[index-1];
		minHepify(array,index-1);
		index--;
	}
	
	
}
