#include <stdio.h>
#include <string.h>

struct students{
	int roll;
	char name[30];
	int marks[4];
	float grade;
};
void search(struct students *ptr,int n){
	char sub[4][10]={"calculus","pps","chemistry","workshop"};
	char tn[30];
	int i,flag=0,j;
	printf("enter name to search marks :");
	scanf("%s",tn);
	for(i=0;i<n;i++){
		if(strcmp(tn,(ptr+i)->name)==0){
			flag=1;
			break;
		}
	}
	if(flag==1){
		printf("marks of %s\n",tn);
				for(j=0;j<4;j++){
					printf("%s->%d\n",sub[j],(ptr+i)->marks[j]);
				}
				printf("final grade is %.1f\n",((ptr+i)->grade)/10);
	}else{
		printf("no record found on this name %s",tn);
	}
	
	
}
void main(){
	int n,i,j,c,gr=0,flag=0;
	char tn[30];
	char sub[4][10]={"calculus","pps","chemistry","workshop"};
	printf("enter no of students :");
	scanf("%d",&n);
	struct students std[n];
	for(i=0;i<n;i++){
		printf("enter %d.student details\n",i+1);
		printf("enter roll no:");
		scanf("%d",&std[i].roll);
		printf("enter name :");
		scanf("%s",std[i].name);
		printf("enter marks\n");
		for(j=0;j<4;j++){
			printf("%s->",sub[j]);
			scanf("%d",&std[i].marks[j]);
			gr=gr+std[i].marks[j];
		}
		std[i].grade=gr/4;
				
		
	}
	printf("data entered successfully\n");
	printf("1.search record\n");
	printf("enter any key for exit\n");
	printf("->");
	scanf("%d",&c);
	if(c==1){
		search(&std,n);
	}
	
	
}
