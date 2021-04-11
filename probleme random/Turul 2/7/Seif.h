#pragma once
#include <iostream>
using namespace std;

class Seif
{
private:
	char cifru[50];
	int suma;
	int getSuma()
	{
		return suma;
	}
	void setSuma(int val)
	{
		suma = val;
	}
public:
	Seif(const char*, int);
	void ScoateDinSeif(int x)
	{
		suma -= x;
	}
	void PuneInSeif(int x)
	{
		suma += x;
	}
};