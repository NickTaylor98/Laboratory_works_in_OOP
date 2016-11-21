#pragma once
#include "Plombir.h"
#include "Chocolate_candy.h"
#include "Cookie.h"
#include "Printer.h"
#include <vector>
class Controller;
class Child_present
{
	vector<Kond_izd*> parts;
	friend class Controller;
public:
	void setParts(vector <Kond_izd*>);
	vector<Kond_izd*> getParts() const;
	void Add(Kond_izd*, ...);
	void Add(ui size, Kond_izd*, ...);
	void Delete(ui);
	void toConsole() const;
};
class Controller
{
public:
	Controller();
	ui Weight(Child_present);
	void Sort_of_candy(Child_present);
	Candy Find_Candy(Child_present, ui, ui);
	void toConsole(Child_present);
};