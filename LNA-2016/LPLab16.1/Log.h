#pragma once
//#include <fstream>
#include "In.h"
#include "Parm.h"
#include "Error.h"
#define TRUE	"true"
#define FALSE	"false"
namespace Log
{
	struct LOG
	{
		wchar_t logfile[PARM_MAX_SIZE];
		FILE* stream;
		LOG() {logfile[0] = 0x00; stream = nullptr;}
		LOG(wchar_t* wc, FILE* pstream) { wcscpy_s(logfile, wc); stream = pstream; }
	};

	static const LOG INITLOG = { L"", nullptr };
	LOG getlog(wchar_t logfile[]);
	void WriteLine(LOG log, char* c, ...);
	//void WriteLine(LOG log, wchar_t* c, ...);
	void WriteLog(LOG log);
	void WriteParm(LOG log, Parm::PARM parm);
	void WriteIn(LOG log, In::IN in);
	void WriteError(LOG log, Error::ERROR error);
	void Close(LOG log);
	void WriteErrorCL(Error::ERROR error);
	char* From_Short_To_String(short Source);
	char* From_Int_To_String(int Source);
	char* From_UTF_to_ASCII(wchar_t* Source);
	char* From_Bool_to_String(bool Source);
	In::IN getin(wchar_t infile[], LOG log);
}