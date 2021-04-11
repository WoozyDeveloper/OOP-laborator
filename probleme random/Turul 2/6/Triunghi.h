#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Triunghi
{
private:
	int a, b, c;
	bool eTriunghi(int x, int y, int z)
	{
		if (x * y * z < 0)
			return false;
		if (x + y < z || x + z < y || y + z < x)
			return false;
		return true;
	}
public:
	Triunghi(int x, int y, int z)
	{
		if (!eTriunghi(x, y, z))
		{
			cout << "\nLaturile nu formeaza un triunghi\n";
			return;
		}
		SetA(x);
		SetB(y);
		SetC(z);
	}

	double Arie()
	{ 
		double p = (double)(a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	int Perimetru()
	{
		return a + b + c;
	}

	bool verif(int x, int y, int z)
	{
		if (pow(x, 2) + pow(y, 2) == pow(z, 2))
			return true;
		return false;
	}

	bool Dreptunghic()
	{
		if (verif(a, b, c) || verif(a, c, b) || verif(b, c, a))
			return true;
		return false;
	}

	int GetA() { return a; }
	int GetB() { return b; }
	int GetC() { return c; }

	void SetA(int x) { a = x; }
	void SetB(int x) { b = x; }
	void SetC(int x) { c = x; }
};