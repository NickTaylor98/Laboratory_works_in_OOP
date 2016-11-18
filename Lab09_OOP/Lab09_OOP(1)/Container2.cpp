#include "stdafx.h"
#include "Container2.h"
Container_Second::Container_Second() {}
Container_Second::Container_Second(initializer_list<pair<ui, Candy>> lst) { for (auto i : lst) arr.insert(i); }
void Container_Second::Insert(Candy num, ...)
{
	ui i(0);
	auto pnum = &num;
	while (pnum[i] != Candy()) arr.insert({ i++, *pnum });
}
Candy* Container_Second::GetArray()
{
	auto rc = new Candy[arr.size()];
	ui j(0);
	for (auto i : arr) rc[j++] = i.second;
	return rc;
}
ui Container_Second::getSize() const
{
	return arr.size();
}
void Container_Second::Print()
{
	for (auto i : arr) printf("Процентное содержание сахара: %u%%\nМасса конфеты: %u\n", i.second.getPerc(),i.second.getWeight());
	printf("\n");
}

