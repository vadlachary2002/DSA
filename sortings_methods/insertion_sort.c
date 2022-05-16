#include <stdio.h>
int print(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}
int main(){
	int i,j,len,key;
	printf("Enter Length of array:");
	scanf("%d",&len);
	int array[len];
	printf("enter array :\n");
	for(i=0;i<len;i++){
		printf("--> ");
		scanf("%d",&array[i]);
	}
	for(i=1;i<len;i++){
		key=array[i];
		j=i-1;
		while(j>=0 && array[j]>key){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;
		print(array,len);
	}
	for(i=0;i<len;i++){
		printf("%d ",array[i]);
	}
}
