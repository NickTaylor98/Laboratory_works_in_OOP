#include "stdafx.h"
#include "Ice_Cream.h"
Ice_Cream::Ice_Cream() : Candy() { 	Cost = 0; }
Ice_Cream::Ice_Cream(ui cost, ui perc, ui max =100000, ui weight=100) : Candy(perc, 9, weight), MaxCost(max) { Cost = cost; }
Ice_Cream::~Ice_Cream() { Cost = 0; }
void Ice_Cream::setCost(ui cost) { Cost = (cost < MaxCost? cost: MaxCost); }
ui Ice_Cream::getCost() const { return Cost; }
void Ice_Cream::Print() 
{
	Candy::Print(); 
	cout << "Цена за мороженое: " << Cost << endl;
}
void Ice_Cream::toConsole()
{
	cout << typeid(this).name() <<   endl;
	Print();
	cout << "------------------------------------\n";
}