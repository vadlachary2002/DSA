#include <stdio.h>
int merge(int [],int,int,int);
int merge_sort(int [],int,int);
int main(){
	int i,len,start,end,n;
	printf("enter array length :");
	scanf("%d",&len);
	int array[len];
	printf("enter array :\n");
	for(i=0;i<len;i++){
		printf("--> ");
		scanf("%d",&array[i]);
	}
	start=0;
	end=len-1;
	
	
	merge_sort(array,start,end);
	printf("arter sorting array :\n");
	for(i=0;i<len;i++){
		printf("%d,",array[i]);
		
	}
	return 0;
}
int merge_sort(int array[],int l,int r){
	if(l<r){
		int m=l+(r-l)/2;
		merge_sort(array,l,m);
		merge_sort(array,m+1,r);
		merge(array,l,m,r);
	}
	
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
			array[k]=L[i];
			i++;
		}else{
			array[k]=R[j];
			j++;
		}k++;
	}
	while(i<n1){
		array[k]=L[i];
		i++;
		k++;
	}while(j<n2){
		array[k]=R[j];
		j++;
		k++;
	}
}
