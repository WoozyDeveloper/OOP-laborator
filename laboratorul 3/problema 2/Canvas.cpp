#include "Canvas.h"

#include <iostream>
#include <cmath>

#define EMPTY_CELL '_'
#define PI 3.1415
#define STEP 0.1

using std::cout;

inline double min(double a, double b)
{
	return a < b ? a : b;
}

inline double max(double a, double b)
{
	return a > b ? a : b;
}

double distance(int x1, int y1, int x2, int y2)
{
	return (double)sqrt(pow(max(x1, x2) - min(x1, x2), 2) + pow(max(y1, y2) - min(y1, y2), 2));
}

void Canvas::SetPoint(int x, int y, char ch)
{
	this->myCanvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++)
	{
		this->myCanvas[x][y] = ch;
		slope_error_new += m_new;
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}

/*void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	double str_line = distance(x1, y1, x2, y2);
	for (double i = x1; i <= x2; i += STEP)
		for (double j = y1; j <= y2; j += STEP)
			if (distance(x1, y1, i, j) + distance(x2, y2, i, j) == str_line)
				this->myCanvas[(int)i][(int)j] = ch;
}*/

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{ 
	for (int i = x - ray; i <= x + ray; i++)
		for (int j = y - ray; j <= y + ray; j++)
			if (i >= 0 && i < this->height && j >= 0 && j < this->width && (int)distance(i, j, x, y) == ray)
				this->myCanvas[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int second_ray = ray; second_ray >= 0; --second_ray)
		DrawCircle(x, y, second_ray, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x - 1 >= 0 && x - 1 < this->height && y - 1 >= 0 && y - 1 < this->width)
		this->myCanvas[x - 1][y - 1] = ch;
}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			this->myCanvas[i][j] = EMPTY_CELL;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top - 1; i <= bottom; i++)
		for (int j = left - 1; j <= right; j++)
			if(i >= 0 && i < this->height &&
			   j >= 0 && j < this->width)
			this->myCanvas[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left - 1; i < right; i++)
		this->myCanvas[top - 1][i] = this->myCanvas[bottom - 1][i] = ch;
	for (int i = top - 1; i < bottom; i++)
		this->myCanvas[i][left - 1] = this->myCanvas[i][right - 1] = ch;
}

Canvas::Canvas(int w, int h)
{
	this->width = w;
	this->height = h;
	Clear();
}

void Canvas::Print()
{
	for (int i = 0; i < this->height; ++i)
	{
		for (int j = 0; j < this->width; ++j)
			cout << this->myCanvas[i][j] << ' ';
		cout << '\n';
	}
}