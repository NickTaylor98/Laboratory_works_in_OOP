#include "stdafx.h"
Candy::Filling::Filling() { id = 0; }
Candy::Filling::Filling(Filling& fill) { id = fill.id; }
Candy::~Candy() { Percentege_of_sugar = 0; Taste.setId(0); Weight = 0; }
void Candy::toConsole()
{
	cout << typeid(this).name() << endl;
	Taste.Print(*this);
	cout << "---------------------------------" << endl;
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
void Candy::Filling::Print(Candy candy) { candy.Print(); cout << "Начинка конфеты: " << getTaste() << endl; }
Candy::Candy(ui perc, ui id, ui weight) { setPerc(perc); Taste.setId(id); Weight = weight; }
ui Candy::getPerc() const { return Percentege_of_sugar; }
void Candy::setWeight(ui weight) { Weight = weight; }
ui Candy::getWeight() const { return Weight; }
void Candy::setPerc(ui perc) { Percentege_of_sugar = perc < 100 ? perc : 100; }
void Candy::Print() { cout << "Процентное содержание сахара: " << Candy::Percentege_of_sugar << "%" << endl; }
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