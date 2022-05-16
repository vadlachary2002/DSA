#include <windows.h>
#include <iostream>
#include <conio.h>
//int main();
struct capacity{
	float len;
};
int sleep(float sec){
	int s=(int)sec*1000;
	Sleep(s);
}

int minimise(){
	
	fflush(stdin);
	Sleep(1000);
	SetCursorPos(1240,3);
	Sleep(1000);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	Sleep(300);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	printf("\nMINIMISED\n");
	//main();
	
}
int ex(){
	
	fflush(stdin);
	Sleep(1000);
	SetCursorPos(1365,12);
	Sleep(1000);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	Sleep(300);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	printf("\nEXITED\n");
	//main();
}
int maximise(){
	
	fflush(stdin);
	Sleep(1000);
	SetCursorPos(1276,5);
	Sleep(1000);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	Sleep(300);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	printf("\nMAXIMISED\n");
	//main();
}
int undertab(){
	
	fflush(stdin);
	Sleep(1000);
	SetCursorPos(716,767);
	Sleep(1000);
	
	printf("\nOPENED UNDER TAB\n");
	
}
int chrome(){
	
	fflush(stdin);
	Sleep(1000);
	SetCursorPos(558,748);
	Sleep(1000);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	Sleep(300);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	printf("\nOPENED CHROME\n");
	Sleep(1000);
	
	
	
	
}
int chrome_chary(){
	Sleep(1000);
	SetCursorPos(697,424);
	Sleep(1000);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	Sleep(300);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}
float see(){
	system("cls");
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
	return n;
}
int enter(){
	keybd_event(0x0D,0,KEYEVENTF_EXTENDEDKEY,0);
	Sleep(100);
	keybd_event(0x0D,0,KEYEVENTF_KEYUP,0);
}
int leftclick(){
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
}
int rightclick(){
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);	
	Sleep(100);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
}
int confirm(){
	Sleep(300);
	SetCursorPos(1213,596);
	Sleep(300);
}
int cancel(){
	Sleep(300);
	SetCursorPos(1121,596);
	Sleep(300);
}
int ok(){
	Sleep(300);
	SetCursorPos(768,480);
	Sleep(300);
}
int go(int x,int y){
	Sleep(300);
	SetCursorPos(x,y);
	Sleep(300);
}
int wrong(){
	Sleep(100);
	go(950,15);
	Sleep(100);
	leftclick();
	Sleep(100);
}
//
//int main(){
//	fflush(stdin);
//	int n;
//	printf("1.MINIMISE\n2.EXIT TAB\n->");
//	scanf("%d",&n);
//	switch(n){
//		case 1:
//			minimise();
//			break;
//		case 2:
//			ex();
//			break;
//		default:
//			system("cls");
//			printf("ERROR!\n");
//			main();
//	}
//}
