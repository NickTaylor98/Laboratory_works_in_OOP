// Lab06_OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Matrix.h"
int main()
{
	setlocale(LC_ALL, "");
	Matrix* Matr = new Matrix(2, 2);
	Matrix* Matr1 = new Matrix(2, 2);
	(*Matr).setMatrix();
	(*Matr1).setMatrix();
	if (*Matr > *Matr1) cout << "Первая матрица по модулю больше, чем вторая" << endl;
	else cout << "Вторая матрица по модулю больше, чем первая" << endl;
	system("pause");
    return EXIT_SUCCESS;
}

