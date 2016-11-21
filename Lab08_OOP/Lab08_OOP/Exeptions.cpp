#include "stdafx.h"
#include "Exeptions.h"
Basic_Exeption::Basic_Exeption() { error = "Unknown error";}
Basic_Exeption::Basic_Exeption(string err) { error = err; }
string Basic_Exeption::getError() const { return error; }
void Basic_Exeption::setError(string err) { error = err;}

Exeption_Memory::Exeption_Memory(string err)
{	this->error = err; }

Exeption_Fstream::Exeption_Fstream(string err)
{
	this->error = err;
}

Exeption_Faculty::Exeption_Faculty(string err)
{
	this->error = err;
}

Exeption_Course::Exeption_Course(string err)
{
	this->error = err;
}
