#include "stdafx.h"
#include "Container.h"
Container::Container() {}
Container::Container(ui size) { for (ui i(0); i < size; i++) arr.push(0.0); }
Container::Container(initializer_list<double> lst) { for (auto i : lst) arr.push(i); }
void Container::Insert(double elem, ...) 
{
	double* pelem = &elem;
	ui i(0); 
	while (pelem[i] != DBL_MAX) arr.push(pelem[i++]); 
}
void Container::Delete(ui size = 1) { for (ui i(0); i < size; i++) arr.pop(); }
void Container::Change(ui size_of_del, double arr[], ui size_of_new)
{
	size_of_del < this->arr.size() ? size_of_del : size_of_del = this->arr.size();
	Delete(size_of_del);
	for (ui i(0); i < size_of_new; i++) Insert(arr[i], DBL_MAX);
}
void Container::Print() 
{ 
	auto parr = new queue<double>(arr);
	for (ui i(arr.size()); i > 0; i--)
	{
		cout << (*parr).front() << ends; 
		(*parr).pop();
	}
	cout << endl;
	delete parr;
}

double * Container::GetArray()
{
	auto rc = new double[arr.size()];
	auto help = new queue<double>(this->arr);
	for (ui i(arr.size()), j(0); i > 0; i--, j++) { rc[j] = arr.front(); arr.pop(); }
	delete help;
	return rc;
}
ui Container::GetSize() const {return arr.size();}
