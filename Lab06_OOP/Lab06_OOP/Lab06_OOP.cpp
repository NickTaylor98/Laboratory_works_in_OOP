// Lab06_OOP.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	if (*Matr > *Matr1) cout << "������ ������� �� ������ ������, ��� ������" << endl;
	else cout << "������ ������� �� ������ ������, ��� ������" << endl;
	system("pause");
    return EXIT_SUCCESS;
}

