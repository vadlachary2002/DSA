#include <stdio.h>
#include <string.h>
void del_string(char str[50],int n,int p){
	int i=0,j=0,l1,l2;
	char temp1[50],temp2[50];
	l1=strlen(str);
	for(i=0;i<p;i++){
		temp1[i]=str[i];
	}
	l2=strlen(temp1);
	for(i=0;i<l1-p-n;i++){
		temp1[i+l2]=str[p+n+i];
	}
	printf("updated string is %s",temp1);
}
void main(){
	char str[50];
	int n,p;
	printf("enter your string :\n");
	gets(str);
	printf("enter how many characters you want to delete :");
	scanf("%d",&n);
	printf("enter position from where you want to delete :");
	scanf("%d",&p);
	del_string(str,n,p);
}
