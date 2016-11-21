// Lab07_OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Matrix.h"
#include "..\..\Lab02_OOP\Lab02_OOP\Class.h"
int main()
{
	setlocale(LC_ALL, "");
	Matrix<int>* matr = new Matrix<int>(2,2);
	Matrix<int>* matr0 = new Matrix<int>(2, 2);
	(*matr0).getElement(1, 1) = -2;
	cout << Number_of_elements(*matr0, -1) << endl;
	Matrix<double>* matr1 = new Matrix<double>(2,2);
	Matrix<Student>* matr2 = new Matrix<Student>(3,3);
	*matr = *matr + *matr0;
	Matrix<Student>* matr3 = new Matrix<Student>(3, 3);
	(*matr3).getElement(0, 0) = { "Mushuk", "Artur", "Nikolaevich" };
	*matr3 == *matr3 + *matr2;
	Student* stud = new Student("Kok", "fg", "ergr", Data(12,02,2013) ,Adress(),"", "", 2, 4, true);
	(*matr3).getElement(1, 2).setBirthday(Data(12,01,2015));
	for (int i(0); i < (*matr3).getStroke(); i++)
		for (int j(0); j < (*matr3).getColumn(); j++)
			cout << (*matr3).getElement(i, j).Age(matr3->getElement(i, j).getBirthday()) << " ";
	cout << Number_of_elements(*matr3,*stud) << endl;
 	delete matr, matr0, matr1, matr3, matr2, stud;
	system("pause");
    return 0;
}