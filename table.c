#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct data{
	int id;
	char name[20];
	char branch[5];
	
	
};
int enter_row(){
	FILE *p;
	p=fopen("manasa.csv","wb");
	if(p==NULL){
		printf("error cannot open file\n");
		return;
	}
	struct data n[1];
	printf("Enter Name :");
	scanf("%s",&n[0].name);
	printf("Enter ID :");
	scanf("%d",&n[0].id);
	printf("\n[CSE,ECE,MECH,CHEM,CIVIL,HSS]\n");
	printf("Enter Branch :");
	scanf("%s",&n[0].branch);
	fwrite(n,sizeof(struct data),1,p);
	fclose(p);
	return main();
	
}
int main(){
	int ch;
	printf("1.VIEW TABLE\n");
	printf("2.ENTER A ROW\n");
	printf("3.EDIT TABLE\n");
	printf("4.DELETE A ROW\n");
	printf("5.DELETE ALL\n->");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			//view_table();
			break;
		case 2:
			enter_row();
			break;
		case 3:
			//edit_table();
			break;
		case 4:
			//del_row();
			break;
		case 5:
			break;
		default:
			system("cls");
			printf("ERROR!\n");
			return main();
	}
}
