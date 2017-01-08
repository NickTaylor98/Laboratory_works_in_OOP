// LPLab16.1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Generation.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Тест:", " Без ошибок", "");
		Log::WriteParm(log, parm);
		In::IN in = Log::getin(parm.in, log);
		Log::WriteIn(log, in);
		P::LEX tables = P::Par(in, log, parm);
		PN::PolishNotation(tables.Lextable, tables.Idtable);
		MFST_TRACE_START(fopen(Log::From_UTF_to_ASCII(parm.sintax), "w"))
		MFST::Mfst mfst(tables, GRB::getGreibach());
		mfst.start(fopen(Log::From_UTF_to_ASCII(parm.sintax), "a"));
		mfst.savededucation();
		mfst.printrules(fopen(Log::From_UTF_to_ASCII(parm.sintax), "a"));
		Log::WriteLog(log);
	    GNR::Generation(parm, tables.Idtable,tables.Lextable,mfst.storestate);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	};
	system("pause");
	return 0;
}