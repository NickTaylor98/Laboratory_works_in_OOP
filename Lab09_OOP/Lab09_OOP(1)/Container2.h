#pragma once
#include "stdafx.h"
#include "Candy.h"
class Container_Second
{
	unordered_map <ui, Candy> arr;
public:
	Container_Second();
	Container_Second(initializer_list<pair<ui, Candy>> lst);
	void Insert(Candy, ...);
	void Print();
	Candy* GetArray();
	ui getSize() const;
	//	void Print_with_Iterators(); невозможно, т.к. не существует итераторов на очередь
};