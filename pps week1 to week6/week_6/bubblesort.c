#include <stdio.h>
int sort(int [],int);
int main(){
	int i,j,n;
	printf("enter length of array :");
	scanf("%d",&n);
	int array[n];
	printf("enter array :");
	for(i=0;i<n;i++){
		printf("---> ");
		scanf("%d",&array[i]);
	}
	sort(array,n);
	printf("after sorting array is : \n");
	for(j=0;j<n;j++){
		printf("%d,",array[j]);
	}
}
int sort(int array[],int n){
	int j,k,temp;
	for(j=0;j<n-1;j++){
		for(k=0;k<n-1-j;k++){
			if(array[k]>array[k+1]){
				temp=array[k];
				array[k]=array[k+1];
				array[k+1]=temp;
				
				
			}
		}
	}
	
}
