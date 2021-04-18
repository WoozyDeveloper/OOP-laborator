#include<iostream>
#include<stdlib.h>
using namespace std;
class Student
{
private:
	char nume[30], prenume[30];
	int nrnote;
	int* note;
	double medie;
public:
	Student()
	{
		cin.get();
		cin.get(nume, 30);
		cin.get();
		cin.get(prenume, 30);
		cin.get();
		cin >> nrnote;
		note = (int*)malloc(sizeof(int) * nrnote);
		for (int i = 0; i < nrnote; i++)
			cin >> note[i];
		CalcMedie();
	}

	bool restantasausal()
	{
		for (int i = 0; i < nrnote; i++)
			if (note[i] < 5)
				return true;
		return false;
	}
	void CalcMedie()
	{
		int sum = 0;
		for (int i = 0; i < nrnote; i++)
			sum += note[i];
		medie = (double)sum / nrnote;
	}

	void PrintName()
	{
		cout << nume << ' ' << prenume;
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
	for (int i = 0; i < n; i++)
		if (s[i].restantasausal())
		{
			s[i].PrintName();
			cout << '\n';
		}
	cout << "\n---------------------------------------\n";
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i].GetMedie() > s[j].GetMedie())
				swap(s[i], s[j]);
	for (int i = n - 1; i >= n - 3; i--)
	{
		s[i].PrintName();
		cout << '\n';
	}
	delete[] s;
	return 0;
}
