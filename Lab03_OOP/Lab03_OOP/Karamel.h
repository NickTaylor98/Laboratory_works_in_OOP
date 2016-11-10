#pragma once
#include "Candy.h"
enum Color { Red = 0, Yellow, Blue, Green, Orange, Black, White, Unknown };
class Karamel : public Candy
{
	Color color;
public:
	Karamel();
	Karamel(ui, Color,ui weight);
	void setColor(Color);
	Color getColor();
	virtual void Print();
	virtual ~Karamel();
	virtual void toConsole();
};