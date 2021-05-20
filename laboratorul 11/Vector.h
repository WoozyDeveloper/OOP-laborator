#pragma once
#include<iostream>
using namespace std;
class Vector {
private:
    int* v;
    int dim;
public:
	void Iterate(void (*change)(int& tablou))
	{
		for (int i = 0; i < dim; i++)
			change(v[i]);
	}
	void Filter(bool(*elim)(int& tablou))
	{
		for (int i = 0; i < dim; i++)
			if (elim(v[i]) == true)
			{
				Delete(i);
				i--;
			}
	}
    Vector();
    bool Add(int); // return true if the value was added. As a result, the size of the vector increases with one.
    bool Delete(int index); // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.
	void Print()
	{
		for (int i = 0; i < dim; i++)
			cout << v[i] << ' ';
		cout << endl;
	}
};