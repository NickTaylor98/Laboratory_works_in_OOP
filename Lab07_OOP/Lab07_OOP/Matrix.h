#pragma once
using ui = unsigned int;
using namespace std;
//Написать функцию-шаблон, которая подсчитывет
//количество элементов больших заданному в матрице
#include <iostream>
#include <vector>
#define LOOP for (ui i = 0; i < Stroke; i++) \
             for (ui j = 0; j < Column; j++)
template<typename T>
class Matrix
{
	ui Stroke;
	ui Column;
	vector<vector<T>> matr;
public:
	Matrix(){Stroke = Column = 0;}
	~Matrix(){Stroke = 0; Column = 0; for (ui i(0); i < Stroke; i++) matr[i].~vector(); matr.~vector();}
	Matrix(ui col, ui str)
	{
		matr.resize(Stroke = str);
		for (ui i(0); i < Stroke; i++)
		{
			matr[i].resize(Column = col);
			matr[i].assign(Column, T());
		}
	}
	Matrix(const Matrix& matr1)
	{
		matr.resize(Stroke = matr1.Stroke);
		for (ui i = 0; i < Stroke; i++)
		{
			matr[i].resize(Column = matr1.Column);
			for (ui j = 0; j < Column; j++) matr[i][j] = matr1.matr[i][j];
		}
	}
	void setMatrix() { LOOP{ cout << "Введите элемент матрицы [" << i << "][" << j << "] = "; cin >> matr[i][j]; } cout << endl; }
	void setColumn(ui col) { Column = col; }
	void setStroke(ui str) { Stroke = str; }
	T &getElement(ui i, ui j) { return matr[i][j]; }
	ui getColumn() const { return Column; }
	ui getStroke() const { return Stroke; }
	Matrix operator+(Matrix matr1)
	{
		Matrix* rc = new Matrix<T>();
		if (this->Column == matr1.getColumn() && this->Stroke == matr1.getStroke())
		{
			*rc = Matrix<T>(Column, Stroke);
			LOOP(*rc).getElement(i, j) = this->matr[i][j] + matr1.getElement(i, j);
		}
		else cout << "Матрицы не одинаковых размеров" << endl;
		return *rc;
	} //сложение матриц
	Matrix operator==(const Matrix& matr) { return *(this) = Matrix(matr); }
	vector<T>& operator()(ui i) { return this->matr[(i < Stroke) ? i : 0]; }// доступ по индексу к строке
};
template<class T>
ui Number_of_elements(Matrix<T>& matr, const T& elem)
{
	ui rc(0);
	for(ui i(0); i<matr.getStroke(); i++)
		for (ui j(0); j<matr.getColumn(); j++) 
			if (matr.getElement(i,j) > elem) rc++;
	return rc;
}