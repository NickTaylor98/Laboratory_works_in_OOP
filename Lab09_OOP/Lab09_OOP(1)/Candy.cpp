#include "stdafx.h"
#include "Candy.h"
Candy::Filling::Filling() { id = 0; }
Candy::Filling::Filling(Filling& fill) { id = fill.id; }
Candy::~Candy() { Percentege_of_sugar = 0; Taste.setId(0); Weight = 0; }
void Candy::toConsole()
{
	printf("%s\n", typeid(this).name());
	Taste.Print(*this);
	printf("---------------------------------\n");
}
bool Candy::operator==(const Candy & candy)
{
	bool rc = false;
	if (this->Percentege_of_sugar == candy.Percentege_of_sugar && this->Taste.getId() == candy.Taste.getId() && this->Weight == candy.Weight) rc = true;
	return rc;
}
Candy::Candy() { Percentege_of_sugar = 0; Taste.setId(0); Weight = 0; }
ui Candy::Filling::getId() const { return id; }
void Candy::Filling::setId(ui id) { this->id = (id > _countof(Array_of_tastes) ? _countof(Array_of_tastes) - 1 : id - 1); }
bool Candy::TasteGood() { bool rc = Taste.getId() < 6; return rc; }
string Candy::Filling::getTaste() const { return Array_of_tastes[id]; }
void Candy::Filling::Print(Candy candy) { candy.Print(); printf("Начинка конфеты: %s\n", getTaste()); }
Candy::Candy(ui perc, ui id, ui weight) { setPerc(perc); Taste.setId(id); Weight = weight; }
ui Candy::getPerc() const { return Percentege_of_sugar; }
void Candy::setWeight(ui weight) { Weight = weight; }
ui Candy::getWeight() const { return Weight; }
void Candy::setPerc(ui perc) { Percentege_of_sugar = perc < 100 ? perc : 100; }
void Candy::Print() { printf("Процентное содержание сахара: %u%%\n", Candy::Percentege_of_sugar); }
Candy::Candy(const Candy &candy)
{
	this->Percentege_of_sugar = candy.Percentege_of_sugar;
	this->Taste.setId(candy.Taste.getId());
	this->Weight = candy.Weight;
}
bool Candy::operator!=(const Candy & candy)
{
	bool rc = false;
	if (this->Percentege_of_sugar != candy.Percentege_of_sugar
		|| this->Taste.getId() != candy.Taste.getId()
		|| this->Weight != candy.Weight) rc = true;
	return rc;
}
Candy Candy::operator=(const Candy & candy)
{
	Candy* rc = new Candy(candy);
	return *rc;
}
ostream& operator<<(ostream& out, const Candy candy)
{
	out << "Процентное содержание сахара: " << candy.getPerc() << "%\nМасса конфеты: " << candy.getWeight() << "г\n";
	return out;
}
istream& operator >> (istream& in, Candy& candy)
{
	printf("Введите содержание сахара в конфете (в процентах): ");
	in >> candy.Percentege_of_sugar;
	if (candy.Percentege_of_sugar > 100) candy.Percentege_of_sugar = 100;
	printf("Введите массу конфеты: ");
	in >> candy.Weight;
	if (candy.Weight > 10000) candy.Weight = 10000;
	return in;
}