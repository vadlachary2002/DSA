#include <stdio.h>
#include <string.h>
void main(){
	int i,l,flag;
	char s[30],s2[30];
	printf("enter string :\n");
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++){
		s2[i]=s[l-1-i];
	}
	flag=strcmp(s,s2);
	if(flag==0){
		printf("%s is a palindrome\n",s);
	}else{
		printf("%s is not a apalindrome\n",s);
	}
	
	
}
