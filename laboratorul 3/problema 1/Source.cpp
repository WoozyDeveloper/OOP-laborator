#include "Math.h"

#include <iostream>

using namespace std;
int main()
{
	const char* s1 = "First";
	const char* s2 = "Second";
	int a = 2, b = 3, c = 4;
	double x = 5.5, y = 1.1, z = 0.75;
	cout << "INT\n";
	cout << Math::Add(a, b) << '\n';
	cout << Math::Add(a, b, c) << '\n';
	cout << Math::Mul(a, b) << '\n';
	cout << Math::Mul(a, b, c) << '\n';
	cout << "DOUBLE\n";
	cout << Math::Add(x, y) << '\n';
	cout << Math::Add(x, y, z) << '\n';
	cout << Math::Mul(x, y) << '\n';
	cout << Math::Mul(x, y, z) << '\n';
	cout << "MULTIPLE PARAMS\n";
	cout << Math::Add(5, 1, 1, 1, 1, 2) << '\n';
	cout << "CONCAT\n";
	cout << Math::Add(s1, s2);
}