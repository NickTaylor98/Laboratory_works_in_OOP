#pragma once
using ui = unsigned int;
using namespace std;
//����� - ������. ������������� ����������� ���������
//��������: +-�������� ������; () - ������ �� ������� V(i) �
//�������� ������; > -��������� ������ �� ������; = = -
//����������� �������.
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
	Matrix operator+(Matrix); //�������� ������
	Matrix operator==(const Matrix&); // ����������� ������
	vector<int>& operator()(ui i); // ������ �� ������� � ������
	bool operator>(Matrix matr1); // ��������� �� ������������
};