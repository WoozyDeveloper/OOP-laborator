#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

#include "Number.h"

using namespace std;

int main()
{
	Number n1("24", 10);
	Number n2("40", 10);
	Number n3("44", 10);

	printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
	for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
	{
		printf("n1[%d]=%c\n", tr, n1[tr]);
	}
	n1.Print();
	n2.Print();
	n1 = n2 + n3 - n1; // after this n1 will be in base 16
	n1.Print();
	if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");
	Number n4("10", 10);
	n4 = 1234; // n4 will be in base 10
	n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
	n4.Print();
	n4 = "13579"; // n4 mentains its base (10) and will be 13579
	n4.Print();
	--n4; // the first digit from n4 will be remove ==> n4 becomes 3579
	n4.Print();
	n4--; // the last digit from n4 will be remove ==> n4 becomes 357
	n4.Print();
	Number n5("FF", 16);
	Number n6("10", 10);
	(n5 | n6).Print();

	n1 = 10;
	n2 = 8;
	if (n1 > n2)
		cout << "n1";
	else
		cout << "n2";
	return 0;

}