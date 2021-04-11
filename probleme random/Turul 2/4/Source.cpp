#include<iostream>
#include"data.h"
using namespace std;
int main()
{
	tip_data tip;
	tip.zi = 2;
	tip.luna = 3;
	tip.an = 4;
	Data d(tip);
	d.verif();
	d.parcurg();
}