#pragma once
#include "stdafx.h"
class Container
{
	queue <double> arr;
public:
	Container();
	Container(ui);
	Container(initializer_list<double> l);
	void Insert(double, ...);
	void Delete(ui size);
	void Change(ui size, double arr[], ui size_of_new);
	void Print();
	double* GetArray();
	ui GetSize() const;
//	void Print_with_Iterators(); невозможно, т.к. не существует итераторов на очередь
};