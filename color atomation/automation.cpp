#include <windows.h>
#include <iostream>
#include <conio.h>
#include "basics.h"



using namespace std;
int main(){
	cout<<"hi"<<endl;
	while(1){
		cout<<"to find cursor position click 'g'"<<endl;
		cout<<"to set cursor position click 's'"<<endl;	
		cout<<"to set cursor position click 'b'"<<endl;	
		cout<<"to set cursor position click 's'"<<endl;	
		cout<<"to set cursor position click 'e'"<<endl;	
		cout<<"to set cursor position click 'm'"<<endl;	
		cout<<"to set cursor position click 'x'"<<endl;		
		char g = getch();
		int x,y;
		POINT xypos;
		if(g=='S' || g =='s'){
			cout<<"enter the new position"<<endl;
			cin>>x>>y;
			SetCursorPos(x,y);
			
		}else if(g== 'G' || g=='g'){
			GetCursorPos(&xypos);
			cout<<"X:"<<xypos.x<<"\tY:"<<xypos.y<<endl;
			
			
		}else if(g=='B' || g=='b'){
			SetCursorPos(553,767);
			Sleep(1000);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(1000);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(100);
			SetCursorPos(694,430);
			Sleep(3000);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(300);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(3000);
			SetCursorPos(380,86);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(300);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(3000);
			SetCursorPos(544,405);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(300);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(3000);
			SetCursorPos(554,459);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(300);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(3000);
			SetCursorPos(586,550);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(300);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(6000);
			SetCursorPos(1053,274);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(300);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(5000);
			SetCursorPos(877,296);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(300);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			minimise();
			
			
			
			
			//SetCursorPos(1365,12);
			
		}else if(g == 'e' ){
			cout<<"exiting within 30mseconds "<<endl;
			Sleep(30000);
			SetCursorPos(1365,12);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(300);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			
		}else if(g =='m' || g=='M'){
			cout<<"copying"<<endl;
			Sleep(3000);
			SetCursorPos(742,93);
			Sleep(1000);
			
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);	
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);	
			Sleep(100);
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);	
			Sleep(1000);
			SetCursorPos(820,164);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(3000);
			char text[20];
			cout<<"enter that name"<<endl;
			scanf("%s",&text);
			SetCursorPos(679,424);
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			Sleep(1000);
			mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);	
			Sleep(100);
			mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
			
			
			
				
			
			
		}else if(g == 'x' || g=='X'){
			undertab();
			chrome();
			
		}
	}
}
