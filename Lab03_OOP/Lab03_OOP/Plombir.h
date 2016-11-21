#pragma once
#include "Ice_Cream.h"
class Plombir;
class Curator { public: void ICanModify(Plombir, ui); };
class Plombir : public Ice_Cream
{
	friend class Inspector;
private:
	ui Percentage_of_milk;
public:
	Plombir();
	Plombir(ui cost, ui perc, ui percm, ui max, ui weight);
	virtual ~Plombir();
	void setPerc_milk(ui perc);
	ui getPerc_milk() const; 
	virtual void Print();
	virtual void toConsole();
	friend void Curator::ICanModify(Plombir, ui);
};
class Inspector { public: void IKnowAllAboutYou(Plombir); };