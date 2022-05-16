#include <stdio.h>
struct student{
	int id;
	char name[20];
	int marks[4];
};
int main(){
	int i,j;
	struct student clss[3];
	for(i=0;i<3;i++){
		printf("enter class %d student id : ",i+1);
		scanf("%d",&clss[i].id);
		printf("enter class %d student name : ",i+1);
		scanf("%s",&clss[i].name);
		printf("enter class %d student marks \n",i+1);
		for(j=0;j<4;j++){
			printf("enter marks of %dst subject ",j+1);
			scanf("%d",&clss[i].marks[j]);
		}
		
	}
	for(i=0;i<3;i++){
			printf("students id's : %d \n",clss[i].id);
		}
	return 0;
}
