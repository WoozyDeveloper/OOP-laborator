#define _CRT_SECURE_NO_WARNINGS

#include "Math.h"

#include <stdarg.h>
#include <string>
#include <cstdlib>

int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
int Math::Mul(int x , int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...)// sums up a list of integers
{
	int result = 0;
	va_list params;
	va_start(params, count);
	for (int i = 0; i < count; i++)
		result += va_arg(params, int);
	va_end(params);
	return result;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
char* Math::Add(const char* a, const char* b)
{
	char* result = new char[10];
	for (int i = 0; i < 10; i++)
		result[i] = ' ';
	int m = 0;
	char first[20], second[20];
	strcpy(first, a); strcpy(second, b);
	_strrev(first); 
	_strrev(second);
	int i;
	for (i = 0; i < min(strlen(first),strlen(second)); i++)
	{
		int sum = (int)first[i] - '0' + (int)second[i] - '0';
		if (sum + m >= 10)
			result[i] = (char)((sum + m) % 10 + '0'), m = sum / 10;
		else
			result[i] = (char)sum + m + '0';
	}
	for (; i < max(strlen(first), strlen(second)); i++)
	{
		if (first[i] >= '0' && first[i] <= '9')
		{
			result[i] = first[i] - '0' + m + '0';
			m = (first[i] - '0' + m) / 10;
		}
		if (second[i] >= '0' && second[i] <= '9')
		{
			result[i] = second[i] - '0' + m + '0';
			m = (second[i] - '0' + m) / 10;
		}
	}
	if (m > 0)
		result[i] = m + '0';
	result[i + 1] = '\0';
	_strrev(result);
	return result;
}

char* Math::Sub(const char* a, const char* b)
{
	char* result = new char[10];
	for (int i = 0; i < 10; i++)
		result[i] = ' ';
	int m = 0;
	char first[20], second[20];
	strcpy(first, a); strcpy(second, b);
	_strrev(first);
	_strrev(second);
	int i;
	for (i = 0; i < min(strlen(first), strlen(second)); i++)
	{
		int dif = (int)first[i] - '0' - (int)second[i] + '0';
		if (dif - m < 0)
		{
			result[i] = 10 + ((int)first[i] - '0') - m - ((int)second[i] - '0') + '0';
			m = 1;
		}
		else
			result[i] = (char)dif - m + '0';
	}
	for (; i < max(strlen(first), strlen(second)); i++)
	{
		if (first[i] >= '0' && first[i] <= '9')
		{
			int dif = (int)first[i] - '0';
			if (dif - m < 0)
			{
				result[i] = 10 + ((int)first[i] - '0') - m + '0';
				m = 1;
			}
			else
				result[i] = (char)dif - m + '0';
		}
		if (second[i] >= '0' && second[i] <= '9')
		{
			int dif = (int)second[i] - '0';
			if (dif - m < 0)
			{
				result[i] = 10 + ((int)second[i] - '0') - m + '0';
				m = 1;
			}
			else
				result[i] = (char)dif - m + '0';
		}
	}
	result[i + 1] = '\0';
	_strrev(result);
	return result;
}