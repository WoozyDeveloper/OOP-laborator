#include "Math.h"

#include <iostream>

using namespace std;
int main()
{
	const char* s1 = "First";
	const char* s2 = "Second";
	int a = 2, b = 3, c = 4;
	double x = 5.5, y = 1.1, z = 0.75;
	Math math;
	cout << "INT\n";
	cout << math.Add(a, b) << '\n';
	cout << math.Add(a, b, c) << '\n';
	cout << math.Mul(a, b) << '\n';
	cout << math.Mul(a, b, c) << '\n';
	cout << "DOUBLE\n";
	cout << math.Add(x, y) << '\n';
	cout << math.Add(x, y, z) << '\n';
	cout << math.Mul(x, y) << '\n';
	cout << math.Mul(x, y, z) << '\n';
	cout << "MULTIPLE PARAMS\n";
	cout << math.Add(5, 1, 1, 1, 1, 2) << '\n';
	cout << "CONCAT\n";
	cout << math.Add(s1, s2);
}