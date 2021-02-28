#include "NumberList.h"

#include <iostream>

bool NumberList::Insert(int pos, int x)
{
    if (count == 10)
        return false;
    this->count++;
    int aux = 0;
    for (int i = pos-1; i < this->count; i++)
    {
        aux = this->numbers[i];
        this->numbers[i] = x;
        x = aux;
    }
    return true;
}

bool NumberList::RemoveNumber(int x)
{
    bool removedStatus = false;
    for (int i = 0; i < this->count; i++)
    {
        if (this->numbers[i] == x)
        {
            removedStatus = true;
            for (int j = i; j < this->count - 1; j++)
                this->numbers[j] = this->numbers[j + 1];
            this->count--;
            i--;
        }
    }
    return removedStatus;
}

void NumberList::Init()
{
    this->count = 0;
    for (int i = 0; i < 10; i++)
        this->numbers[i] = 0;
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