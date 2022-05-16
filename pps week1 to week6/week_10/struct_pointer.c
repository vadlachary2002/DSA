#include <stdio.h>
struct students{
	int id;
	char name[30];
	int dob[3];
};
void main(){
	struct students s;
	printf("enter student id:");
	scanf("%d",&s.id);
	printf("name :");
	scanf("%s",&s.name);
	printf("enter DOB\n[DD-MM-YYYY]");
	scanf("%d-%d-%d",&s.dob[0],&s.dob[1],&s.dob[2]);
	printf("printing structure elements by pointer \n");
	struct students *p;
	p=&s;
	printf("name of student: %s\n",p->name);
	printf("id of student:  %d\n",p->id);
	printf("date of birth %d-%d-%d\n",p->dob[0],p->dob[1],p->dob[2]);
	
}
