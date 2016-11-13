#pragma once
#include "stdafx.h"
#include <string>
using ui = unsigned int;
#define ARRAY_OF_TASTES {"Клубника", "Банан", "Вишня", "Манго", "Молоко", "Неизвестный"}
class Candy
{
private:
	class Filling
	{
		ui id;
        const string Array_of_tastes[6] = { "Клубника", "Банан", "Вишня", "Манго", "Молоко", "Неизвестный" };
	public:
		Filling();
		Filling(Filling& fill);
		void setId(ui id);
		ui getId() const;
		string getTaste() const;
		void Print(Candy);
	} Taste;
public:
	Candy();
	Candy(ui Percentage_of_sugar, ui id, ui weight);
	Candy(const Candy&);
	ui getPerc() const;
	void setPerc(ui sugar);
	virtual void Print();
	bool TasteGood();
	void setWeight(ui);
	ui getWeight() const;
	virtual ~Candy();
	virtual void toConsole();
	bool operator==(const Candy&);
	bool operator!=(const Candy&);
	Candy operator=(const Candy&);
protected:
	ui Percentege_of_sugar;
	ui Weight;
};