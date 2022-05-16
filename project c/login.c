#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACITY 2
void admin_page();
void students_page(int);
void del_record(char [],int,int);
struct capacity{
	int len;
};
struct login{
	int id;
	char pass[30];
	int dob[3];
};
struct chat{
	char name[30];
	char msg[50];
};
struct students{
	int id;
	char name[25];
	int dob[3];
	int marks[4];
	float grade;
	//char reason[50];
};
int store(char file[30],int l){
	struct capacity cap[1];
	FILE *fp;
	fp=fopen(file,"wb");
	if(fp==NULL){
		//printf("ERROR! cannot store students capacity...store");
		exit(0);
	}
	cap[0].len=l;
	fwrite(cap,sizeof(struct capacity),1,fp);
	fclose(fp);
}
int getsize(char file[20]){
	int l;
	FILE *str;
	str=fopen(file,"rb");
	if(str==NULL){
		//printf("ERROR! cannot open students capacity... getzise");
		return 0;
	}
	struct capacity cap[1];
	fread(cap,sizeof(struct capacity),1,str);
	l=cap[0].len;
	//printf("length is %d\n",l);
	fclose(str);
	return l;
}
void modify(int id){
	int l,i,j,tt,l2,flag=0,place;
	l=getsize("apli.txt");
	l2=getsize("capacity.txt");
	if(l>0){
		int ch;
		FILE *x;
		x=fopen("applications.txt","rb");
		struct students z[l];
		fread(z,sizeof(struct students),l,x);
		fclose(x);
		for(i=0;i<l;i++){
			if(z[i].id==id){
				printf("\nYOU ALREADY APPLIED FOR MODIFICATION \n[if you want to RE-APPLY-MODIFICATION click CANCEL and  APPLY MODIFICATION ]\n\n");
				printf("1.CANCEL APPLICATION\n");
				printf("any key go back\n");
				printf("->");
				scanf("%d",&ch);
				system("cls");
				if(ch==1){
					del_record("applications.txt",id,1);
				}
				return students_page(id);
				break;
			}
		}
	}
	FILE *p1,*p2,*p3;
	p1=fopen("students.txt","rb");
	if(l==0){
		p2=fopen("applications.txt","wb");
	}else{
		p2=fopen("applications.txt","rb");
	}
	p3=fopen("applications3.txt","wb");
	if(p1==NULL ||p2==NULL || p3==NULL){
		//printf("cannot open files \n");
		remove("applications3.txt");
		fclose(p1);
		fclose(p2);
		fclose(p3);
		return students_page(id);
	}
	struct students s1[l2],s2[l+1];
	fread(s1,sizeof(struct students),l2,p1);
	fclose(p1);
	for(i=0;i<l2;i++){
		if(s1[i].id==id){
			printf("\nMATCHED ID\n");
			flag=1;
			place=i;
			break;
		}
	}
	if(flag==0){
		printf("\nNOT MATCHED ID APPLY FOR NEW\n");
		return students_page(id);
	}
	fread(s2,sizeof(struct students),l,p2);
	fclose(p2);
	s2[l].id=id;
	fflush(stdin);
	printf(" NAME :");
	gets(s2[l].name);
	printf("DOB [DD-MM-YYYY] :");
	scanf("%d-%d-%d",&s2[l].dob[0],&s2[l].dob[1],&s2[l].dob[2]);
	for(i=0;i<4;i++){
		printf("%d.subject :",i+1);
		scanf("%d",&s2[l].marks[i]);
		tt=tt+s2[l].marks[i];
	}
	s2[l].grade=tt/4;
	fwrite(s2,sizeof(struct students),l+1,p3);
	fclose(p3);
	remove("applications.txt");
	rename("applications3.txt","applications.txt");
	store("apli.txt",l+1);
	system("cls");
	printf("\tAPPLIED FOR MODIFICATION \n");
	return students_page(id);
}
void apply(int id){
	int l,i,j,tt,l2;
	l2=getsize("capacity.txt");
	struct students std[l2];
	FILE *p;
	p=fopen("students.txt","rb");
	if(p==NULL ){
		//printf("ERROR! cannot open students file...\n");
		fclose(p);
	}else{
		fread(std,sizeof(struct students),l2,p);
		fclose(p);
		for(i=0;i<l2;i++){
			if(std[i].id==id){
				printf("\nYOUR DATA ALREADY THERE IN OUR DATABASE\n[if you want to change click apply modify ]\n[enter any key to go back...]\n\n");
				return students_page(id);
				break;
			}
		}
	}
	l=getsize("apli.txt");
	if(l>0){
		int ch;
		FILE *x;
		x=fopen("applications.txt","rb");
		struct students z[l];
		fread(z,sizeof(struct students),l,x);
		fclose(x);
		for(i=0;i<l;i++){
			if(z[i].id==id){
				printf("\nYOUR  ALREADY APPLIED FOR NEW \n[if you want to RE-APPLY click CANCEL and  APPLY NEW ]\n\n");
				printf("1.CANCEL APPLICATION\n");
				printf("any key go back\n");
				printf("->");
				scanf("%d",&ch);
				system("cls");
				if(ch==1){
					del_record("applications.txt",id,1);
				}
				return students_page(id);
				break;
			}
		}
	}//printf("l in apply %d\n",l);
	FILE *fp1,*fp2;
	if(l==0){
		fp1=fopen("applications.txt","wb");
	}else{
		fp1=fopen("applications.txt","rb");
	}
	fp2=fopen("applications2.txt","wb");
	if(fp1==NULL || fp2==NULL ){
		//printf("ERROR! cannot open applications file...");
		return students_page(id);
	}
	struct students s[l+1];
	fread(s,sizeof(struct students),l,fp1);
	fclose(fp1);
	tt=0;
	s[l].id=id;
	fflush(stdin);
	printf("  NAME :");
	gets(s[l].name);
	printf(" DOB[DD-MM-YYYY] :");
	scanf("%d-%d-%d",&s[l].dob[0],&s[l].dob[1],&s[l].dob[2]);
	printf(" ENTER MARKS\n");
	for(j=0;j<4;j++){
		printf("%d.subject :",j+1);
		scanf("%d",&s[l].marks[j]);
		tt=tt+s[l].marks[j];
	}
	s[l].grade=tt/4;
	fwrite(s,sizeof(struct students),l+1,fp2);
	fclose(fp2);
	remove("applications.txt");
	tt=rename("applications2.txt","applications.txt");
	//printf("tt=%d\n",tt);
	system("cls");
	printf("\tAPPLIED  SUCCESSFULLY\n");
	store("apli.txt",l+1);
	return students_page(id);
}
void notice(int id){
	char ntc[100];
	FILE *ptr;
	if(id==1){
		ptr=fopen("notice.txt","wb");
		if(ptr==NULL){
			printf("NO NOTICE UPDATED YET\n");
			return admin_page();
		}
		printf("TYPE YOUR NOTICE HERE\t\t\t [enter '#' at the end of notice]\n");
		printf("->");
		scanf("%[^#]",ntc);
		fwrite(ntc,1,sizeof(ntc),ptr);
		fclose(ptr);
		system("cls");
		printf("NOTICE UPDATED SUCCESSFULLY \n");
		return admin_page();
	}else{
		printf("~~~~~~~~~~~~~~~~|| NOTICE ||~~~~~~~~~~~~~~~~~~~~\n");
		FILE *ptr;
		ptr=fopen("notice.txt","rb");
		if(ptr==NULL){
			printf("\t\tNO NOTICE UPDATED YET\n");
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			return students_page(id);
		}
		fread(ntc,1,sizeof(ntc),ptr);
		printf("\t\t%s\n\n",ntc);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return students_page(id);
	}
	fclose(ptr);
}
void del_record(char file[30],int id,int a){
	int l,i,place,flag=0,j,k;
	if(strcmp(file,"students.txt")==0){
		if(a==1){
			printf("||  DELETE A RECORD  ||\n");
		}else{
			printf("\n");
		}
		l=getsize("capacity.txt");
		//printf("recieved from capacity l=%d\n",l);
	}else if(strcmp(file,"applications.txt")==0){
		if(a==1){
			printf("||  DELETE A RECORD  ||\n");
		}else{
			printf("\n");
		}
		l=getsize("apli.txt");
		//printf("recirved from apli l=%d\n",l);
	}
	FILE *p1,*p2;
	if(l==0){
		if(a==1){
			printf("NO RECORDS FOUND IN DATABASE\n\n");
		}else{
			printf("\n");
		}
		return admin_page();
	}else{
		p1=fopen(file,"rb");
		p2=fopen("temp.txt","wb");
	}
	if(p1==NULL|| p2==NULL){
		//printf("ERROR! cannot open students file...\n");
		return;
	}
	struct students s1[l];
	struct students s2[l-1];
	fread(s1,sizeof(struct students),l,p1);
	fclose(p1);
	for(i=0;i<l;i++){
		if(id==s1[i].id){
			place=i;
			flag=1;
			//printf("matched to delete\n");
			break;
		}
	}
	if(flag==1){
		k=0;
		for(i=0;i<l;i++){
			if(s1[i].id!=id){
				s2[k].id=s1[i].id;
				//printf("id remainding %d\n",s2[k].id);
				strcpy(s2[k].name,s1[i].name);
				for(j=0;j<3;j++){
					s2[k].dob[j]=s1[i].dob[j];
				}
				for(j=0;j<4;j++){
					s2[k].marks[j]=s1[i].marks[j];
				}
				s2[k].grade=s1[i].grade;
				k++;
			}
		}
		if(strcmp(file,"students.txt")==0){
			store("capacity.txt",l-1);
		}else if(strcmp(file,"applications.txt")==0){
			store("apli.txt",l-1);
		}
		fwrite(s2,sizeof(struct students),l-1,p2);
		fclose(p2);
		remove(file);
		rename("temp.txt",file);
		if(strcmp(file,"applications.txt")==0){
			if(a==1){
				printf("%d APPLICATION DELETED SUCCESSFULLY\n\n",id);
			}else{
				printf("\n");
			}
		}else if(strcmp(file,"students.txt")==0){
			if(a==1){
				printf("%d DATA DELETED SUCCESSFULLY\n\n",id);
			}else{
				printf("\n");
			}
		}
		if(l==1){
			if(strcmp(file,"applications.txt")==0){
				remove("apli.txt");
			}else if(strcmp(file,"students.txt")==0){
				remove("capacity.txt");
			}
			remove(file);
		}
	}
	else{
		fclose(p2);
		if(a==1){
			printf("NO RECORD FOUND ON THIS ID=%d\n\n",id);
		}else{
			printf("\n");
		}
	}
}
void update_record(){
	int i,j,l,t=0,gr=0,place;
	printf("||  UPDATE STUDENT RECORD ||\n");
	FILE *st,*st2;
	l=getsize("capacity.txt");
	if(l==0){
		int x;
		printf("NO RECORDS FOUND TO UPDATE\n");
		printf("1.ADMIN _PAGE\n");
		printf("ENTER ANY KEY TO Quit\n");
		printf("->");
		scanf("%d",&x);
		if(x==1){
			system("cls");
			admin_page();
		}else{
			exit(0);
		}
	}else{
		st=fopen("students.txt","rb");
		st2=fopen("studentsu.txt","wb");
		if(st==NULL || st2==NULL){
			printf("ERROR! cannot open students file...");
			return admin_page();
		}
	}
	struct students std[l];
	int id;
	fread(std,sizeof(struct students),l,st);
	fclose(st);
 	printf("ENTER ID WHICH YOU WANT TO UPDATE\n");
	printf	("->");
	scanf("%d",&id);
	for(i=0;i<l;i++){
		if(id==std[i].id){
			t=1;
			place=i;
			printf("MATCHED SUCCESSFULLY\n");
			break;
		}
	}
	if(t==0){
		printf("NO RECORD FOUND ON THIS ID:%d\n",id);
			int x;
			printf("1.ADMIN _PAGE\n");
			printf("ENTER ANY KEY TO Quit\n");
			printf("->");
			scanf("%d",&x);
			if(x==1){
				system("cls");
				admin_page();
			}else{
				exit(0);
			}
	}else{
		//view_student();
		printf("ENTER UPDATED DETAILS\n");
		fflush(stdin);
		printf("ENTER NAME:");
		gets(std[place].name);
		printf("DOB[DD-MM-YYYY]:");
		scanf("%d-%d-%d",&std[place].dob[0],&std[place].dob[1],&std[place].dob[2]);
		printf("ENTER MARKS\n");
		for(j=0;j<4;j++){
			printf("%d.SUBJECT :",j+1);
			scanf("%d",&std[place].marks[j]);
			gr=gr+std[place].marks[j];
		}
		std[place].grade=gr/4;
		fwrite(std,sizeof(struct students),l,st2);
		fclose(st2);
		remove("students.txt");
		rename("studentsu.txt","students.txt");
		system("cls");
		printf("DATA UPDATED SUCCESSFULLY\n");
		admin_page();
	}
}
void view_all(){
	int i,j,l,tt;
	FILE *all;
	all=fopen("students.txt","rb");
	if(all==NULL){
		printf("NO RECORDS FOUND IN DATABASE \n");
		int x;
		printf("1.ADMIN _PAGE\n");
		printf("ENTER ANY KEY TO Quit\n");
		printf("->");
		scanf("%d",&x);
		if(x==1){
			system("cls");
			admin_page();
		}else{
			exit(0);
		}
	}
	l=getsize("capacity.txt");
	//printf("l in view all %d\n",l);
	if(l==0){
		printf("NO RECCORDS FOUND IN DATABASE\n");
		return admin_page();
	}
	struct students allstd[l];
	fread(allstd,sizeof(struct students),l,all);
	fclose(all);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~|| ALL STUDENTS RECORDS  ||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\tSLNO\tID\tNAME\t\tDOB\t\t MARKS[1,2,3,4]\t\tGRADE\t\n");
	for(i=0;i<l;i++){
		printf("\t%d",i+1);
		printf("\t%d\t",allstd[i].id);
		printf("%s\t",allstd[i].name);
		printf("%d-%d-%d\t",allstd[i].dob[0],allstd[i].dob[1],allstd[i].dob[2]);
		for(j=0;j<4;j++){
			printf("'%d'",allstd[i].marks[j]);
		}
		printf("\t");
		printf("%.1f\t\n",(allstd[i].grade)/10);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fflush(stdin);
	admin_page();
}
int enter_record(){
	int i,j,l,l2,tt;
	char ch;
	printf(" || ENTER STUDENTS RECORD  ||\n\n");
	printf("NO OF STUDENTS YOU WANT TO ENTER :\t");
	scanf("%d",&l);
	l2=getsize("capacity.txt");
	//printf("l+l2=%d\n",l+l2);
	FILE *sptr,*sptr2;
	if(l2==0){
		sptr=fopen("students.txt","wb");
	}else{
		sptr=fopen("students.txt","rb");
	}
	sptr2=fopen("students2.txt","wb");
	if(sptr==NULL || sptr2==NULL ){
		printf("ERROR! cannot open students file...\n");
		exit(0);
	}
	struct students s[l+l2];
	fread(s,sizeof(struct students),l2,sptr);
	fclose(sptr);
	for(i=l2;i<l+l2;i++){
		tt=0;
		printf("%d.STUDENT ID :",i+1-l2);
		scanf("%d",&s[i].id);
		fflush(stdin);
		printf("  NAME :");
		gets(s[i].name);
		printf(" DOB[DD-MM-YYYY] :");
		scanf("%d-%d-%d",&s[i].dob[0],&s[i].dob[1],&s[i].dob[2]);
		printf(" ENTER MARKS\n");
		for(j=0;j<4;j++){
			printf("%d.SUBJECT :",j+1);
			scanf("%d",&s[i].marks[j]);
			tt=tt+s[i].marks[j];
		}
		s[i].grade=tt/4;
	}
	fwrite(s,sizeof(struct students),l+l2,sptr2);
	fclose(sptr2);
	remove("students.txt");
	rename("students2.txt","students.txt");
	system("cls");
	printf("DATA ENTERED SUCCESSFULLY\n\n");
	store("capacity.txt",l+l2);
	admin_page();
}
void rank_record(){
	int i,j,l;
	register int k;
	l=getsize("capacity.txt");
	if(l==0){
		printf("NO RECORDS FOUND IN DATABASE\n");
		 return admin_page();
	}
	FILE *p1,*p2;
	p1=fopen("students.txt","rb");
	p2=fopen("students4.txt","wb");
	if(p1==NULL || p2==NULL){
		printf("cannot open students file try again later..\n");
		return admin_page();
	}
	struct students s[l];
	struct students temp;
	fread(s,sizeof(struct students),l,p1);
	fclose(p1);
	for(i=0;i<l-1;i++){
		for(j=0;j<l-1-i;j++){
			if(s[j].grade<s[j+1].grade){
				temp.id=s[j].id;
				strcpy(temp.name,s[j].name);
				for(k=0;k<3;k++){
					temp.dob[k]=s[j].dob[k];
				}
				for(k=0;k<4;k++){
					temp.marks[k]=s[j].marks[k];
				}
				temp.grade=s[j].grade;
				s[j].id=s[j+1].id;
				strcpy(s[j].name,s[j+1].name);
				for(k=0;k<3;k++){
					s[j].dob[k]=s[j+1].dob[k];
				}
				for(k=0;k<4;k++){
					s[j].marks[k]=s[j+1].marks[k];
				}
				s[j].grade=s[j+1].grade;
				s[j+1].id=temp.id;
				strcpy(s[j+1].name,temp.name);
				for(k=0;k<3;k++){
					s[j+1].dob[k]=temp.dob[k];
				}
				for(k=0;k<4;k++){
					s[j+1].marks[k]=temp.marks[k];
				}
				s[j+1].grade=temp.grade;
			}
		}
	}
	fwrite(s,sizeof(struct students),l,p2);
	fclose(p2);
	remove("students.txt");
	rename("students4.txt","students.txt");
	system("cls");
	printf("\tRANKS ALLOTED TO STUDENTS\n\n");
	return view_all();
}
void view_apli(){
	int i,j,l1,l2,c,c2,t=0,tt,place,sum,pl;
	l1=getsize("apli.txt");
	//printf("l1 apli in viw al %d\n",l1);
	l2=getsize("capacity.txt");
	printf("||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|| APPLICATIONS ||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
	if(l1==0 ){
		
		printf("\tTHERE IS NO APPLICATIONS RECIEVED\n\n");
		printf("||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
		return admin_page();
	}
	FILE *p;
	p=fopen("applications.txt","rb");
	if(p==NULL){
		printf("cannot open applications file \n");
		return admin_page();
	}
	struct students s[l1];
	fread(s,sizeof(struct students),l1,p);
	fclose(p);
	printf("SLNO\tID\t NAME\t DOB\t\t MARKS[1,2,3,4]\t\tGRADE\t\n");
	for(i=0;i<l1;i++){
		printf("%d\t",i+1);
		printf("%d\t ",s[i].id);
		printf("%s\t ",s[i].name);
		printf("%d-%d-%d\t",s[i].dob[0],s[i].dob[1],s[i].dob[2]);
		for(j=0;j<4;j++){
			printf("'%d'",s[i].marks[j]);
		}
		printf("\t");
		printf("%.1f\t\n",(s[i].grade)/10);
	}
	printf("||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n");
	printf("SELECT ONE OF THE ABOVE TO INSERT INTO DATABASE [or]\n");
	printf("any key to go back...\n");
	//printf("l1=%d\n",l1);
	printf("->");
	scanf("%d",&c);
	c--;
	pl=c;
	//printf("c =%d\n",c);
	if(c>=l1 || c<0){
		printf("\nWRONG CHOICE\n");
		return admin_page();
	}
	printf("1.ACCEPT REQUEST AND INSERT INTO DATABASE\n");
	printf("2.DECLINE REQUEST\n");
	scanf("%d",&c2);
	if(c2!=1 && c2!=2){
		system("cls");
		printf("\nWRONG CHOICE\n");
		return admin_page();
	}
	FILE *ptr1,*ptr2;
	if(c2==1){
		if(l2==0){
			sum=0;
			ptr1=fopen("students.txt","wb");
			struct students q[1];
			q[0].id=s[c].id;
			strcpy(q[0].name,s[c].name);
			for(i=0;i<3;i++){
				q[0].dob[i]=s[c].dob[i];
			}
			for(i=0;i<4;i++){
				q[0].marks[i]=s[c].marks[i];
				sum=sum+s[c].marks[i];
			}
			q[0].grade=sum/4;
			fwrite(q,sizeof(struct students),1,ptr1);
			fclose(ptr1);
			system("cls");
			printf("\nINSERTED NEW APPLICATION  INTO DATABASE\n\n");
			//printf("%d is to be removed \n",s[c].id);
			//remove_apli(s[c].id);
			del_record("applications.txt",s[c].id,0);
			l1=getsize("apli.txt");
			store("capacity.txt",1);
			//printf("l1 apli %d\n",l1);
			return admin_page();
		}else{
			ptr1=fopen("students.txt","rb");
		}
		ptr2=fopen("students6.txt","wb");
		//printf("s[c].id=%d\n",s[c].id);
		struct students std[l2+1];
		fread(std,sizeof(struct students),l2,ptr1);
		fclose(ptr1);
		for(i=0;i<l2;i++){
			if(s[c].id==std[i].id){
				t=1;
				place=i;
				printf("MATCHED SUCCESSFULLY\n");
				break;
			}
		}
		
		if(t==1){
			std[place].id=s[c].id;
			strcpy(std[place].name,s[c].name);
			for(j=0;j<3;j++){
				std[place].dob[j]=s[c].dob[j];
			}
			for(j=0;j<4;j++){
				std[place].marks[j]=s[c].marks[j];
			}
			std[place].grade=s[c].grade;
			fwrite(std,sizeof(struct students),l2,ptr2);
			fclose(ptr2);
			remove("students.txt");
			rename("students6.txt","students.txt");
			system("cls");
		//	printf("%d\n",s[c].id);
			printf("\nINSERTED  UPDATED DATA  INTO DATABASE\n\n");
			//remove_apli(s[c].id);
			del_record("applications.txt",s[c].id,0);
		//	printf("removed \n");
			return admin_page();
		}
		std[l2].id=s[pl].id;
		printf("inserting new l!=0 of id %d\n",std[l2].id);
		strcpy(std[l2].name,s[pl].name);
		for(j=0;j<3;j++){
			std[l2].dob[j]=s[pl].dob[j];
		}
		for(j=0;j<4;j++){
			std[l2].marks[j]=s[pl].marks[j];
		}
		std[l2].grade=s[pl].grade;
		fwrite(std,sizeof(struct students),l2+1,ptr2);
		fclose(ptr2);
		remove("students.txt");
		//printf("tt in new %d\n",tt);
		del_record("applications.txt",s[pl].id,0);
		//printf("del after id =%d\n",s[c].id);
		rename("students6.txt","students.txt");
		//printf("tt in new %d\n",tt);
		system("cls");
		store("capacity.txt",l2+1);
		printf("INSERTED  NEW RECORD SUCCESSFULLY\n\n");
		//remove_apli(s[c].id);
		return admin_page();
	}else{
		printf("\nREJECTED SUCCESSFULLY \n");
		del_record("applications.txt",s[pl].id,1);
		return admin_page();
	}
}
void chat_box(char name[30],int id){
	fflush(stdin);
	
	system("cls");
	int l,i;
	char ch[100];
	printf("ENTER '#' TO GO BACK\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~CHAT~BOX~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	l=getsize("chats.txt");
	if(l!=0){
		struct chat c[l];
		FILE *ptr1;
		ptr1=fopen("chatbox.txt","rb");
		fread(c,sizeof(struct chat),l,ptr1);
		if(l>10){
			for(i=l-10;i<l;i++){
				printf("%s\t:\t%s\n",c[i].name,c[i].msg);
			}
		}else{
			for(i=0;i<l;i++){
				printf("%s\t:\t%s\n",c[i].name,c[i].msg);
			}
		}
		fclose(ptr1);
	}else{
		printf("THERE ARE NO CHATS HERE \n");
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fflush(stdin);
	printf("%s->",name);
	gets(ch);
	if(strcmp(ch,"#")==0){
		system("cls");
		if(id==1){
			return admin_page();
		}else{
			return students_page(id);
		}
	}
	FILE *ptr1,*ptr2;
	if(l==0){
		ptr1=fopen("chatbox.txt","wb");
		struct chat c[1];
		strcpy(c[0].name,name);
		strcpy(c[0].msg,ch);
		fwrite(c,sizeof(struct chat),1,ptr1);
		fclose(ptr1);
		store("chats.txt",1);
		return chat_box(name,id);
	}
	ptr1=fopen("chatbox.txt","rb");
	if(ptr1==NULL){
		printf("cannot open file \n");
		exit(0);
	}
	struct chat c[l+1];
	fread(c,sizeof(struct chat),l,ptr1);
	fclose(ptr1);
	strcpy(c[l].name,name);
	strcpy(c[l].msg,ch);
	ptr2=fopen("chatbox2.txt","wb");
	fwrite(c,sizeof(struct chat),l+1,ptr2);
	fclose(ptr2);
	remove("chatbox.txt");
	rename("chatbox2.txt","chatbox.txt");
	store("chats.txt",l+1);
	chat_box(name,id);
}
void admin_page(){
	fflush(stdin);
	int c;
	printf("\tWELL-COME ADMINISTRATOR\n");
	printf("1.\tMANUAL ENTER,DELETE,UPDATE RECORD\n");
	printf("2.\tVIEW STUDENTS RECORDS\n");
	printf("3.\tALLOT RANKS BASED ON GRADE\n");
	printf("4.\tNOTICE \n");
	printf("5.\tVIEW APPLICATIONS\n");
	printf("6.\tCHAT-BOX\n");
	printf("7.\tLOG OUT\n");
	printf("->");
	fflush(stdin);
	scanf("%d",&c);
	switch(c){
		case 1:
			system("cls");
			int c2=0;
			printf("1.\tENTER NEW STUDENT RECORD\n");
			printf("2.\tUPDATE STUDENTS RECORD\n");
			printf("3.\tDELETE STUDENTS RECORD\n");
			printf("->");
			scanf("%d",&c2);
			switch(c2){
				case 1:
					system("cls");
					enter_record();
					break;
				case 2:
					system("cls");
					update_record();
					break;
				case 3:
					system("cls");
					int d;
					printf("ENTER ID WHICH YOU WANT TO DELETE\n");
					scanf("%d",&d);
					system("cls");
					del_record("students.txt",d,1);
					admin_page();
					break;
					enter_record();
					break;
				default:
					system("cls");
					printf("\tERROR ! CHOICE\n");
					return admin_page();
			}
		case 2:
			system("cls");
			view_all();
			break;
		case 3:
			system("cls");
			rank_record();
			break;
		case 4:
			system("cls");
			notice(1);
			break;
		case 5:
			system("cls");
			view_apli();
			break;
		case 6:
			system("cls");
			chat_box("ADMIN",1);
			break;
		case 7:
			system("cls");
			printf("\tLOGGED OUT\n");
			main();
			break;
		default:
			system("cls");
			printf("ERROR ! CHOICE\n");
			return admin_page();
	}
}
void students_page(int id){
	fflush(stdin);
	int l,i,flag=0,c,place,j;
	l=getsize("capacity.txt");
	struct students s[l];
	FILE *p;
	p=fopen("students.txt","rb");
	if(p==NULL){
		printf("\tNO RECORDS FOUND OF YOURS\n");
	}else{
		fread(s,sizeof(struct students),l,p);
		fclose(p);
		for(i=0;i<l;i++){
			if(s[i].id==id){
				printf("\t||  WELL-COME  %s ||\n",strupr(s[i].name));
				flag=1;
				place=i+1;
				break;
			}
		}
	}
	if(flag==0){
		printf("\n\tNO DATA FOUND OF YOURS\n\tAPPLY TO INSERT YOUR DETAILS INTO DATABASE\n\n");
		
	}
	printf("\t1.\tVIEW YOUR DETAILS\n");
	printf("\t2.\tVIEW YOUR RANK\n");
	printf("\t3.\tNOTICE BOX\n");
	printf("\t4.\tAPPLY FOR NEW \n");
	printf("\t5.\tAPPLY FOR MODIFICATION\n");
	printf("\t6.\tCHAT-BOX\n");
	printf("\t7.\tLOG OUT\n");
	printf("\t->");
	fflush(stdin);
	scanf("%d",&c);
	switch(c){
		case 1:
			system("cls");
			if(l!=0 && flag==1){
				printf("\tID \t NAME\t DOB\t\t MARKS[1,2,3,4]\t\tGRADE\t\n");
				printf("\t%d\t",s[i].id);
				printf("%s\t",s[i].name);
				printf("%d-%d-%d\t",s[i].dob[0],s[i].dob[1],s[i].dob[2]);
				for(j=0;j<4;j++){
					printf("'%d'",s[i].marks[j]);
				}
				printf("\t");
				printf("%.1f\t\n",(s[i].grade)/10);
			}else{
				printf("\n\tYOUR DETAILS ARE NOT ENTERED INTO DATABASE\n\n");
			}
			return students_page(id);
			break;
		case 2:
			system("cls");
			if(l!=0){
				system("cls");
				printf("\n\tYOUR RANK IS '%d'\n\n",place);
			}else{
				printf("\nYOUR DETAILS ARE NOT ENTERED INTO DATABASE\n");
			}
			students_page(id);
			break;
		case 3:
			system("cls");
			notice(id);
			break;
		case 4:
			system("cls");
			apply(id);
			break;
		case 5:
			system("cls");
			modify(id);
			break;
		case 6:
			system("cls");
			if(flag==0){
				printf("\n YOUR ARE NOT SUPPOSE TO ENTER INTO CHAT BOX U NEED TO ACCEPT BY ADMIN \n");
				students_page(id);
			}else{
				chat_box(s[i].name,id);
			}
			
			break;
		case 7:
			system("cls");
			printf("\tLOGGED OUT\n");
			main();
			break;
		default:
			system("cls");
			printf("\tERROR CHOICE \n");
			return students_page(id);
		}
	}

void logg(){
	fflush(stdin);
	struct login pp[4];
	int i,id,tf=0,l;
	char pass[30];
	system("cls");
	printf("\t||   LOGIN   ||\n");
	printf("\tENTER ID ->");
	scanf("%d",&id);
	fflush(stdin);
	printf("\tENTER PASSWORD ->");
	gets(pass);
	l=getsize("logins.txt");
	FILE *fpp;
	fpp=fopen("admin.txt","rb");
	if(fpp==NULL){
		printf("\tERROR! cannot open admin file...");
		exit(0);
	}
	fread(pp,sizeof(struct login),l,fpp);
	fclose(fpp);
	for(i=0;i<l;i++){
		if(id==pp[i].id){
			if(strcmp(pass,pp[i].pass)==0){
				system("cls");
				if(id==pp[0].id){
					printf("\t||  ADMIN  LOGGED IN  SUCCESSFULLY   ||\n");
					admin_page();
				}else{
					printf("\t|| STUDENT LOGGED IN  SUCCESSFULLY   ||\n");
					students_page(id);
				}
				tf=1;
				break;
			}
		}
	}
	if(tf==0){
		system("cls");
		printf("\tERROR WHILE LOGGING IN...\n\tNO SUCH ACCOUNT FOUND...\n");
		main();
	}
	
}
int create_account(){
	fflush(stdin);
	system("cls");
	printf("\t||   CREATE ACCOUNT   ||\n");
	int i,n,l,id,dob[3],co;
	char pass[30],pass2[30];
	l=getsize("logins.txt");
	if(l==0){
		printf("\tno login id passwords found\n");
		return main();
	}
	FILE *ptr1,*ptr2;
	ptr1=fopen("admin.txt","rb");
	if(ptr1==NULL ){
		printf("\tERROR! cannot open file...\n");
		exit(0);
	}
	struct login ad[l+1];
	fread(ad,sizeof(struct login),l,ptr1);
	fclose(ptr1);
	printf("\tENTER ID IN ONLY NUMBERS [ex 181905]\n\n");
	printf("\tENTER ID :");
	fflush(stdin);
	scanf("%d",&id);
	for(i=0;i<l;i++){
		if(id==ad[i].id){
			printf("\tYOUR ACCOUNT IS ALREADY THERE IN OUR DATABASE \n\tIF YOU FORGOT PASSWORD CICK FORGOT PASSWORD\n\n");
			return main();
			break;
		}
	}
	fflush(stdin);
	printf("\tCREATE PASSWORD:");
	gets(pass);
	fflush(stdin);
	printf("\tCONFIRM PASSWORD:");
	gets(pass2);
	printf("ENTER SECURITY KEY DOB[DD-MM-YYYY]:");
	scanf("%d-%d-%d",&dob[0],&dob[1],&dob[2]);
	if(strcmp(pass,pass2)!=0){
		printf("\tPASSWORD NOT MATCHED\n");
		return main();
	}
	printf("1.CONFIRM AND PROCEED \n");
	printf("2.CANCEL AND GO BACK\n");
	scanf("%d",&co);
	if(co!=1){
		printf("CANCELLED SUCCESSFULLY\n");
		return main();
	}
	ptr2=fopen("admin2.txt","wb");
	ad[l].id=id;
	strcpy(ad[l].pass,pass);
	for(co=0;co<3;co++){
		ad[l].dob[co]=dob[co];
	}
	fwrite(ad,sizeof(struct login),l+1,ptr2);
	system("cls");
	printf("\n\tCREATED ACCOUNT SUCESSFULLY\n");
	fclose(ptr2);
	remove("admin.txt");
	rename("admin2.txt","admin.txt");
	store("logins.txt",l+1);
	students_page(id);
}
int forgot_pass(int id){
	fflush(stdin);
	system("cls");
	int i,n,l,place,flag=0,dob[3],s=0;
	char pass[30],pass2[30];
	l=getsize("logins.txt");
	if(l==0){
		printf("\tno login id passwords found\n");
		//return main();
	}
	FILE *ptr1,*ptr2;
	ptr1=fopen("admin.txt","rb");
	if(ptr1==NULL ){
		printf("\tERROR! cannot open file...\n");
		exit(0);
	}
	struct login ad[l];
	fread(ad,sizeof(struct login),l,ptr1);
	fclose(ptr1);
	for(i=0;i<l;i++){
		if(id==ad[i].id){
			printf("\t%d-ID  MATCHED \n\n",id);
			printf("ENTER SECURITY KEY DOB[DD-MM-YYYY]:");
			scanf("%d-%d-%d",&dob[0],&dob[1],&dob[2]);
			flag=1;
			if(dob[0]==ad[i].dob[0] && dob[1]==ad[i].dob[1] && dob[2]==ad[i].dob[2] ){
				place=i;
				s=1;
				break;
			}
			
		}
	}
	if(flag==0){
		printf("\t%d ID NOT MATCHED WITH OUR DATABASE \n",id);
		return main();
	}else{
		if(s==0){
			printf("\t%d  SECURITY KEY NOT MATCHED WITH OUR DATABASE \n",id);
			return main();
		}
	}
	fflush(stdin);
	printf("\tCREATE PASSWORD:");
	gets(pass);
	fflush(stdin);
	printf("\tCONFIRM PASSWORD:");
	gets(pass2);
	if(strcmp(pass,pass2)!=0){
		printf("\tPASSWORD NOT MATCHED\n");
		return main();
	}
	ptr2=fopen("admin2.txt","wb");
	ad[place].id=id;
	strcpy(ad[place].pass,pass);
	fwrite(ad,sizeof(struct login),l+1,ptr2);
	system("cls");
	printf("\tPASSWORD CHANGED SUCESSFULLY\n");
	fclose(ptr2);
	remove("admin.txt");
	rename("admin2.txt","admin.txt");
	if(id==12345){
		admin_page();
	}else{
		students_page(id);
	}
}
int main(){
	int c,id;
	fflush(stdin);
	printf("\t||~~~~~||   WELL-COME  ||~~~~~||\n");
	printf("\t||-----|| PPS-DATABASE ||-----||\n");
	printf("\t1.\tLOGIN\n");
	printf("\t2.\tCREATE ACCOUNT\n");
	printf("\t3.\tFORGOT PASSWORD\n");
	printf("\t4.\tQuit\n");
	printf("\tENTER ->");
	scanf("%d",&c);
	switch(c){
		case 1:
			logg();
			break;
		case 2:
			create_account();
			break;
		case 3:
			system("cls");
			printf("\tENTER ID IN ONLY NUMBERS [ex 181905]\n\n");
			printf("\tENTER ID:");
			scanf("%d",&id);
			forgot_pass(id);
			break;
		case 4:
			printf("\tEXITED\n");
			exit(0);
		default:
			system("cls");
			printf("\tERROR! \n");
			return main();
	}
	
}
