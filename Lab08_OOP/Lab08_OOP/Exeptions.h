#pragma once
#include "stdafx.h"
class Basic_Exeption : public exception
{
protected:
	string error;
public:
	Basic_Exeption();
	Basic_Exeption(string);
	void setError(string);
	string getError() const;
};

class Exeption_Memory : public Basic_Exeption
{public: Exeption_Memory(string);};
class Exeption_Fstream : public Basic_Exeption
{
public: Exeption_Fstream(string);
};
class Exeption_Faculty: public Basic_Exeption
{
public: Exeption_Faculty(string);
};
class Exeption_Course : public Basic_Exeption
{
public: Exeption_Course(string);
};
class Spec_Exception
{};