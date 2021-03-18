#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>

#include "Number.h"

using namespace std;


int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int toDeci(char* str, int base)
{
    int len = strlen(str);
    int power = 1;
    int num = 0;
    int i;
    for (i = len - 1; i >= 0; i--)
    {

        if (val(str[i]) >= base)
        {
            printf("Invalid Number");
            return -1;
        }
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
    _strrev(res);

    return res;
}

Number Number::operator|(Number& x)
{
    char mem[20];
    strcpy(mem, this->number);
    delete[] this->number;
    this->number = new char[strlen(mem) + strlen(x.number) + 1];
    strcpy(this->number, mem);
    int biggerBase = max(this->currentBase, x.currentBase);
    if(x.currentBase!=biggerBase)
        x.SwitchBase(biggerBase);
    if (this->currentBase != biggerBase)
        this->SwitchBase(biggerBase);
    char result[50];
    strcpy(result, this->number);
    strcat(result, x.number);
    Number n(result, biggerBase);
    return n;
}

Number::Number(const Number& x)
{
    currentBase = x.currentBase;
    number = new char[20];
    memcpy(number, x.number, strlen(x.number) + 1);
}

Number::Number(const char* value, int base)
{
    number = new char[20];
    memcpy(number, value, strlen(value));
    number[strlen(value)] = '\0';
    currentBase = base;
}

Number::Number(int nr) {
    this->currentBase = 10;
    char str[100];
    _itoa(nr, str, 10);
    this->number = new char[20];
    strcpy(this->number, str);
}

char& Number::operator[](int index)
{
    return this->number[index];
}

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void Number::operator--()
{
    int dim = strlen(this->number);
    for (int i = 0; i < dim; i++)
        this->number[i] = this->number[i + 1];
    this->number[dim - 1] = '\0';
}

void Number::operator--(int) 
{
    number[strlen(this->number) - 1] = '\0';
}

void Number::operator=(const char* nr)
{
    delete[] number;

    number = new char[strlen(nr) + 1];
    strcpy(number, nr);

    SwitchBase(currentBase);
}

void Number::operator=(const int num)//num is in base 10
{
    delete[] this->number;
    char res[100];
    _itoa(num, res, this->currentBase);
    this->number = new char[strlen(res) + 1];
    strcpy(this->number, res);
}

Number operator+(Number& a, Number& b)
{
    char result[20];
    Number x(a.number, a.currentBase);
    Number y(b.number, b.currentBase);
    x.SwitchBase(10); 
    y.SwitchBase(10);
    int rez = atoi(x.number) + atoi(y.number);
    int biggerBase = max(x.currentBase, y.currentBase);
    sprintf(result, "%d", rez);
    Number res(result, 10);
    res.SwitchBase(biggerBase);
    return res;
}

bool Number::operator>(const Number& x)
{
    Number a(this->number, this->currentBase);
    Number b(x.number, x.currentBase);
    a.SwitchBase(10);
    b.SwitchBase(10);

    return strlen(this->number) > strlen(x.number) ? true : false;
    return strcmp(this->number,x.number)>0 ? true : false;
}

bool Number::operator>=(const Number& x)
{
    Number a(this->number, this->currentBase);
    Number b(x.number, x.currentBase);
    a.SwitchBase(10);
    b.SwitchBase(10);
    return strlen(this->number) >= strlen(x.number) ? true : false;
    return strcmp(this->number, x.number) >= 0 ? true : false;
}

bool Number::operator<(const Number& x)
{
    Number a(this->number, this->currentBase);
    Number b(x.number, x.currentBase);
    a.SwitchBase(10);
    b.SwitchBase(10);
    return strlen(this->number) < strlen(x.number) ? true : false;
    return strcmp(this->number, x.number) < 0 ? true : false;
}

bool Number::operator<=(const Number& x)
{
    Number a(this->number, this->currentBase);
    Number b(x.number, x.currentBase);
    a.SwitchBase(10);
    b.SwitchBase(10);
    return strlen(this->number) <= strlen(x.number) ? true : false;
    return strcmp(this->number, x.number) <= 0 ? true : false;
}

void Number::operator=(const Number& x)
{
    delete[] this->number;
    this->number = new char[strlen(x.number) + 1];
    strcpy(this->number, x.number);
    this->currentBase = x.currentBase;
}

bool Number::operator==(const Number& x)
{
    Number a(this->number, this->currentBase);
    Number b(x.number, x.currentBase);
    a.SwitchBase(10);
    b.SwitchBase(10);
    return strcmp(this->number, x.number) == 0 ? true : false;
}

bool Number::operator!=(const Number& x)
{
    Number a(this->number, this->currentBase);
    Number b(x.number, x.currentBase);
    a.SwitchBase(10);
    b.SwitchBase(10);
    return strcmp(this->number, x.number) != 0 ? true : false;
}

Number operator-(const Number& a, const Number& b)
{
    char result[20];
    Number x(a.number, a.currentBase);
    Number y(b.number, b.currentBase);
    x.SwitchBase(10); y.SwitchBase(10);
    int rez = atoi(x.number) - atoi(y.number);
    int biggerBase = max(x.currentBase, y.currentBase);
    sprintf(result, "%d", rez);
    Number res(result, 10);
    res.SwitchBase(biggerBase);
    return res;
}

Number::~Number()
{
	delete[] this->number;
}

void Number::SwitchBase(int newBase)
{
    int inputNum = toDeci(number, currentBase);
    char res[100];

    _itoa(inputNum, res, newBase);

    delete[] number;

    number = new char[strlen(res) + 1];
    strcpy(number, res);
    currentBase = newBase;
}

void Number::Print()
{
	cout << this->number << '\n';
}

int Number::GetDigitsCount()
{
	return strlen(this->number);
}

int Number::GetBase()
{
	return this->currentBase;
}