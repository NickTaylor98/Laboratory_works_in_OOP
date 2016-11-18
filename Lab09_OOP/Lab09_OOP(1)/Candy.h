#pragma once
#include "stdafx.h"
#define ARRAY_OF_TASTES {"Клубника", "Банан", "Вишня", "Манго", "Молоко", "Неизвестный"}
class Candy
{
	class Filling
	{
		ui id;
		string Array_of_tastes[6] = ARRAY_OF_TASTES;
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
	~Candy();
	ui getPerc() const;
	void setPerc(ui sugar);
	void Print();
	bool TasteGood();
	void setWeight(ui);
	ui getWeight() const;
	void toConsole();
	bool operator==(const Candy&);
	bool operator!=(const Candy&);
	Candy operator=(const Candy&);
	friend ostream& operator<<(ostream& out,const Candy candy);
	friend istream& operator >> (istream& in, Candy& candy);
protected:
	ui Percentege_of_sugar;
	ui Weight;
};
ostream& operator<<(ostream& out, const Candy candy);
istream& operator >> (istream& in, Candy& candy);