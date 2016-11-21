#pragma once
using ui = unsigned int;
using namespace std;
//Класс - Марица. Дополнительно перегрузить следующие
//операции: +-сложение матриц; () - доступ по индексу V(i) к
//заданной строке; > -сравнение матриц по модулю; = = -
//копирование матрицы.
#include <iostream>
#include <vector>
class Matrix
{
	ui Stroke;
	ui Column;
	vector<vector<int>> matr;
public:
	Matrix();
	Matrix(ui col,ui str);
	Matrix(const Matrix&);
	void setColumn(ui);
	void setStroke(ui);
	void setMatrix();
	int &getElement(ui i, ui j);
	ui getColumn() const;
	ui getStroke() const;
	ui Absolute();
	Matrix operator+(Matrix); //сложение матриц
	Matrix operator==(const Matrix&); // копирование матриц
	vector<int>& operator()(ui i); // доступ по индексу к строке
	bool operator>(Matrix matr1); // сравнение по определителю
};