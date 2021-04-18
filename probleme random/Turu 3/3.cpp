#include<iostream>
#include<stdlib.h>
using namespace std;
class Student
{
private:
	char nume[30], prenume[30];
	int note[7];
	double medie;
	int grupa;
public:
	Student()
	{
		cin.get();
		cin.get(nume, 30);
		cin.get();
		cin.get(prenume, 30);
		cin.get();
		for (int i = 0; i < 7; i++)
			cin >> note[i];
		this->CalcMedie();
		cin >> grupa;
	}
	~Student()
	{
		cout << "pa pa\n\a";
	}
	void ShowInfo()
	{
		cout << nume << ' ' << prenume << ' ' << grupa << ' ' << medie << '\n';
	}
	void CalcMedie()
	{
		int sum = 0;
		for (int i = 0; i < 7; i++)
			sum += note[i];
		medie = sum / 7;
	}
	double GetMedie()
	{
		return medie;
	}
};
int main()
{
	int n;
	cin >> n;

	Student* s = new Student[n];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i].GetMedie() > s[j].GetMedie())
				swap(s[i], s[j]);
	for (int i = n - 1; i >= 0; i--)
		s[i].ShowInfo();
	delete[] s;
	return 0;
}