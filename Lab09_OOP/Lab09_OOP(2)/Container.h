#pragma once
#include "stdafx.h"
#include <algorithm>
#include <map>
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
	list<double> getCont() const;
	void Merge(Container, map<int, double>);
	double* Find(double, double, int& size);
};