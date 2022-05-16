#include <stdio.h>
struct str{
	char link[20];
};
int main(){
	int i=0;
	printf("enter string:");
	struct str s[60];
	while(i<60){
		scanf("%s",&s[i].link);
	}
}
