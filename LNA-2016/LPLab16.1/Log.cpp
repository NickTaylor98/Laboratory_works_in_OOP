#include "stdafx.h"
#define LINE_MAX_SIZE 1000
#define MAX(x,y) (x)>(y)?(x):(y)
namespace Log
{
	char* From_UTF_to_ASCII(wchar_t* Source)
	{
		char *rc = new char[wcslen(Source)];
		wcstombs(rc, Source, strlen(rc));
		return rc;
	}
	char* From_Bool_to_String(bool Source)
	{
		char* rc = new char[MAX(strlen(TRUE), strlen(FALSE))];
		Source ? strcpy(rc, TRUE) : strcpy(rc, FALSE);
		return rc;
	}
	char* From_Int_To_String(int Source)
	{
		char* rc = new char[3];
		sprintf(rc, "%d", Source);
		return rc;
	}
	char* From_Short_To_String(short Source)
	{
		char* rc = new char[3];
		sprintf(rc, "%d", Source);
		return rc;
	}
	LOG getlog(wchar_t logfile[])
	{
		LOG* rc = new LOG;
		wcscpy_s(rc->logfile, logfile);
		//rc->stream = new std::ofstream(logfile);
		rc->stream = fopen(From_UTF_to_ASCII(logfile), "w");
		if (!rc->stream) throw ERROR_THROW(112)
		return *rc;
	}
	void WriteLine(LOG log, char* c, ...)
	{
		if (!log.stream) ERROR_THROW(101);
		char** rc = &c;
		while (*rc != "") fprintf(log.stream,"%s",*rc++);
	}
	/*void WriteLine(LOG log, wchar_t* c, ...)
	{
		if (!log.stream) ERROR_THROW(101);
		wchar_t **pc = &c;
		while (*pc != L"") 
			fprintf(log.stream,"%s", From_UTF_to_ASCII(*pc++));
	}*/
	void WriteLog(LOG log)
	{
		char* time_now = new char[26];
		time_t date = time(nullptr);
		strftime(time_now, strlen(time_now), "Дата: %x %X", localtime(&date));
		WriteLine(log, "---- Протокол ------ ", time_now, "  --------------------", "");
		delete[] time_now;
	}
	void WriteParm(LOG log, Parm::PARM parm)
	{
		WriteLine(log, 
			"\n------ Параметры ------ ", 
			"\n", "-in: ", From_UTF_to_ASCII(parm.in),
			"\n", "-out: ", From_UTF_to_ASCII(parm.out),
			"\n", "-log: ", From_UTF_to_ASCII(parm.log),  
			"\n", "-sintax: ", From_UTF_to_ASCII(parm.sintax),
			"\n", "-gener: ", From_UTF_to_ASCII(parm.generation), "\n", "");
	}
	void WriteIn(LOG log, In::IN in)
	{
		WriteLine(log, "\n---- Исходные данные ------\n", "Количество символов: ", From_Int_To_String(in.size), "\n", "Проигнорировано    : ", From_Int_To_String(in.ignor), "\n", "Количество строк   : ", From_Int_To_String(in.lines), "\n", "");
	}
	void WriteError(LOG log, Error::ERROR error)
	{
		if (!log.stream)
			printf("Ошибка %i: %s, строка %i, позиция %i\n\n", error.id, error.message, error.inext.line, error.inext.col);
		else WriteLine(log, "Ошибка ", From_Int_To_String(error.id), ": ", error.message, ", строка ", From_Short_To_String(error.inext.line), ", позиция ", From_Short_To_String(error.inext.col), "\n", "");
	}
	void WriteErrorCL(Error::ERROR error)
	{
		printf("Ошибка %i: %s\n", error.id, error.message);
	}
	void Close(LOG log)
	{
		fclose(log.stream);
	}
}