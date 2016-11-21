#include "stdafx.h"
#include "Cookie.h"
ui Cookie::Counter = 0;
Cookie::Cookie(): Kond_izd()
{
	Counter++;
	Izyum = false;
	form = Other;
	Weight = 0;
}
void Cookie::toConsole()
{
	cout << typeid(this).name() << endl;
	Print();
	cout << "------------------------------------\n";
}
Cookie::Cookie(bool izyum, Form frm, ui weight)
{
	Counter++;
	Izyum = izyum;
	form = frm;
	Weight = weight;
}
Cookie::~Cookie()
{
	Counter--;
	Izyum = false;
	this->form = Other;
	Weight = 0;
}
ui Cookie::getCount() const { return Counter; }
void Cookie::setIzyum(bool izyum) { Izyum = izyum; }
void Cookie::setForm(Form frm) { form = frm; }
void Cookie::setWeight(ui weight) {Weight = weight;}
ui Cookie::getWeight() const {return Weight;}
bool Cookie::getIzyum() { return Izyum; }
Form Cookie::getForm() { return form; }
void Cookie::Print()
{
	string str;
	switch (Cookie::getForm())
	{
	case Triangle: str = "Треугольник"; break;
	case Circle: str = "Круг"; break;
	case Rectangle: str = "Прямоугольник"; break;
	case Other: str = "Неизвестно"; break;
	default:;
	}
	cout <<"Наличие изюма: " << (Cookie::getIzyum()?"да":"нет") << endl;
	cout << "Форма печенья: " << str << endl;
	str.~basic_string();
}