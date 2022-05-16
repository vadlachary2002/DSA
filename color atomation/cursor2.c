#include <stdio.h>
#include <math.h>
struct capacity{
	float len;
};

float see(){
	
	fflush(stdin);
	float n;
	FILE *p;
	p=fopen("cur.txt","rb");
	if(p==NULL){
		printf("error opening file\n");
	}
	struct capacity s[1];
	fread(s,sizeof(struct capacity),1,p);
	n=s[0].len;
	printf("\nvalue is %f\n",s[0].len);
	fclose(p);
	main();
}
int set(){
	
	fflush(stdin);
	float n;
	printf("enter number :");
	scanf("%f",&n);
	FILE *p;
	p=fopen("cur.txt","wb");
	if(p==NULL){
		printf("error opening file\n");
	}
	struct capacity s[1];
	s[0].len=n;
	fwrite(s,sizeof(struct capacity),1,p);
	fclose(p);
	printf("entere successfully\n");
	main();
}
int main(){
	fflush(stdin);
	int c;
	printf("1.SET\n");
	printf("2.SEE\n->");
//	printf("c=");
//	scanf("%d",&c);
	c=1;
	int money[4],i=0,a;
	
	
	switch(c){
		case 1:
			set();
			break;
		case 2:
			see();
			break;
		case 3:
			
			printf("a=");
			scanf("%d",&a);	
			
			//Sleep(1000);
			//printf("colors is %c\n",c);
			while(a>0){
				money[i]=a%10;
				a=a/10;
				i++;
			}
			printf("ones -%d\ntens-%d\nhund-%d\nth-%d\n",money[0],money[1],money[2],money[3]);
			break;
		default:
			system("cls");
			printf("ERROR!\n");
			main();
	}
}
