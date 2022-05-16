#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void printarray(int array[],int n){
	int i;
	printf("{");
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}printf("}\n");
}
int quicksort(int arry[],int l,int n){
	int pivot,i,j,temp;
	if(l<n){
		pivot=l;
		i=l;
		j=n;
		while(i<j){
			while(arry[i]<=arry[pivot] && i<n){
				i++;
			}
			while(arry[j]>arry[pivot]){
				j--;
			}
			if(i<j){
				temp=arry[i];
				arry[i]=arry[j];
				arry[j]=temp;
			}
		}
		temp=arry[pivot];
      	arry[pivot]=arry[j];
     	arry[j]=temp;
     	quicksort(arry,l,j-1);
      	quicksort(arry,j+1,n);
	}
}
int main (){
	int i,j,n,s;
	printf("enter length of array : ");
	scanf("%d",&n);
	int arry[n];
	
	for(i=0;i<n;i++){
		printf("enter element --> ");
		scanf("%d",&arry[i]);
	}
	printf("original array : ");
	printarray(arry,n);
	quicksort(arry,0,n-1);
	
	
	printarray(arry,n);
	
}



