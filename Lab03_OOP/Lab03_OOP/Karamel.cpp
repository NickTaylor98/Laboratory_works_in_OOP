#include "stdafx.h"
#include "Karamel.h"
Karamel::Karamel(): Candy::Candy() { color = Unknown; }
Karamel::Karamel(ui perc, Color col, ui weight) : Candy(perc, 6, weight) { color = col; }
void Karamel::toConsole()
{
	cout << typeid(this).name() <<endl;
	Print();
	cout << "------------------------------------\n";
}
Karamel::~Karamel() { color = Unknown; }
Color Karamel::getColor() { return color; }
void Karamel::setColor(Color col) {color = col;}
void Karamel::Print()
{
	string str;
	switch (Karamel::getColor())
	{
	case Red: str = "Красный"; break;
	case Yellow: str = "Жёлтый"; break;
	case Blue: str = "Голубой"; break;
	case Green: str = "Зелёный"; break;
	case Orange: str = "Оранжевый"; break;
	case Black: str = "Чёрный"; break;
	case White: str = "Белый"; break;
	case Unknown: str = "Неизвестный"; break;
	default:;
	}	
	Candy::Print();
	cout << "Цвет карамели: " << str << endl;
	str.~basic_string();
}