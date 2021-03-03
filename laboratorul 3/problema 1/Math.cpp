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
char* Math::Add(const char* a, const char* b)
{
	char* result = (char*)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
	strcpy(result, a);
	strcat(result, b);
	result[strlen(a) + strlen(b)] = '\0';
	return result;
}