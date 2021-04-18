#include<iostream>
#include<cmath>
using namespace std;
enum axis
{
	X = 1, Y, Z
};
class Punct
{
private:
	double x, y, z;
public:
	Punct()
	{
		cin >> x >> y >> z;
	}
	double GetX() { return x; }
	double GetY() { return y; }
	double GetZ() { return z; }
	void Trans(axis x, double distance)
	{
		switch (x)
		{
		case X:
			this->x = this->x + distance;
			break;
		case Y:
			this->y = this->y + distance;
			break;
		case Z:
			this->z = this->z + distance;
			break;
		default:
			exit(404);
		}
	}
};

double distance(Punct a, Punct b)
{
	return sqrt(pow(b.GetX() - a.GetX(), 2) + pow(b.GetY() - a.GetY(), 2) + pow(b.GetZ() - a.GetZ(), 2));
}

int main()
{
	Punct a, b;
	Punct c = a;
	double dist = distance(a, b);
	c.Trans(X, 5);
	if (distance(a, c) == dist)
	{
		cout << "Pt ox";
		return 0;
	}
	c = a;
	c.Trans(Y, 5);
	if (distance(a, c) == dist)
	{
		cout << "Pt oy";
		return 0;
	}
	c = a;
	c.Trans(Z, 5);
	if (distance(a, c) == dist)
	{
		cout << "Pt oz";
		return 0;
	}
	cout << "No se puede";
	return 0;
}