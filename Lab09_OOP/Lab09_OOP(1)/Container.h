#pragma once
#include "stdafx.h"
#include "Candy.h"
class Container
{
	queue<Candy> arr;
public:
	Container();
	Container(ui);
	Container(initializer_list<Candy> l);
	void Insert(Candy, ...);
	void Delete(ui size);
	void Change(ui size, Candy arr[], ui size_of_new);
	void Print();
	Candy* GetArray();
	ui GetSize() const;
	//	void Print_with_Iterators(); невозможно, т.к. не существует итераторов на очередь
};