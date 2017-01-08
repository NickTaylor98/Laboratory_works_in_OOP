#include "stdafx.h"

namespace LT
{
	LexTable Create(int size)
	{
		if (size > LT_MAXSIZE) throw ERROR_THROW(120);
		LexTable rc;
		rc.table = new Entry[rc.maxsize = size];
		rc.size = 0;
		std::memset(rc.table, 0xff, sizeof(Entry)*size);
		return rc;
	}
	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size >= lextable.maxsize) throw ERROR_THROW(117);
		lextable.table[lextable.size++] = entry;
	}
	Entry GetEntry(LexTable& lextable, int n)
	{
		if (n >= lextable.size) throw ERROR_THROW(118);
		return lextable.table[n];
	}
	void Delete(LexTable& lextable)
	{
		if (!lextable.size) throw ERROR_THROW(119);
		delete lextable.table;
	}
	void Delete_Elem(LexTable& lextable, char lexema)
	{
		int i, k;
		for (i = 0; i < lextable.size; i++)
			if (lextable.table[i].lexema == lexema)
			{
				for (k = i; k < lextable.size; k++)
					lextable.table[k] = lextable.table[k + 1];
				lextable.size--;
				if (lextable.table[i].lexema == lexema) 
					i--;
			}
	}
}