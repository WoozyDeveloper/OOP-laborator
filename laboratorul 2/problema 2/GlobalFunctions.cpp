#pragma once
#include "Student.h"
#include "GlobalFunctions.h"

#include <string>

inline bool between(float grade)
{
	return grade >= 1 && grade <= 10 ? true : false;
}

int nameComparison(Student& s1, Student& s2)
{
	if (s1.GetName() > s2.GetName())
		return 1;
	if (s1.GetName() == s2.GetName())
		return 0;
	return -1;
}

int mathGradeComparison(Student& s1, Student& s2)
{
	if (between(s1.GetMathGrade()) && between(s2.GetMathGrade()))
	{
		if (s1.GetMathGrade() == s2.GetMathGrade())
			return 0;
		return s1.GetMathGrade() > s2.GetMathGrade() ? 1 : -1;
	}
}

int englishGradeComparison(Student& s1, Student& s2)
{
	if (between(s1.GetEnglishGrade()) && between(s2.GetEnglishGrade()))
	{
		if (s1.GetEnglishGrade() == s2.GetEnglishGrade())
			return 0;
		return s1.GetEnglishGrade() > s2.GetEnglishGrade() ? 1 : -1;
	}
}

int historyGradeComparison(Student& s1, Student& s2)
{
	if (between(s1.GetHistoryGrade()) && between(s2.GetHistoryGrade()))
	{
		if (s1.GetHistoryGrade() == s2.GetHistoryGrade())
			return 0;
		return s1.GetHistoryGrade() > s2.GetHistoryGrade() ? 1 : -1;
	}
}

int averageComparison(Student& s1, Student& s2)
{
	if (s1.GetAverageGrade() == s2.GetAverageGrade())
		return 0;
	return s1.GetAverageGrade() > s2.GetAverageGrade() ? 1 : -1;
}