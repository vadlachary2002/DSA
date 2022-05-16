#include <stdio.h>
#define scan(a) scanf("%d",&a)
int l;
int print(int *array){
	int i;
	for(i=0;i<l;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}
int merge(int array[],int l,int m,int r){
	int i,j,k, n1=m-l+1, n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=array[l+i];
	}for(j=0;j<n2;j++){
		R[j]=array[m+1+j];
	}
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			array[k++]=L[i++];
		}else{
			array[k++]=R[j++];
		}
	}
	while(i<n1){
		array[k++]=L[i++];
	}while(j<n2){
		array[k++]=R[j++];
	}
}
int pass=1;
int merge_sort(int array[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		merge_sort(array,l,m);
		merge_sort(array,m+1,r);
		printf("pass %d ->",pass++);
		print(array);
		merge(array,l,m,r);
	}
	
}
int main(){
	int i,len,start,end,n;
	printf("enter array length :");
	scan(len);
	l=len;
	int array[len];
	printf("enter array :\n");
	for(i=0;i<len;i++){
		printf("--> ");
		scan(array[i]);
	}
	start=0;
	end=len-1;
	merge_sort(array,start,end);
	printf("arter sorting array :\n");
	for(i=0;i<len;i++){
		printf("%d ",array[i]);
	}
	return 0;
}

