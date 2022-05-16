#include <windows.h>
#include <iostream>
#include <conio.h>
#include "basics.h"
#include <stdlib.h>
#include <string.h>
int initial;
float have,profit=0;
//float amount=see();
char colors[5];


int call_colors(int flag){
	int i;
	char c;
	if(flag==0){
		printf("enter last 5 colors \t\t[r-red\tg-green]\n");
		for(i=0;i<5;i++){
			fflush(stdin);
			printf("->");
			scanf("%c",&colors[i]);
		}
	}else if(flag==1){
		if(strcmp(colors,"rgrgr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}else if(strcmp(colors,"grgrg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"rrrrr")==0){
			colors[4]='r';
		}
		else if(strcmp(colors,"ggggg")==0){
			colors[4]='g';
		}else if(strcmp(colors,"rrggr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}else if(strcmp(colors,"rggrr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"ggrrg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"grrgg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"rrggg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}else if(strcmp(colors,"ggrrr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}else if(strcmp(colors,"rrrgg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}else if(strcmp(colors,"gggrr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"grrrr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"rgggg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"rrrrg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"ggggr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		
		else if(strcmp(colors,"grrgr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"rggrg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"ggrgg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"rrgrr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"rgggr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"grrrg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		
		else if(strcmp(colors,"rgrrg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"grggr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"rgrrr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"grggg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"rgrgg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"grgrr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		else if(strcmp(colors,"ggrgr")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='r';
		}
		else if(strcmp(colors,"rrgrg")==0){
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
		}
		
		
		else{
			for(i=0;i<4;i++){
				fflush(stdin);
				colors[i]=colors[i+1];
			}
			colors[4]='g';
			printf("colros prediction not happen \n");
		}
	}
}
float see_amount(){
	Sleep(500);
	undertab();
	chrome();
	SetCursorPos(223,131);
	Sleep(500);
	leftclick();
	Sleep(100);
	leftclick();
	Sleep(500);
	rightclick();
	Sleep(500);
	SetCursorPos(280,141);
	leftclick();
	Sleep(1000);
	//under tab
	SetCursorPos(614,767);
	Sleep(1000);
	SetCursorPos(698,635);
	Sleep(500);
	leftclick();
	Sleep(1000);
	SetCursorPos(476,329);
	Sleep(1000);
	rightclick();
	Sleep(500);
	enter();
	Sleep(1000);
	
	//minimise();
	float n;
	n=see();
	return n;

	
	
	
	
	
	
}
int refresh(){
	undertab();
	chrome();
	Sleep(100);
	SetCursorPos(1301,180);
	Sleep(1000);
	leftclick();
	Sleep(1000);
	leftclick();
	Sleep(1000);
	undertab();
	chrome();
	
	
	
}
int choose_color(char c){
	if(c=='g'){
		Sleep(500);
		SetCursorPos(224,396);
		Sleep(500);
		leftclick();
		Sleep(500);
	}else if(c=='r'){
		Sleep(500);
		SetCursorPos(1134,400);
		Sleep(500);
		leftclick();
		Sleep(500);
	}
}
int set_amount(char c,int money[4]){
	int ones,tens,hund,th,i;
	ones=money[0];
	tens=money[1];
	hund=money[2];
	th=money[3];
	if(ones>0){
		choose_color(c);
		SetCursorPos(981,454); //ones
		Sleep(300);
		for(i=0;i<ones-1;i++){
			leftclick();
			Sleep(300);
		}
		confirm();
		leftclick();
		Sleep(800);
		ok();
		leftclick();
		Sleep(500);
		
	}
	if(tens>0){
		choose_color(c);
		SetCursorPos(142,357);
		Sleep(500);
		leftclick();
		Sleep(300);
		SetCursorPos(981,454);
		Sleep(300);
		for(i=0;i<tens-1;i++){
			leftclick();
			Sleep(300);
		}
		confirm();
		leftclick();
		Sleep(800);
		ok();
		leftclick();
		Sleep(500);
	}
	if(hund>0){
		choose_color(c);
		SetCursorPos(181,361);
		Sleep(500);
		leftclick();
		Sleep(300);
		SetCursorPos(981,454);
		Sleep(300);
		for(i=0;i<hund-1;i++){
			leftclick();
			Sleep(300);
		}
		confirm();
		leftclick();
		Sleep(800);
		ok();
		leftclick();
		Sleep(500);
	}
	if(th>0){
		choose_color(c);
		SetCursorPos(233,361);
		Sleep(500);
		leftclick();
		Sleep(300);
		SetCursorPos(981,454);
		Sleep(300);
		for(i=0;i<th-1;i++){
			leftclick();
			Sleep(300);
		}
		confirm();
		leftclick();
		Sleep(800);
		ok();
		leftclick();
		Sleep(500);
	}
	
	
	
	
}
int set_color(char c,int a){
	int temp=a;
	fflush(stdin);
	int money[]={0,0,0,0},i=0;
	undertab();
	chrome();
	Sleep(1000);
	printf("colors is %c\n",c);
	printf("a=%d\n",a);
	while(a>0){
		money[i]=a%10;
		a=a/10;
		i++;
		
	}
	printf("ones -%d\ntens-%d\nhund-%d\nth-%d\n",money[0],money[1],money[2],money[3]);
	printf("Ordered Amount is %d\n",temp);
	
	
	Sleep(500);
	set_amount(c,money);
	
	
	
	
}
int main(){
	int i,n,flag=0,in;
	printf("Set initial amouunt:");
	scanf("%d",&initial);
	in=initial;
	call_colors(0);
	float a1,a2;
	a1=see_amount();
	have=a1;
	call_colors(1);
	printf("Predicted color is %c\n",colors[4]);
	printf("Colors is %s\n",colors);
	set_color(colors[4],initial);
	printf("\nWaiting\n");
	minimise();
	Sleep(120000);
	while(1){
		refresh();
		Sleep(4000);
		a2=see_amount();
		if(a1==a2){
			printf("no lose no win\n");
		}else if(a1>a2){
			printf("loss of %d\n",initial);
			initial =2*initial;
			
			if(colors[4]=='g'){
				colors[4]='r';
			}else{
				colors[4]='g';
			}
			
			
		}else if(a1<a2){
			printf("win of %d\n",initial);
			profit=a2-have;
			printf("current profit %f\n",profit);
			if(profit>100 || (a2<300 && a2>100)){
				exit(0);
			}
			
			initial=in;
			
			
			
		}
		call_colors(1);
		
		printf("colors :%s\n",colors);
		printf("Predicted color is %c\n",colors[4]);
		
		
		
		set_color(colors[4],initial);
		printf("Before amount is %f\n",a1);
		printf("After amount is %f\n",a2);
		printf("Waiting 3 minutes\n");
		minimise();
		a1=a2;
		Sleep(132000);
	}
	
	//set_color(a,)
	//printf("\nnum is %d\n",n);
	getch();
	
	
	
	
	
}
