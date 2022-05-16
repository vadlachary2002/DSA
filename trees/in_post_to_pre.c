#include <stdio.h>
#define scan(a) scanf("%d",&a)
int findIndex(int root,int *in,int len){
	int i=0;
	for(i=0;i<len;i++){
		if(in[i]==root){
			return i;
		}
	}
	return -1;
}
int makePreOrder(int *in,int *post,int start_in,int end_in,int start_post,int end_post){
	if(start_in<=end_in || start_post<=end_post){	
		printf("%d ",post[end_post]);
		int index=findIndex(post[end_post],in,end_in+1);
		if(index==-1){
			printf("chary this is wrong\n");
			return ;
		}
		makePreOrder(in,post,start_in,index-1,start_post,start_post+index -1 -start_in);
		makePreOrder(in,post,index+1,end_in,index,end_post-1);
		
	}
}
int main(){
	int in[20],post[20],len,i=0;
	printf("enter length\n");
	scan(len);
	printf("enter elements in inorder:");
	while(i<len){
		scan(in[i]);
		i++;
	}i=0;
	printf("enter elements in postorder:");
	while(i<len){
		scan(post[i]);
		i++;
	}
	printf("elements in preorder is:");
	makePreOrder(in,post,0,len-1,0,len-1);
	
}
