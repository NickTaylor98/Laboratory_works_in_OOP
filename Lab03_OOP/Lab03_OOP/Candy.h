#pragma once
#include "Kond_izd.h"
#define ARRAY_OF_TASTES {"Клубника", "Банан", "Вишня", "Манго", "Молоко", "Неизвестный"}
class Candy : public Kond_izd
{
private:
	class Filling
	{
		ui id;
		const string Array_of_tastes[6] = ARRAY_OF_TASTES;
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
	ui getPerc() const;
	void setPerc(ui sugar);
	virtual void Print();
	bool TasteGood();
	void setWeight(ui);
	ui getWeight() const;
	virtual ~Candy();
	virtual void toConsole();
	bool operator==(const Candy&);
	
protected:
	ui Percentege_of_sugar;
	ui Weight;
};