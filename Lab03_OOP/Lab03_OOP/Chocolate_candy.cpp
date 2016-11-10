#include "stdafx.h"
#include "Chocolate_candy.h"
Chocolate_Candy::Chocolate_Candy() : Candy() {	Percentage_of_chocolate = 0; }
Chocolate_Candy::Chocolate_Candy(ui perc, ui choc, ui weight) : Candy(perc, 9, weight){ Percentage_of_chocolate = choc;}
Chocolate_Candy::~Chocolate_Candy() { Percentage_of_chocolate = 0; Weight = 0; }
void Chocolate_Candy::setChoc(ui perc) {Percentage_of_chocolate = perc;}
ui Chocolate_Candy::getChoc() const {return Percentage_of_chocolate; }
void Chocolate_Candy::toConsole()
{
	cout << typeid(this).name() <<  endl;
	Print();
	cout << "------------------------------------\n";
}
void Chocolate_Candy::Print() 
{
	Candy::Print();
	cout << "Процентное содержание шоколада: " << Percentage_of_chocolate << "%" << endl;
}