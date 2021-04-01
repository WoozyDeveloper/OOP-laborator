#pragma once
#include <iostream>

using namespace std;


template <typename T>
bool ascendent(T a = 0, T b = 0)
{
	return a > b ? true : false;
}

template <typename T>
bool descendent(T a = 0, T b = 0)
{
	return a < b ? true : false;
}

template <typename T>
bool condition(T element = 1)
{
	if (element % 2 == 0)
		return true;
	return false;
}

template <typename T>
class myVector
{
private:
	T* array;
	int arraySize, memory;
public:

	void schimba(myVector<T> &newVector)
	{
		if (arraySize > newVector.count())
		{
			for (int i = 0; i < newVector.count(); i++)
				swap(array[i], newVector.array[i]);
			for (int i = newVector.count(); i < arraySize; i++)
			{
				newVector.push(array[i]);
				arraySize--;
			}
		}
		else
		{
			for (int i = 0; i < count(); i++)
				swap(array[i], newVector.array[i]);
			for (int i = count(); i < newVector.count(); i++)
			{
				push(newVector.array[i]);
				newVector.setDim(newVector.count() - 1);
			}
		}
	}

	int firstIndex(bool (*condition)(T) = nullptr)
	{
		for (int i = 0; i < arraySize; i++)
			if (condition(array[i]))
				return i;
		return -1;
	}

	myVector()
	{
		memory = 1;
		array = (T*)malloc(sizeof(T));
		arraySize = 0;
	}

	~myVector() {}

	void setDim(int dim)
	{
		arraySize = dim;
	}

	void push(T element)
	{
		++arraySize;
		if (memory == arraySize)
		{
			memory *= 2;
			array = (T*)realloc(array, memory * sizeof(T));
		}
		array[arraySize - 1] = element;
	}

	T pop()
	{
		return array[arraySize - 1];
	}

	void sort(bool (*comp)(T ,T) = nullptr)
	{
		for (int i = 0; i < arraySize - 1; i++)
			for (int j = i + 1; j < arraySize; j++)
				if (comp!=nullptr && comp(array[i], array[j]))
					swap(array[i], array[j]);
				else
				{
					if (array[i] < array[j])
						swap(array[i], array[j]);
				}
				
	}

	void delete_element(int index)
	{
		for (; index < arraySize; ++index)
			array[index] = array[index + 1];
		--arraySize;
	}

	void insert(T element, int index)
	{
		int copy;
		++arraySize;
		for (; index < arraySize; ++index)
		{
			copy = array[index];
			array[index] = element;
			element = copy;
		}
	}

	void set(const T element, int index)
	{
		array[index] = element;
	}

	const T& get(int index)
	{
		return &array[index];
	}

	int count()
	{
		return arraySize;
	}

	void print()
	{
		for (int i = 0; i < arraySize; i++)
			cout << array[i] << ' ';
		cout << '\n';
	}
};