#pragma once
#include "Student.h"
#include "GlobalFunctions.h"

#include <iostream>

using std::cout;

int main()
{
	Student firstStudent, secondStudent;

	//CREATE THE FIRST STUDENT
	firstStudent.SetName("Robert Baltog");
	firstStudent.SetMathGrade(9);
	firstStudent.SetEnglishGrade(10);
	firstStudent.SetHistoryGrade(2);

	//PRINT INFO FOR THE FIRST STUDENT
	cout << "First student info:\n\tNAME: " << firstStudent.GetName() << "\n\tMATH GRADE: " <<
		firstStudent.GetMathGrade() << "\n\tENGLISH GRADE: " << firstStudent.GetEnglishGrade() << 
		"\n\tHISTORY GRADE: " << firstStudent.GetHistoryGrade() << "\n\tAVERAGE GRADE: " << 
		firstStudent.GetAverageGrade();

	//CREATE THE SECOND STUDENT
	secondStudent.SetName("Baltag Simona");
	secondStudent.SetMathGrade(9);
	secondStudent.SetEnglishGrade(10);
	secondStudent.SetHistoryGrade(2.3);

	//PRINT INFO FOR THE SECOND STUDENT
	cout << "\n\nSecond student info:\n\tNAME: " << secondStudent.GetName() << "\n\tMATH GRADE: " <<
		secondStudent.GetMathGrade() << "\n\tENGLISH GRADE: " << secondStudent.GetEnglishGrade() << 
		"\n\tHISTORY GRADE: " << secondStudent.GetHistoryGrade() << "\n\tAVERAGE GRADE: " << 
		secondStudent.GetAverageGrade() << "\n\n";


	cout << nameComparison(firstStudent, secondStudent) << ' ';
	cout << mathGradeComparison(firstStudent, secondStudent) << ' ';
	cout << englishGradeComparison(firstStudent, secondStudent) << ' ';
	cout << historyGradeComparison(firstStudent, secondStudent) << '\n';

	firstStudent.GetAverageGrade() > secondStudent.GetAverageGrade() ? cout << firstStudent.GetName() << " has better grades." : cout << secondStudent.GetName() << " has better grades.";
	return 0;
}