#include "stdafx.h"
#include "Kond_izd.h"
#include "Chocolate_candy.h"
#include "Cookie.h"
#include "Karamel.h"
#include "Plombir.h"
#include "Printer.h"
#include "Child_present.h"
int main()
{
	setlocale(LC_ALL, "");
	Candy* chcandy = new Chocolate_Candy(80, 21, 89);
	Karamel* karam = new Karamel(23, Yellow, 34);
	Kond_izd* cook = new Cookie(false, Circle, 567);
	Ice_Cream* ice = new Ice_Cream(1203,34,2000, 987);
	Plombir* plom = new Plombir();
	Child_present pres{};
	pres.Add(chcandy, karam, cook, ice, plom, nullptr);
	Controller control{};
	cout << "Суммарная масса всех сладостей подарка: " << control.Weight(pres) << endl;
	Candy* candy = new Candy(control.Find_Candy(pres, 60, 100));
	(*candy).toConsole();
	pres.Delete(2);
	pres.Add(6, karam, karam, cook, cook, ice,ice);
	control.Sort_of_candy(pres);
	control.toConsole(pres);
	delete candy, chcandy, karam, cook, ice, plom;
	system("pause");
    return EXIT_SUCCESS;
}