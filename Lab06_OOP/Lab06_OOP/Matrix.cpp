#include "stdafx.h"
#include "Matrix.h"
#define LOOP for (ui i = 0; i < Stroke; i++) \
             for (ui j = 0; j < Column; j++)
Matrix::Matrix() { Stroke = Column = 0;}
Matrix::Matrix(ui col, ui str) 
{ 
	matr.resize(Stroke = str);
	for (ui i(0); i < Stroke; i++)
	{
		matr[i].resize(Column = col);
		matr[i].assign(Column, 0); 
	} 
} //assign((Column = col), 0)
Matrix::Matrix(const Matrix& matr1)
{
	matr.resize(Stroke = matr1.Stroke);
	for (ui i = 0; i < Stroke; i++) 
	{
		matr[i].resize(Column = matr1.Column);
		for (ui j = 0; j < Column; j++) matr[i][j] = matr1.matr[i][j]; 
	}
}
void Matrix::setMatrix() { LOOP{ cout << "Введите элемент матрицы [" << i << "][" << j << "] = "; cin >> matr[i][j]; } cout << endl; }
int &Matrix::getElement(ui i, ui j){ return matr[i][j];}
Matrix Matrix::operator+(Matrix matr1)
{
	Matrix* rc = new Matrix();
	if (this->Column == matr1.getColumn() && this->Stroke == matr1.getStroke())
	{
		*rc = Matrix(Column, Stroke);
		LOOP (*rc).getElement(i, j) = this->matr[i][j] + matr1.getElement(i,j);
	}
	else cout << "Матрицы не одинаковых размеров" << endl;
	return *rc;
}
void Matrix::setColumn(ui col) { Column = col; }
void Matrix::setStroke(ui str) { Stroke = str; }
ui Matrix::getColumn() const { return Column; }
ui Matrix::getStroke() const { return Stroke; }
Matrix Matrix::operator==(const Matrix& matr) { return *(this) = Matrix(matr); }
vector<int>& Matrix::operator()(ui i) { return this->matr[(i < Stroke)? i : 0];}
ui Matrix::Absolute()
{
	int rc(0);
	LOOP rc += matr[i][j];
	return abs(rc);
}
bool Matrix::operator>(Matrix matr1) { return this->Absolute() > matr1.Absolute(); }