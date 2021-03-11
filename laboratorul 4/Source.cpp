#include <random>
#include <time.h>
#include <iostream>

#include "Sort.h"

using namespace std;

int main()
{
	char vec[] = "10,311,2";
	Sort s1(vec);
	Sort s2(5, 3, 2, 1, 5, 6);
	Sort s3(4, 10, 20);
	s1.Print();
	s2.Print();
	s3.Print();

	cout << s3.GetElementFromIndex(2) << '\n';
	cout << s2.GetElementsCount() << '\n';

	s2.QuickSort(0,0,4);
	s2.Print();
}