#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <cstdarg>
#include "Sort.h"

using namespace std;

void Sort::Merge(Sort other)
{
	int firstDim = this->numberOfElements;
	int* aux = this->myArray;
	this->numberOfElements += other.GetElementsCount();
	this->myArray = (int*)malloc(numberOfElements * sizeof(int));
	for (int i = 0; i < firstDim; ++i)
		this->myArray[i] = aux[i];
	for (int i = 0; i < other.GetElementsCount(); i++)
		this->myArray[i + firstDim] = other.GetElementFromIndex(i);
	this->InsertSort(true);
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void Sort::BubbleSort(bool ascendent = false)
{
	int i, j;
	if (ascendent == true)
	{
		for (i = 0; i < this->numberOfElements - 1; i++)
			for (j = 0; j < this->numberOfElements - i - 1; j++)
				if (this->myArray[j] > this->myArray[j + 1])
					swap(&this->myArray[j], &this->myArray[j + 1]);
	}
	else
		for (i = 0; i < this->numberOfElements - 1; i++)
			for (j = 0; j < this->numberOfElements - i - 1; j++)
				if (this->myArray[j] < this->myArray[j + 1])
					swap(&this->myArray[j], &this->myArray[j + 1]);
}

int Sort::partition (bool ascendent, int low, int high) 
{ 
	int pivot = this->myArray[high];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (ascendent == true)
		{
			if (this->myArray[j] < pivot)
			{
				i++;
				swap(&this->myArray[i], &this->myArray[j]);
			}
		}
		else
		{
			if (this->myArray[j] > pivot)
			{
				i++;
				swap(&this->myArray[i], &this->myArray[j]);
			}
		}
	}
	swap(&this->myArray[i + 1], &this->myArray[high]);
	return (i + 1);
} 

void Sort::QuickSort(bool ascendent,int low,int high)
{
	if (low < high)
	{
		int pi = partition(ascendent, low, high);
		QuickSort(ascendent, low, pi - 1);
		QuickSort(ascendent, pi + 1, high);
	}
}

void Sort::InsertSort(bool ascendent = false)
{
	int i, key, j;
	if(ascendent == false)
		for (i = 1; i < this->numberOfElements; i++)
		{
			key = this->myArray[i];
			j = i - 1;

			while (j >= 0 && this->myArray[j] < key)
			{
				this->myArray[j + 1] = this->myArray[j];
				j = j - 1;
			}
			this->myArray[j + 1] = key;
		}
	else
		for (i = 1; i < this->numberOfElements; i++)
		{
			key = this->myArray[i];
			j = i - 1;

			while (j >= 0 && this->myArray[j] > key)
			{
				this->myArray[j + 1] = this->myArray[j];
				j = j - 1;
			}
			this->myArray[j + 1] = key;
		}
}

Sort::Sort(int numberOfElements, int minimumValue, int maximumValue)
{
	this->numberOfElements = numberOfElements;
	this->myArray = (int*)malloc(numberOfElements * sizeof(int));

	/* Intializes random number generator */
	srand((unsigned)time(NULL));

	for (int index1 = 0; index1 < numberOfElements; ++index1)
		this->myArray[index1] = minimumValue + rand() % (maximumValue - minimumValue + 1);

}

Sort::Sort() : myArray(new int[6]{ 1, 33, 9, 4, 5, 7 })
{
	this->numberOfElements = 6;
}

Sort::Sort(int* arrayA, int numberOfElements)
{
	this->numberOfElements = numberOfElements;
	this->myArray = (int*)malloc(numberOfElements * sizeof(int));
	for (int index1 = 0; index1 < numberOfElements; ++index1)
		this->myArray[index1] = arrayA[index1];
}

Sort::Sort(int count, ...)
{
	this->numberOfElements = count;
	this->myArray = (int*)malloc(count * sizeof(int));

	va_list pargs;
	va_start(pargs, count);

	for (int i = 0; i < count; i++)
		this->myArray[i] = va_arg(pargs, int);
	
	va_end(pargs);
}

int convertNumber(char* nr)
{
	int res = 0;
	int dim = strlen(nr);
	for (int i = 0; i < dim; ++i)
		res = res * 10 + nr[i] - '0';
	return res;
}

Sort::Sort(char* arrayA)
{
	this->numberOfElements = 0;
	char* pch;
	pch = strtok(arrayA, ",");
	while (pch != nullptr)
	{
		this->myArray = (int*)realloc(this->myArray, (this->numberOfElements + 1) * sizeof(int));
		this->myArray[this->numberOfElements] = convertNumber(pch);
		this->numberOfElements++;
		pch = strtok(NULL, ",");
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->numberOfElements; ++i)
		cout << this->myArray[i] << ' ';
	cout << '\n';
}

int Sort::GetElementsCount()
{
	return this->numberOfElements;
}

int Sort::GetElementFromIndex(int index)
{
	return this->myArray[index];
}