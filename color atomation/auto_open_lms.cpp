#include "windows.h"
#include <iostream>
#include <conio.h>
#include "basics.h"
#include <stdlib.h>
#include <string.h>
int lms[]={396,82};
int user[]={497,434};
int chary[]={519,138};
int login[]={575,586};
int atnd[]={1002,329,1084,344};
int n_tab[]={364,12};
int date[]={428,412,474,426};
int main(){
	undertab();
	chrome();
	go(lms[0],lms[1]);
	leftclick();
	Sleep(1000);
	go(497,434);
	leftclick();
	Sleep(1000);
	go(519,138);
	leftclick();
	Sleep(1000);
	go(575,586);
	Sleep(100);
	leftclick();
	Sleep(6000);
	go(atnd[0],atnd[1]);
	rightclick();
	Sleep(1000);
	go(atnd[2],atnd[3]);
	leftclick();
	Sleep(500);
	go(n_tab[0],n_tab[1]);
	leftclick();
	Sleep(300);
	go(date[0],date[1]);
	leftclick();
	Sleep(100);
	leftclick();
	Sleep(300);
	rightclick();
	go(date[2],date[3]);
	Sleep(200);
	leftclick();
}
