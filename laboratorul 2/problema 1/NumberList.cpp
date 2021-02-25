#include "NumberList.h"

#include <iostream>

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count == 10)
		return false;
	this->numbers[count] = x;
    this->count++;
	return true;
}

void NumberList::Sort()
{
    int i, nr, j;
    for (int i = 0; i < this->count; i++)
    {
        nr = this->numbers[i];
        j = i - 1;

        while (j >= 0 && this->numbers[j] > nr)
        {
            this->numbers[j + 1] = this->numbers[j];
            j--;
        }
        this->numbers[j + 1] = nr;
    }
}

void NumberList::Print()
{
    for (int i = 0; i < this->count; i++)
		std::cout << this->numbers[i] << ' ';
}