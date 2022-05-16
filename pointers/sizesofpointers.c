#include <stdio.h>
/* every ponter has some fixed  size 
if system is 16bit size of pointer is 2bytes
if system is 32but size of pointer is 4bytes 
if system ids 64bit size of poninter is 8bytes
beacuse it holds integer typeof value(address)*/
struct student {
	int id;
	char name[20];
	int marks[4];
};
int  main(){
	int *ip;
	char *cp;
	struct student *ssp;
	printf("size of int pointer %d \n",sizeof(ip));
	printf("size of char pointert %d \n",sizeof(cp));
	printf("size of struct student pointer %d \n",sizeof(ssp));
	
	return 0;
	
}
