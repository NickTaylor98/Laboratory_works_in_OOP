#include "stdafx.h"
#include "Child_present.h"
#include <algorithm>
#define TO_CANDY static_cast<Candy*>(pres.getParts()[i])
vector <Kond_izd*> Child_present::getParts() const { return this->parts;}
void Child_present::setParts(vector <Kond_izd*> parts) { this->parts = parts; }
//void Child_present::Add(Kond_izd* kond) { this->parts.push_back(kond); }
void Child_present::Add(Kond_izd* kond, ...)
{
	Kond_izd** pkond = &kond;
	ui i = 0;
	while (pkond[i] != nullptr) this->parts.push_back(pkond[i++]);
}
void Child_present::Add(ui size, Kond_izd* kond, ...)
{
	Kond_izd** pkond = &kond;
	ui i = 0;
	while (i < size) this->parts.push_back(pkond[i++]);
}
void Child_present::Delete(ui id) { parts.erase(parts.begin() + id);}
void Child_present::toConsole() const { for (auto i: parts) (*i).toConsole(); }
ui Controller::Weight(Child_present pres)
{
	ui sum = 0;
	for (auto i: pres.parts)  sum += (*i).getWeight();
	return sum;
}
bool Sort_Function(Kond_izd* kond1, Kond_izd* kond2)
{
	bool rc = false;
	if (kond1->getWeight() < kond2->getWeight()) rc = true;
	return rc;
}
void Controller::Sort_of_candy(Child_present pres) { sort(pres.parts.begin(), pres.parts.end(), Sort_Function); }
Candy Controller::Find_Candy(Child_present pres, ui lim1, ui lim2)
{
	Candy* candy = new Candy();
	for (ui i(0); i < pres.getParts().size() && *candy == Candy(); i++) if (TO_CANDY->getPerc() > lim1 && TO_CANDY->getPerc() < lim2) candy = TO_CANDY;
	return *candy;
}
void Controller::toConsole(Child_present pres) { cout << "Содержимое контейнера: " << endl; for (auto i: pres.parts) i->toConsole(); }
Controller::Controller() {}