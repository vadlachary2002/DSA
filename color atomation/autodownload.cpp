#include <windows.h>
#include <iostream>
#include <conio.h>
#include "basics.h"
int sleep(float sec){
	int s=(int)sec*1000;
	Sleep(s);
}
int wrong(){
	Sleep(100);
	go(950,15);
	Sleep(100);
	leftclick();
	Sleep(100);
}
using namespace std;
int main(){
	undertab();
	chrome();
	sleep(0.5);
	go(1078,533);//videp
	leftclick();
	sleep(6);
	
	
	go(611,726);//share
	leftclick();
	sleep(4);
	go(876,474);//copy
	sleep(1);
	leftclick();
	sleep(1);
	go(912,295);//share cancel
	sleep(2);
	sleep(1);
	leftclick();
	//copied the link go to y2mate
	go(587,10);//y2mate
	leftclick();
	sleep(2);
	go(543,329);//input field
	rightclick();
	Sleep(2000);
	go(603,428);
	leftclick();
	sleep(4);
	go(985,564);//download1
	sleep(3);
	leftclick();
	wrong();
	go(664,226);
	sleep(4);
	leftclick();
	go(300,157);
	sleep(3);
	leftclick();
	
	
	
	
}
