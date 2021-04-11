#pragma once
#include <iostream>
#include <fstream>
using namespace std;
ofstream g("data.txt");
struct tip_data
{
	int zi, luna, an;
};
class Data
{
private:
	tip_data info;
public:
	Data(tip_data);

	void SetZi(int x) { info.zi = x; }
	void SetLuna(int x) { info.luna = x; }
	void SetAn(int x) { info.an = x; }

	int GetZi() { return info.zi; }
	int GetLuna() { return info.luna; }
	int GetAn() { return info.an; }

	bool verif()
	{
		cout << "\nN am considerat anul bisect:( \n";
		if (info.luna==2 && info.zi > 29 || info.luna % 2 == 0 && info.luna <= 7 && info.zi != 30 || info.luna % 2 == 1 && info.luna > 7 && info.zi != 31)
		{
			cout << "\nInvalid\n";
			return false;
		}
		cout << "\nE bun\n";
		return true;
	}
	void parcurg()
	{
		int minus;
		for (int i = info.luna; i <= 12; i++)
		{
			minus = 0;
			if (i % 2 == 0 && i <= 7)
				minus = -1;
			int day = 1;
			if (i == info.luna)
				day = info.zi;
			for (; day <= 31 - minus; day++)
				g << info.zi << ' ' << info.luna << '\n';
		}
	}
};