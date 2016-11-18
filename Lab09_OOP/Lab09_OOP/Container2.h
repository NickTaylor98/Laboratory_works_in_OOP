#pragma once
#include "stdafx.h"
class Container_Second
{
	unordered_map <ui, double> arr;
public:
	Container_Second();
	Container_Second(initializer_list<pair<ui, double>> lst);
	void Insert(double, ...);
	void Print();
	double* GetArray();
	ui getSize() const;
	//	void Print_with_Iterators(); невозможно, т.к. не существует итераторов на очередь
};