#pragma once
#include "Candy.h"
class Chocolate_Candy : public Candy
{
	ui Percentage_of_chocolate;
public:
	Chocolate_Candy();
	virtual ~Chocolate_Candy();
	Chocolate_Candy(ui sugar, ui choc, ui weight);
	void setChoc(ui);
	ui getChoc() const;
	virtual void Print();
	virtual void toConsole();
};