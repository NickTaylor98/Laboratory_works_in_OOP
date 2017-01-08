#include "stdafx.h"
In::IN Log::getin(wchar_t infile[], LOG log)
{
	In::IN rc;
	int position = 0;
	uc simbol;
	rc.size = rc.ignor = 0;
	rc.text = new uc[IN_MAX_LEN_TEXT];
	rc.lines = 1;
	FILE* file = fopen(Log::From_UTF_to_ASCII(infile), "r");
	if (!file) throw ERROR_THROW(110);
	simbol = fgetc(file);
	while(!feof(file))
	{
		switch (rc.code[simbol])
		{
		case rc.A: while (rc.code[simbol] != EOF && rc.code[simbol] != rc.N) simbol = fgetc(file);
		case rc.N: rc.text[rc.size] = 0x7c; rc.lines++;	position = 0; break; // 0x7c = '|'
		case rc.F: WriteError(log, Error::geterrorin(111, rc.lines, position)); rc.size--; break;
		case rc.T: 
		case rc.P:
		case rc.R:
		case rc.O:
		case rc.S: rc.text[rc.size] = (char)simbol; break;
		}
		position++;
		rc.size++;
		simbol = fgetc(file); 
	}
	rc.text[rc.size] = 0x00;
	fclose(file);
	return rc;
}