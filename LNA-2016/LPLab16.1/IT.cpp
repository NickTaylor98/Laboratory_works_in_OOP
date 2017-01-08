#include "stdafx.h"
namespace IT
{
	IdTable Create(int size)
	{
		if (size > TI_MAXSIZE) throw ERROR_THROW(114);
		IdTable* rc = new IdTable();
		rc->table = new Entry[rc->maxsize = size];
		rc->size = 0;
		return *rc;
	}
	void Add(IdTable& idtable, Entry entry)
	{
		if (idtable.size >= idtable.maxsize) ERROR_THROW(113);
		idtable.table[idtable.size++] = entry;
	}
	Entry GetEntry(IdTable& idtable, int n)
	{
		if (n >= idtable.size) throw ERROR_THROW(115);
		return idtable.table[n];
	}
	int IsId(Log::LOG log, IdTable& idtable, IT::Entry elem)//char id[ID_MAXSIZE])
	{
		int i(0);
		bool rc = true;
		while (i < idtable.size && rc)
		{
			if (!strcmp(idtable.table[i].id, elem.id))
				if (elem.is_var) 
					Log::WriteError(log, Error::geterror_id(103, elem.id_buf, elem.idxfirstLE));
				else rc = !rc;
			i++;
		}
		return !rc? i-1: TI_NULLIDX;
	}
	int IsLiteral(IdTable& idtable, IT::Entry elem)
	{
		int i(0);
		bool rc = true;
		while (i < idtable.size && rc)
		{
			if (idtable.table[i].idtype == IT::L)
			{
				if (elem.iddatatype == IT::INT &&
					elem.iddatatype == idtable.table[i].iddatatype &&
					elem.value.vint == idtable.table[i].value.vint) rc = !rc;
				else if (elem.iddatatype == IT::STR &&
					elem.iddatatype == idtable.table[i].iddatatype &&
					elem.value.vstr.len == idtable.table[i].value.vstr.len &&
					!strcmp(elem.value.vstr.str, idtable.table[i].value.vstr.str)) rc = !rc;
			}
			i++;
		}
		return !rc ? i - 1 : TI_NULLIDX;
	}
	void Delete(IdTable& idtable)
	{
		if (!idtable.size) throw ERROR_THROW(116);
		for (int i(0); i < idtable.size; i++) delete[] idtable.table;
		idtable.maxsize = idtable.size = 0;
	}
	void Delete_Elem(IdTable& idtable, LT::LexTable& lextable, int index)
	{
		if (index < 0 && index > idtable.size) throw ERROR_THROW(109);
		for (int i(index); i < idtable.size - 1; i++)
			idtable.table[i] = idtable.table[i + 1];
		for (int i(0); i < lextable.size; i++)
			if (lextable.table[i].idxTI == index) // for main
				lextable.table[i].idxTI = TI_NULLIDX;
			else if (lextable.table[i].idxTI > index)
				lextable.table[i].idxTI--;
		idtable.table[--idtable.size] = IT::Entry();
	}
}