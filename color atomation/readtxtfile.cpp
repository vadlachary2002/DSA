#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include "basics.h"
#include <conio.h>

int do_download(char str[]){
	char link[40]="start ";
	strcat(link,str);
	printf("%s\n",link);
	system(link);
	Sleep(1);
	return 0;
}
int do_d(char str[]){
	printf("came\n");
	do_download(str);
	//opend chrome
	go(985,564);//go download 1
		sleep(2);
		leftclick();//lick download 1
		sleep(1);
		wrong();
		
	go(985,564);//go download 1
		sleep(2);
		leftclick();//lick download 1
		sleep(1);
		wrong();
	
	
	sleep(4);
	go(664,226);//go to download 2
	sleep(1);
	leftclick();
	wrong();
	sleep(1);
//	go(664,226);
//	leftclick();
//	sleep(2);
//	wrong();
	sleep(3);
	go(709,17);
	sleep(2);
	leftclick();
	sleep(3);
	
	
}
int main(){
	FILE *ptr;
	char ch ,ylink[30],pre[]="https://www.y2mate.com/",y[40];
	int i=0,count=0;
	ptr=fopen("links.txt","rb");
	if(ptr==NULL){
		printf("cannot rwad file links.txt\n");
		return 1;
	}
	ch=fgetc(ptr);
	while(ch!=EOF){
		if(ch!='\n'){
			if(count>7){
				if(ch!='.' && count!=13){
					ylink[i++]=ch;
			}
				
			}
			count++;
			
		}else{
			strcpy(y,pre);
			strcat(y,ylink);
			printf("%s\n",y);
			do_d(y);
			count=0;
			i=0;
			
		}
		//printf("%c",ch);
		ch=fgetc(ptr);
	}
	fclose(ptr);
}

