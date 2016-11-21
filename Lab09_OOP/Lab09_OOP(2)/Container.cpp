#include "stdafx.h"
#include "Container.h"
void Container::Sort(){ cont.sort(); }
Container::Container(initializer_list <double> lst) { for (auto i : lst) cont.push_back(i); }
void Container::Insert(double numb, ...) { int i(0); auto pnumb = &numb; while (pnumb[i] != DBL_MAX) cont.push_back(pnumb[i++]); }
void Container::Print() { for (auto i : cont) printf("%g ", i); puts("\n"); }
double* Container::Find(double MinLimit, double MaxLimit, int& size)
{
	auto beg = cont.begin();
	int* count = new int(0);
	double* rc = new double[cont.size()];
	while (beg != cont.end())
	{
		auto it = std::find_if(beg, cont.end(), [MinLimit, MaxLimit](double a) -> bool {return (a > MinLimit && a < MaxLimit); });
		if (it != cont.end()) rc[(*count)++] = *it;
		beg != it ? beg = it : beg++;
	}
	size = *count;
	delete count;
	return rc;
}
int Container::getSize() const { return cont.size(); }
list<double> Container::getCont() const { return this->cont; }
void Container::Merge(Container _cont, map<int, double> cont_1)
{
	cont.merge(_cont.getCont());
	for (auto i : cont_1) this->Insert(i.second, DBL_MAX);
}
