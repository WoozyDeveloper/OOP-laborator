#include "Vector.h"
#include <stdlib.h>

Vector::Vector()
{
	dim = 0;
}
bool Vector::Add(int item)
{
	v = (int*)realloc(v, ++dim * sizeof(int));
	if (v != nullptr)
	{
		v[dim - 1] = item;
		return true;
	}
	return false;
}
bool Vector::Delete(int index)
{
	for (int i = index; i < dim ; i++)
		v[i] = v[i + 1];
	v = (int*)realloc(v, --dim * sizeof(int));
	if(v != nullptr)
		return true;
	return false;
}