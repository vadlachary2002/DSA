#include <stdio.h>
int main(){
	int n,i,j;
	printf("Enter Length of array:");
	scanf("%d",&n);
	int array[n],key;
	printf("ENTER %d EEMENTS IN ARRAY  : \n",n);
	for(i=0;i<n;i++){
		printf("Element %d :",i);
		scanf("%d",&array[i]);
	}
	printf("Enter key value : ");
	scanf("%d",&key);
	for(j=0;j<n;j++){
		if(key==array[j]){
			printf("matched at index =%d",j);
			break;
		}
	}
	if(j==n){
		printf("%d is not matched\n",key);
	}
	return 0;
	
}
