#include "myVector.h"

#include <iostream>

using namespace std;

int main()
{
	myVector<int> vect;
	myVector<int> vect2;
	vect.push(4);
	vect.push(2);
	vect.push(1);
	vect.insert(3, 1);
	//4 3 2 1
	vect.delete_element(1);
	//4 2 1
	vect.set(3, 0);
	//3 2 1
	vect.sort(ascendent);
	//1 2 3
	vect.print();
	vect.sort();
	//3 2 1
	vect.print();
	cout << vect.firstIndex(condition);
	//1
	vect2.push(1);
	vect2.push(3);
	cout << "\n\n\n\n";
	vect.print();
	vect2.print();
	cout << "\n";
	vect.schimba(vect2);
	vect.print();
	vect2.print();
	//3
}