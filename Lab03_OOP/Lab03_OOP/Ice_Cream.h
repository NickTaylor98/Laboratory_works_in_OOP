#pragma once
#include "Candy.h"
class Ice_Cream : public Candy
{
public: 
	Ice_Cream();
	Ice_Cream(ui cost, ui perc , ui max, ui weight);
	virtual ~Ice_Cream();
	void setCost(ui);
	ui getCost() const;
	virtual void Print();
	virtual void toConsole();
protected:
	ui Cost;
private :
	const ui MaxCost = 100000;
};