#pragma once
class Number
{
	char* number;
	int currentBase;
	
public:
	Number(const Number& n);
	Number(int nr);
	Number(const char* value, int base);
	~Number();

	char& operator[](int index);
	friend Number operator+(Number& a, Number& b);
	friend Number operator-(const Number& a, const Number& b);
	bool operator>(const Number& x);
	bool operator>=(const Number& x);
	bool operator==(const Number& x);
	bool operator!=(const Number& x);
	bool operator<(const Number& x);
	bool operator<=(const Number& x);
	void operator=(const Number& x);
	void operator=(const int num);
	void operator=(const char*);
	void operator--(int);
	void operator--();
	Number operator|(Number& x);
	
	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();
};