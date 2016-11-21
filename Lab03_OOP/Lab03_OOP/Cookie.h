#pragma once
#include "Kond_izd.h"
enum Form {Triangle = 0, Circle, Rectangle, Other};
class Cookie : public Kond_izd
{
	bool Izyum;
	Form form;
	static ui Counter;
protected:
	ui Weight;
public:
	Cookie();
	Cookie(bool, Form, ui weight);
	void setIzyum(bool);
	void setForm(Form);
	void setWeight(ui);
	ui getWeight() const;
	bool getIzyum();
	Form getForm();
	ui getCount() const;
	virtual void Print();
	virtual ~Cookie();
	virtual void toConsole();
};