#pragma once
#include <string>

using std::string;

class Student
{
private:
	string studentName;
    float mathGrade, englishGrade, historyGrade;
public:
	//NAME FUNCTIONS
	void SetName(string name);//set the name of the student
	string GetName();//get the name of the student
	
	//MATH GRADE FUNCTIONS
	void SetMathGrade(float grade);//set the math grade
	float GetMathGrade();//get the math grade
	
	//ENGLISH GRADE FUNCTIONS
	void SetEnglishGrade(float grade);//set the english grade
	float GetEnglishGrade();//get the english grade
	
	//HISTORY GRADE FUNCTIONS
	void SetHistoryGrade(float grade);//set the history grade
	float GetHistoryGrade();//get the history grade
	
	//AVERAGE FUNCTION
	float GetAverageGrade();//calculate the average between math,english and history grades
};