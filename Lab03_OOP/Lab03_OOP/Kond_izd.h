#pragma once
#include <string>
#include <typeinfo>
using ui = unsigned int;
//Классы – Кондитерское изделие, Конфета, Карамель, Шоколадная конфета, Печенюшка.
class Kond_izd
{
public:
	Kond_izd();
	Kond_izd(const Kond_izd&);
	virtual ~Kond_izd();
    virtual void Print() = 0;
	virtual void toConsole() = 0;
    virtual void setWeight(ui) = 0;
	virtual ui getWeight() const = 0;
private:
protected:
};