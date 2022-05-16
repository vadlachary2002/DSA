#include <stdio.h>
int print(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}
int main(){
	int i,j,k,min,temp,len;
	printf("Enter Length of array:");
	scanf("%d",&len);
	int array[len];
	printf("enter array : \n");
	for(i=0;i<len;i++){
		printf("--> ");
		scanf("%d",&array[i]);
	}
//	printf("%d",len);
	for(j=0;j<len-1;j++){
		min=j;
		for(k=j+1;k<len;k++){
			if(array[k]<array[min]){
				min =k;
			}
		}
		temp=array[j];
		array[j]=array[min];
		array[min]=temp;
		print(array,len);
		
	}
	printf("after sorting array :\n");
	for(k=0;k<len;k++){
		printf("%d ",array[k]);
	}
	return 0;
}
