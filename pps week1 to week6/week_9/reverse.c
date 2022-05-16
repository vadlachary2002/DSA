#include <stdio.h>
#include <string.h>
void reverse(char *strr){
	if(*strr){
		reverse(strr+1);
		printf("%c",*strr);
	}

}
void main(){
	char strr[30];
	printf("enter your string\n");
	printf("->");
	gets(strr);
	printf("reversed string :");
	reverse(strr);
	
}
