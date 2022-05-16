#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct employee{
	int empid;
	char empname[30];
	char dqra[4][40];
	int sal;
	int expr;
	long long int phn;
};
struct cap{
	int len;
};
void store(int n){
	FILE *ptr;
	ptr=fopen("capacity.txt","wb");
	if(ptr==NULL){
		printf("cannot store capacity ...\n");
		exit(0);
	}
	struct cap c[2];
	c[0].len=n;
	c[1].len=n;
	fwrite(c,sizeof(struct cap),2,ptr);
	printf("stored %d\n",n);
	fclose(ptr);
	
}
void main(){
	int n,i;
	printf("enter no of employees :");
	scanf("%d",&n);
	store(n);
	struct employee e[n];
	for(i=0;i<n;i++){
		printf("%d.emoloyee details\n",i+1);
		printf("NAME :");
		scanf("%s",&e[i].empname);
		printf("ID :");
		scanf("%d",&e[i].empid);
		printf("DESIGNATION :");
		scanf("%s",&e[i].dqra[0]);
		printf("QUALIFICATION :");
		scanf("%s",&e[i].dqra[1]);
		printf("SALARY :");
		scanf("%d",&e[i].sal);
		printf("EXPERIENCE __YEARS:");
		scanf("%d",&e[i].expr);
		printf("RESEARCH WORK:");
		scanf("%s",&e[i].dqra[2]);
		printf("ADDRESS :");
		scanf("%s",&e[i].dqra[3]);
		printf("MOBILE NO :");
		scanf("%lld",&e[i].phn);
	}
	FILE *fp;
	fp=fopen("employee.txt","wb");
	if(fp==NULL){
		printf("cannot open file ...\n");
		exit(0);
	}
	fwrite(e,sizeof(struct employee),n,fp);
	printf("data inserted successfully ");
	fclose(fp);
	
}
