#pragma once
#include "stdafx.h"
#define MAX_SIZE_OF_ASSEMBLY_FILE 1024*1024
namespace GNR
{
	void Generation( Parm::PARM parm, IT::IdTable idtable, LT::LexTable lextable, std::stack<MFST::MfstState>& st);
}