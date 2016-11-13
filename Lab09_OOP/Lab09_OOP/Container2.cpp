#include "stdafx.h"
#include "Container2.h"
Container_Second::Container_Second() {}
Container_Second::Container_Second(initializer_list<pair<double, ui>> lst) { for (auto i : lst) arr.insert(i); }
void Container_Second::Insert(double num, ...)
{
	ui i(0);
	auto pnum = &num;
	while (pnum[i] != DBL_MAX) arr.insert({ *pnum,i++ });
}
double* Container_Second::GetArray()
{
	auto rc = new double[arr.size()];
	ui j(0);
	for (auto i : arr) rc[j++] = i.first;
	return rc;
}
ui Container_Second::getSize() const
{
	return arr.size();
}
void Container_Second::Print()
{
	for (auto i : arr) cout << i.first << " ";
	cout << endl;
}

