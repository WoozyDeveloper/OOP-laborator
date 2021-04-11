#include <iostream>
#include <stdlib.h>

using namespace std;

class Matrix {
	//atribute
	int** matrix;
	int dim1, dim2;
	//declararea metodei de afisare a unui element
	int returnElement(int row, int column);
public:
	//constructor explicit cu parametri – recomandat a folosi o metoda diferita a citi valorile
	Matrix(int dim1, int dim2) {
		this->dim1 = dim1;
		this->dim2 = dim2;
		matrix = new int* [dim1];
		for (int i = 0; i < dim1; ++i)
			matrix[i] = new int[dim2];
		//variabile locale
		int i, j;
		cout << "\nIntroduceti elementele matricii: ";
		for (i = 0; i < dim1; i++) {
			for (j = 0; j < dim2; j++) {
				cout << "\nmatrix[" << i << "][" << j << "] = ";
				cin >> matrix[i][j];
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < dim1; ++i)
			delete[] matrix[i];
		delete[] matrix;
	}

	void subPrinc()
	{
		if (dim1 != dim2)
			cout << "Nu e patratica\n";
		else {
			for (int i = 0; i < dim1; i++)
				for (int j = 0; j < i; j++)
					cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}

	void functieCiudata()
	{
		int** dubios = new int* [dim1];
		for (int i = 0; i < dim1; ++i)
			dubios[i] = new int[dim2];
		int nr;
		for (int i = 0; i < dim1; i++)
			for (int j = 0; j < dim2; j++)
			{
				cin >> nr;
				dubios[i][j] = 0;
				if (nr < matrix[i][j])
					dubios[i][j] = 1;
			}
		cout << "\nMatricea formata..?\n";
		for (int i = 0; i < dim1; i++)
		{
			for (int j = 0; j < dim2; j++)
				cout << dubios[i][j] << ' ';
			cout << endl;
		}

		for (int i = 0; i < dim1; ++i)
			delete[] dubios[i];
		delete[] dubios;
	}

	void diagSec()
	{
		if (dim1 != dim2)
			cout << "Nu e patratica\n";
		else {
			for (int i = 0; i < dim1; i++)
				cout << matrix[i][dim2 - i - 1] << ' ';
		}
	}
	//metoda de afisare a matricii din clasa; implementare in cadrul clasei
	void displayMatrix() {
		//variabile locale
		int i, j;
		cout << "\nElementele matricii: ";
		for (i = 0; i < dim1; i++) {
			cout << "\n";
			for (j = 0; j < dim2; j++) {
				//apelul metodei private care returneaza valoarea unui element din matrice
				cout << returnElement(i, j) << " ";
			}
		}
		cout << endl;
		diagSec();
		cout << endl;
		subPrinc();
		cout << endl;
		functieCiudata();
	}
	//declararea metodei de afisare a elementelor unei coloane
	void displayColumn(int col);
};

//implementarea externa a metodelor (publice sau private) declarate in clasa
void Matrix::displayColumn(int col) {
	if (col < 0 || col >= dim2) {
		cout << "\nColoana cu numarul " << col << " nu exista in matricea din clasa!\n";
	}
	else {
		cout << "\nElementele coloanei " << col << ": ";
		for (int i = 0; i < dim1; i++) {
			cout << returnElement(i, col) << " ";
		}
	}
}

int Matrix::returnElement(int row, int column) {
	return matrix[row][column];
}

int main() {
	int dim1, dim2;
	cout << "\nIntroduceti dimensiunile 1 si 2 ale matricii: (<=10):\n";
	cin >> dim1;
	cin >> dim2;
	Matrix m1(dim1, dim2);
	m1.displayMatrix();
	
}