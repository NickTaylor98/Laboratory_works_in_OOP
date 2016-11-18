#include "stdafx.h"
#include "Container.h"
Container::Container() {}
Container::Container(ui size) { for (ui i(0); i < size; i++) arr.push(Candy()); }
Container::Container(initializer_list<Candy> lst) { for (auto i : lst) arr.push(i); }
void Container::Insert(Candy elem, ...)
{
	auto pelem = &elem;
	ui i(0);
	while (pelem[i] != Candy()) arr.push(pelem[i++]);
}
void Container::Delete(ui size = 1) { for (ui i(0); i < size; i++) arr.pop(); }
void Container::Change(ui size_of_del, Candy arr[], ui size_of_new)
{
	size_of_del < this->arr.size() ? size_of_del : size_of_del = this->arr.size();
	Delete(size_of_del);
	for (ui i(0); i < size_of_new; i++) Insert(arr[i], Candy());
}
void Container::Print()
{
	unique_ptr<queue<Candy>> parr (new queue<Candy>(arr));
	for (ui i(arr.size()); i > 0; i--)
	{
		(*parr).front().toConsole();
		(*parr).pop();
	}
	printf("\n");
}
Candy* Container::GetArray()
{
	auto rc = new Candy[arr.size()];
	unique_ptr<queue<Candy>> help (new queue<Candy>(this->arr));
	for (ui i(arr.size()), j(0); i > 0; i--, j++) { rc[j] = arr.front(); arr.pop(); }
	return rc;
}
ui Container::GetSize() const { return arr.size(); }