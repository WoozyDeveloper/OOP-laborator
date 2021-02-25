#include "Student.h"

#include <cstring>

using std::string;

void Student::SetName(string name)
{
	this->studentName = name;
}

string Student::GetName()
{
	return this->studentName;
}

void Student::SetMathGrade(float grade)
{
	this->mathGrade = grade;
}

float Student::GetMathGrade()
{
	return this->mathGrade;
}

void Student::SetEnglishGrade(float grade)
{
	this->englishGrade = grade;
}

float Student::GetEnglishGrade()
{
	return this->englishGrade;
}

void Student::SetHistoryGrade(float grade)
{
	this->historyGrade = grade;
}

float Student::GetHistoryGrade()
{
	return this->historyGrade;
}

float Student::GetAverageGrade()
{
	return (this->mathGrade + this->englishGrade + this->historyGrade) / 3.0f;
}