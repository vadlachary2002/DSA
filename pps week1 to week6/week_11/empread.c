#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void main();
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
int getsize(){
	int l;
	FILE *fp;
	fp=fopen("capacity.txt","rb");
	if(fp==NULL){
		printf("cannot open capacity file ...\n");
		return 0;
	}else{
		struct cap c[2];
		fread(c,sizeof(struct cap),2,fp);
		l=c[0].len;
		fclose(fp);
		return l;
		
	}
	
	
	
}
void del_record(){
	int i,l,id,place,flag=0,j;
	l=getsize();
	FILE *p1,*p2;
	p1=fopen("employee.txt","rb");
	p2=fopen("employee3.txt","wb");
	if(p1==NULL || p2==NULL){
		printf("cannot open file ...\n");
		exit(0);
	}
	printf("enter if of record you want to delete :\n");
	printf("->");
	scanf("%d",&id);
	struct employee e[l];
	struct employee e2[l-1];
	fread(e,sizeof(struct employee),l,p1);
	for(i=0;i<l;i++){
		if(id==e[i].empid){
			place=i;
			flag=1;
			break;
		}
	}
	if(flag==1){
		for(i=0;i<l-1;i++){
			if(e[i].empid!=id){
				strcpy(e2[i].empname,e[i].empname);
				e2[i].empid=e[i].empid;
				e2[i].sal=e[i].sal;
				e2[i].expr=e[i].expr;
				for(j=0;j<4;j++){
					strcpy(e2[i].dqra[j],e[i].dqra[j]);
				}
				
				
			}
		}
		store(l-1);
		fwrite(e2,sizeof(struct employee),l-1,p2);
		fclose(p1);
		fclose(p2);
		remove("employee.txt");
		rename("employee3.txt","employee.txt");
		printf("deleted successfully\n");
	}else{
		printf("no record found on this is id=%d",id);
	}
	main();
	
	
}
void enter_record(){
	int i,l,n;
	l=getsize();
	FILE *p1,*p2;
	//printf("len =%d",l);
	if(l==0){
		p1=fopen("employee.txt","wb");
	}else{
		p1=fopen("employee.txt","rb");
	}
	
	p2=fopen("employee2.txt","wb");
	if(p1==NULL || p2==NULL){
		printf("cannot open file ...\n");
		exit(0);
	}
	printf("enter no of records you want to enter :\n");
	scanf("%d",&n);
	
	struct employee e[l+n];
	fread(e,sizeof(struct employee),l,p1);
	for(i=l;i<l+n;i++){
		printf("%d.employee record :",i+1);
		printf("NAME :");
		scanf("%s",e[i].empname);
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
	fwrite(e,sizeof(struct employee),l+n,p2);
	fclose(p1);
	fclose(p2);
	remove("employee.txt");
	rename("employee2.txt","employee.txt");
	printf("data inserted successfully");
	store(l+n);
	main();
	
}
void modify(){
	int i,l,id,place,flag=0;
	l=getsize();
	FILE *fp,*ptr;
	fp=fopen("employee.txt","rb");
	ptr=fopen("employee2.txt","wb");
	if(fp==NULL || ptr==NULL){
		printf("cannot open file ...\n");
		exit(0);
	}
	struct employee e[l];
	fread(e,sizeof(struct employee),l,fp);
	
	printf("enter id :");
	scanf("%d",&id);
	for(i=0;i<l;i++){
		if(id==e[i].empid){
			printf("Matched Successfully\n");
			flag=1;
			place=i;
			break;
			
		}
		
	}
	if(flag==1){
		printf("enter updated details \n");
		printf("%d.emoloyee details\n",i+1);
		printf("NAME :");
		scanf("%s",e[i].empname);
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
		fwrite(e,sizeof(struct employee),l,ptr);
		printf("modified successfully\n");
	}else{
		printf("no record found on this is id=%d",id);
	}
	
	fclose(ptr);
	fclose(fp);
	remove("employee.txt");
	rename("employee2.txt","employee.txt");
	main();
	
	
	
	
}
void view_all(){
	int l,i;
	
	
	FILE *fp;
	fp=fopen("employee.txt","rb");
	if(fp==NULL){
		printf("cannot open file ...\n");
		main();
		
	}
	l=getsize();
	printf("lenth %d\n",l);
	struct employee e[l];
	
	fread(e,sizeof(struct employee),l,fp);
	printf("\tNAME\t   ID\tDESIGNATION\tQUALIFICATION\tSALARY\tEXPERIENCE\tRESEARCH WORK\tADDRESS\tMOBILE NO\t\n");
	for(i=0;i<l;i++){
		printf("%d\t",i+1);
		printf("%s\t",e[i].empname);
		printf("%d",e[i].empid);
		printf("\t%s\t",e[i].dqra[0]);
		printf("\t%s\t",e[i].dqra[1]);
		printf("\t%d\t",e[i].sal);
		printf("\t%d\t",e[i].expr);
		printf("\t%s",e[i].dqra[2]);
		printf("\t%s",e[i].dqra[3]);
		printf("\t%lld\n",e[i].phn);
	}
	fclose(fp);
	main();
	
	
}
void main(){
	int c;
	printf("1.MODIFY RECORD\n");
	printf("2.DELETE RECORD\n");
	printf("3.ENTER NEW RECORD\n");
	printf("4.VIEW ALL RECORDS\n");
	printf("5.Quit\n");
	printf("->");
	scanf("%d",&c);
	switch(c){
		case 1:
			modify();
			break;
		case 2:
			del_record();
			break;
		case 3:
			enter_record();
			break;
		case 4:
			view_all();
			break;
		case 5:
			printf("4");
			exit(0);
		default :
			printf("ERROR CHOICE\n");
			main();
	}
}
	
