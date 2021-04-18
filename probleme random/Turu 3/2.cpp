#include<iostream>
#include <stdlib.h>
using namespace std;
class tablou
{
private:
	int* element;
	int dim;
public:
	tablou()
	{
		element = NULL;
		dim = 0;
	}
	void SetDim(int val)
	{
		dim = val;
	}
	int GetElemFromIndex(int index)
	{
		if (index < 0 || index >= dim)
		{
			cout << "Invalid index";
			exit(101);
			return -1;
		}
		return element[index];
	}
	int GetDim()
	{
		return dim;
	}
	void ShowValues()
	{
		for (int i = 0; i < dim; i++)
			cout << element[i] << ' ';
	}
	void AddElement(int val)
	{
		++dim;
		element = (int*)realloc(element, dim * sizeof(int));
		element[dim - 1] = val;
	}
	void AddArrays(tablou& x, tablou& y)
	{
		int dim = (x.GetDim() > y.GetDim() ? y.GetDim() : x.GetDim());
		
		for (int i = 0; i < dim; i++)
		{
			int dif = x.GetElemFromIndex(i) - y.GetElemFromIndex(i);
			//cout << i << ' ';
			this->AddElement(dif);
		}
	}
};

int main()
{
	tablou a, b, c;
	a.AddElement(2);
	a.AddElement(4);
	a.AddElement(6);
	b.AddElement(1);
	b.AddElement(1);
	b.AddElement(1);
	c.AddArrays(a, b);
	c.ShowValues();
}
