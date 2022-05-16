#include<stdio.h>
int main(){
	int i,array[]={10,20,30,40,50,60,70,80,90,100};
	int *p;
	p=&array[0];
	for(i=0;i<10;i++){
		printf("%d\n",*(p+i));
	}
	return 0;
}
