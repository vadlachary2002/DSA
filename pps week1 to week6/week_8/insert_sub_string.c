#include <stdio.h>
#include <string.h>
void sub_string(char str1[50],char str2[30],int p){
	int i,l1,l2,l3;
	char temp[50];
	l1=strlen(str1);
	l2=strlen(str2);
	for(i=0;i<l1-p;i++){
		temp[i]=str1[p+i];
	}
	l3=strlen(temp);
	for(i=p;i<l2+p;i++){
		str1[i]=str2[i-p];
	}
	for(i=0;i<l3;i++){
		str1[p+l2+i]=temp[i];
	}
	printf("updated string is %s\n",str1);
}
void main(){
	char str1[50],str2[30],str3[80];
	int p;
	printf("enter main string\n");
	printf("->");
	gets(str1);
	printf("enter sub string :");
	gets(str2);
	printf("enter position to insert substring :");
	scanf("%d",&p);
	sub_string(str1,str2,p);
}
