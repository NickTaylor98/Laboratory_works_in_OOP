#pragma once
#include "stdafx.h"
#include <algorithm>
class Container
{
	list<double> cont;
public:
	Container() = default;
	Container(initializer_list<double>);
	void Insert(double, ...);
	void Sort();
	void Print();
	int getSize() const;
	double* Find(double, double, int& size);
};