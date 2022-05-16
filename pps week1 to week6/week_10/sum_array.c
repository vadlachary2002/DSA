#include <stdio.h>
int summation(int *ptr,int n){
	int i,sum=0;
	for(i=0;i<n;i++){
		sum=sum+(*(ptr+i));
	}
	return sum;
}
int main(){
	int n,i,sum;
	printf("enter no of elements in array :");
	scanf("%d",&n);
	int array[n];
	printf("enter elements in array\n");
	for(i=0;i<n;i++){
		printf("->");
		scanf("%d",&array[i]);
	}
	sum=summation(&array,n);
	printf("sum of elements in array is %d",sum);
}


