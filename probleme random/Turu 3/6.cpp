#include<iostream>
#include<string>

using namespace std;

class Complex
{
private:
	double real, imag;
	char* nume;

public:
	double GetReal()
	{
		return real;
	}
	double GetImag()
	{
		return imag;
	}
	char* GetNume()
	{
		return nume;
	}
	void SetReal(double val)
	{
		real = val;
	}
	void SetImag(double val)
	{
		imag = val;
	}
	void SetNume(const char* x)
	{
		nume = (char*)malloc(sizeof(char) * strlen(x));
		strcpy_s(nume, strlen(x), x);
	}
	Complex()
	{
		real = imag = 1.0;
		nume = (char*)malloc(sizeof(char) * 15);

	}
	void ShowInfo()
	{
		cout << real << ' ' << imag << '\n';
	}
	int GetLen()
	{
		return strlen(nume);
	}
	Complex(Complex& pct)
	{
		real = pct.real;
		imag = pct.imag;
		nume = (char*)malloc(sizeof(char) * pct.GetLen());
	}
	Complex operator+(Complex x)
	{
		Complex res;
		res.SetReal(this->GetReal() + x.GetReal());
		res.SetImag(this->GetImag() + x.GetImag());
		return res;
	}
	Complex operator-(Complex x)
	{
		Complex res;
		res.SetReal(this->GetReal() - x.GetReal());
		res.SetImag(this->GetImag() - x.GetImag());
		return res;
	}
	Complex operator*(Complex x)
	{
		Complex res;
		res.SetReal(this->GetReal() * x.GetReal() + this->GetImag() * x.GetImag());
		res.SetImag(this->GetReal() * x.GetImag() + this->GetImag() * x.GetReal());
		return res;
	}

};

int main()
{
	Complex a, b;
	a.SetReal(2);
	a.SetImag(4);
	b.SetReal(3);
	b.SetImag(1);
	(a + b).ShowInfo();
}