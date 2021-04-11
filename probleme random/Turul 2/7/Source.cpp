#include<iostream>
#include "Seif.h"
using namespace std;
int main()
{
	const char* cifru = "1234";
	Seif s(cifru, 100);
	char pin[50];
	cin.get(pin, 50);
	cin.get();
	bool permis = false;
	if (strcmp(pin, cifru) == 0)
	{
		permis = true;
		cout << "Acces permis\n";
	}
	else
		cout << "Hopaa! Vine politia!\n";
	if (permis == true)
	{
		s.PuneInSeif(1500);
		s.ScoateDinSeif(111);
	}
	return 0;
}