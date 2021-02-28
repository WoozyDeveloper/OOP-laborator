#include "NumberList.h"

#include <iostream>

using namespace std;

int main()
{
	NumberList numberList;

	numberList.Init();

	numberList.Add(20);
	numberList.Add(2);
	numberList.Add(2);
	numberList.Add(7);
	numberList.Add(100);

	
	numberList.Print();
	std::cout << '\n';
	numberList.Sort();

	numberList.RemoveNumber(2);
	numberList.Insert(4, 333);
	

	numberList.Print();
	return 0;
}