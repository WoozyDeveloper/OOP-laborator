#include <iostream>
#include "PilotF1.h"

using namespace std;

int main()
{
	PilotF1 p1, p2, p3;
	char name[30];
	int varsta, record, pole_pos;

	cout << "Primul pilot\n";
	cin.get(name, 30);
	cin.get();
	cin >> varsta >> record >> pole_pos;
	p1.SetName(name);
	p1.SetNrPolePos(pole_pos);
	p1.SetRecord(record);
	p1.SetVarsta(varsta);

	cout << "Al doilea pilot\n";
	cin.get();
	cin.get(name, 30);
	cin >> varsta >> record >> pole_pos;
	p2.SetName(name);
	p2.SetNrPolePos(pole_pos);
	p2.SetRecord(record);
	p2.SetVarsta(varsta);

	cout << "Al treilea pilot\n";
	cin.get();
	cin.get(name, 30);
	cin.get();
	cin >> varsta >> record >> pole_pos;
	p3.SetName(name);
	p3.SetNrPolePos(pole_pos);
	p3.SetRecord(record);
	p3.SetVarsta(varsta);

	cout << "\np1:\n";
	cout << p1.GetName() << ' ' << p1.GetVarsta() << ' ' << p1.GetRecord() << ' ' << p1.GetNrPolePosition();

	cout << "\np2:\n";
	cout << p2.GetName() << ' ' << p2.GetVarsta() << ' ' << p2.GetRecord() << ' ' << p2.GetNrPolePosition();

	cout << "\np3:\n";
	cout << p3.GetName() << ' ' << p3.GetVarsta() << ' ' << p3.GetRecord() << ' ' << p3.GetNrPolePosition();
}