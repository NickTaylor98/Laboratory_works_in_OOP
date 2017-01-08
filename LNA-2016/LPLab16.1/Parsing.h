#pragma once
#include "stdafx.h"
#define CONCAT(_str_1,_str_2) strcat(_str_1,_str_2)

namespace P
{
	struct LEX
	{
		LT::LexTable Lextable;
		IT::IdTable Idtable;
	};
	LEX Par(In::IN in, Log::LOG log, Parm::PARM parm);
	//void output_LT(Log::LOG log, LT::LexTable lextable);
	//void output_IT(Log::LOG log, IT::IdTable idtable);
}

