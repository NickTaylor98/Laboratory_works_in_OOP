#pragma once
#include "LT.h"
#include "IT.h"
namespace PN
{
	void PolishNotation(LT::LexTable& lextable, IT::IdTable& idtable);
	void PolishNotation(int lextable_pos, LT::LexTable& lextable, IT::IdTable& idtable);
}