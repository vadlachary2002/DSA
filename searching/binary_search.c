#include <stdio.h>
int sort(int [],int);
int main(){
	int i,l,h,len;
	printf("enter length od arry:");
	scanf("%d",&len);
	int array[len];
	printf("enter array :\n");
	for(i=0;i<len;i++){
		printf("ele[%d]->",i);
		scanf("%d",&array[i]);
	}
	
	sort(array,len);
	printf("array after sorted  \n");
	for(l=0;l<len;l++){
		printf("%d ",array[l]);
	}
	int key;
	printf("\nenter search element :  ");
	scanf("%d",&key);
	l=0;
	h=len-1;
	while(l<=h){
		int mid;
		mid=l+(h-l)/2;
		if(key<array[0] || key>array[len-1]){
			printf("%d data is not found\n",key);
			break;
		}
		if(key<array[mid]){
			h=mid-1;
		}else if(key>array[mid]){
			l=mid+1;
		}else if(key==array[mid]){
			printf("found at index %d",mid);
			break;
		}
	}
}
int sort(int array[],int l){
	int j,k,temp;
	for(j=0;j<l;j++){
		for(k=0;k<l-j;k++){
			if(array[k]>array[k+1]){
				temp=array[k];
				array[k]=array[k+1];
				array[k+1]=temp;
			}
		}
	}
}
