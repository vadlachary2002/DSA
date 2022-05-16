#include <stdio.h>
int main(){
	int d,m,y;
	printf("enter date [DD/MM/YYYY]");
	scanf("%d %d %d",&d,&m,&y);
	if(y>0){
		if(m==2){//feb
			if(d>0 && d<28){
				printf("%d-%d-%d",d+1,m,y);
			}else if(d==28){
				// we are checking leap year also
				if(y%400==0){
					printf("%d-%d-%d",d+1,m,y);
				}else if(y%100==0){
					printf("%d-%d-%d",d+1-28,m+1,y);
				}else if(y%4==0){
					printf("%d-%d-%d",d+1,m,y);
				}else{
					printf("%d-%d-%d",d+1-28,m+1,y);
				}
				
			}else if(d==29){
				// we are checking leap year also
				if(y%400==0){
					printf("%d-%d-%d",d+1-29,m+1,y);
				}else if(y%100==0){
					printf("enter correct date  in feb %d",y);
				}else if(y%4==0){
					printf("%d-%d-%d",d+1-29,m+1,y);
				}else{
					printf("enter correct date in feb %d",y);
				}
			}
			else{
				printf("enter correct date in feb");
			}
		}else if(m==12){//december
			if(d>0 && d<31){
				printf("%d-%d-%d",d+1,m,y);
			}else if(d==31){
				printf("%d-%d-%d",d+1-31,m+1-12,y+1);
			}
			else{
				printf("enter correct day in date in dec month");
			}
			
		}else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 ){
			if(d>0 && d<31){
				printf("%d-%d-%d",d+1,m,y);
			}else if (d==31){
				printf("%d-%d-%d",d+1-31,m+1,y);
			}else{
				printf("enter correct day in that month");
			}
		}else if(m==4 || m==6 || m==9 || m==11){
			if(d>0 && d<30){
				printf("%d-%d-%d",d+1,m,y);
			}else if(d==30){
				printf("%d-%d-%d",d+1-30,m+1,y);
			}else{
				printf("enter correct day in that month");
			}
		}else{
			printf("enter correct month");
		}
	}else{
		printf("please enter correct year");
	}
	return 0;
}
