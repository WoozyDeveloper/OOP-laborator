#pragma once
class Sort
{
	int* myArray;
	int numberOfElements;
public:

	Sort(int n, int min, int max);
	Sort(int* arrayA, int numberOfElements);
	Sort(int count, ...);
	Sort(char* arrayA);
	Sort();

	void InsertSort(bool);
	int partition(bool,int, int);
	void QuickSort(bool,int,int);
	void BubbleSort(bool);
	void Merge(Sort);

	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);
};