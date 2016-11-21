#include "stdafx.h"
#include "Plombir.h"
Plombir::Plombir() : Ice_Cream() { Percentage_of_milk = 0;}
Plombir::~Plombir() { Percentage_of_milk = 0; }
Plombir::Plombir(ui cost, ui perc, ui percm, ui max, ui weight=100) : Ice_Cream(cost, perc, max, weight) { Percentage_of_milk = percm; }
void Plombir::setPerc_milk(ui perc) { Percentage_of_milk = perc; }
ui Plombir::getPerc_milk() const { return Percentage_of_milk; }
void Plombir::toConsole() { cout << typeid(this).name() << endl; Print(); cout << "------------------------------------\n";}
void Plombir::Print()
{
	Ice_Cream::Print();
	cout << "Процентное содержание молока: " << Percentage_of_milk << endl;
	cout << "------------------------------------\n";
}
void Inspector::IKnowAllAboutYou(Plombir plom) { cout << "Процентное содержание молока: " << plom.Percentage_of_milk << endl; }
void Curator::ICanModify(Plombir plom, ui perc) { plom.Percentage_of_milk = perc;}