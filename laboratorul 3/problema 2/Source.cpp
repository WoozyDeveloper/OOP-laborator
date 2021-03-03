#include "Canvas.h"

#include <iostream>
#include <Windows.h>

#define WAIT 1000

using namespace std;

void pause()
{
	Sleep(WAIT);
	system("cls");
}

int main()
{
	Canvas* canv = new Canvas(20,20);
	canv->DrawCircle(3, 3, 6, '#');
	canv->Print();
	pause();
	canv->FillCircle(3, 3, 6, '#');
	canv->Print();
	pause();
	canv->DrawLine(1,1,16,12,'X');
	canv->Print();
	pause();
	canv->DrawRect(10, 10, 20, 20,'8');
	canv->Print();
	pause();
	canv->FillRect(10, 10, 20, 20, '8');
	canv->Print();
	pause();
	canv->Clear();
	pause();
	return 0;
}