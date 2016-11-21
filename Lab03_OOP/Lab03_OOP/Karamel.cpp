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
	case Red: str = "�������"; break;
	case Yellow: str = "Ƹ����"; break;
	case Blue: str = "�������"; break;
	case Green: str = "������"; break;
	case Orange: str = "���������"; break;
	case Black: str = "׸����"; break;
	case White: str = "�����"; break;
	case Unknown: str = "�����������"; break;
	default:;
	}	
	Candy::Print();
	cout << "���� ��������: " << str << endl;
	str.~basic_string();
}