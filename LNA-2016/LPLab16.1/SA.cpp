#include "stdafx.h"
namespace SA
{
	void Create_Good_Id(char* &id)
	{
		if (strlen(id) > ID_MAXSIZE - 1) id[ID_MAXSIZE-1] = 0x00;
		else id[strlen(id) + 1] = 0x00;
	}
	bool Good_Literal(Log::LOG log, IT::Entry& elem)
	{
		bool rc = true;
		if (elem.value.vstr.len > STR_LITERAL_MAXSIZE)
		{
			Log::WriteError(log, Error::geterrorin(128, elem.idxfirstLE));
			rc = false;
		}
		return rc;
	}
	bool If_Var_Id(Log::LOG log,LT::Entry& lem, IT::Entry& elem)
	{
		if (!elem.is_var)
		{
			Log::WriteError(log, Error::geterror_id(107, elem.id_buf, lem.sn));
			memset(elem.id, NULL, ID_MAXSIZE);
		}
		return true;
	}
	void Unknown_Type(Log::LOG log, IT::Entry& elem)
	{
		Log::WriteError(log, Error::geterror_id(102, elem.id_buf, elem.idxfirstLE));
		elem.is_var = false;
	}
	void Good_Type_of_Operand(Log::LOG log, LT::LexTable lextable, IT::IdTable idtable)
	{
		IT::Entry elem;
		char* buff = new char[STR_LITERAL_MAXSIZE];
		for (int i(0); i < lextable.size; i++)
			if (lextable.table[i].lexema == LEX_FUNCTION && !idtable.table[lextable.table[i + 1].idxTI].std_lib)
				elem = idtable.table[lextable.table[i + 1].idxTI];
			else if (lextable.table[i].lexema == LEX_EQUAL)
			{
				elem = idtable.table[lextable.table[i-1].idxTI];
				if (lextable.table[i + 2].lexema == LEX_SEMICOLON)
				{
					if (idtable.table[lextable.table[i - 1].idxTI].iddatatype != idtable.table[lextable.table[i + 1].idxTI].iddatatype)
					{
						if (idtable.table[lextable.table[i + 1].idxTI].idtype == IT::L)
							sprintf(buff, "%s %s и %s", "литерала", idtable.table[lextable.table[i + 1].idxTI].id, idtable.table[lextable.table[i - 1].idxTI].id_buf);
						else sprintf(buff, "%s и %s", idtable.table[lextable.table[i + 1].idxTI].id_buf, idtable.table[lextable.table[i - 1].idxTI].id_buf);
						Log::WriteError(log, Error::geterror_id(121, buff, lextable.table[i].sn));
						memset(buff, NULL, STR_LITERAL_MAXSIZE);
					}
				}
				for (int k(i + 1); lextable.table[k].lexema != LEX_SEMICOLON && k<lextable.size; k++)
					if (idtable.table[lextable.table[k].idxTI].iddatatype != idtable.table[lextable.table[i - 1].idxTI].iddatatype
						&& idtable.table[lextable.table[k].idxTI].idtype == IT::F)
					{
							sprintf(buff, "%s и %s", idtable.table[lextable.table[k].idxTI].id_buf, elem.id_buf);
							Log::WriteError(log, Error::geterror_id(121, buff, lextable.table[k].sn));
							memset(buff, NULL, STR_LITERAL_MAXSIZE);
					}
					else if (lextable.table[k].lexema == LEX_PLUS)
						if (idtable.table[lextable.table[k + 1].idxTI].iddatatype != elem.iddatatype)
						{
							if (idtable.table[lextable.table[k + 1].idxTI].idtype == IT::L)
								sprintf(buff, "%s %s и %s", "литерала", idtable.table[lextable.table[k + 1].idxTI].id, elem.id_buf);
							else if (lextable.table[k + 1].idxTI != TI_NULLIDX)
								sprintf(buff, "%s и %s", idtable.table[lextable.table[k + 1].idxTI].id_buf, elem.id_buf);
							else 
								sprintf(buff, "%s и %s", "Неопределённый идентифиактор", elem.id_buf);
 							Log::WriteError(log, Error::geterror_id(121, buff, lextable.table[i].sn));
							memset(buff, NULL, STR_LITERAL_MAXSIZE);
						}
						else if (idtable.table[lextable.table[k + 1].idxTI].iddatatype != IT::INT)
							Log::WriteError(log, Error::geterrorin(129, lextable.table[k + 1].sn));
			}
			else if (lextable.table[i].lexema == LEX_RETURN)
			{
				int k = i + 1;
				while (k < lextable.size && lextable.table[k].lexema != LEX_SEMICOLON && lextable.table[k].lexema != LEX_PLUS) k++;
				if (lextable.table[k].lexema != LEX_SEMICOLON)
					if (k != lextable.size)
						if (idtable.table[lextable.table[k + 1].idxTI].iddatatype != elem.iddatatype)
					    {
					    	if (idtable.table[lextable.table[k + 1].idxTI].idtype == IT::L)
					    	sprintf(buff, "%s %s и %s", "литерала", idtable.table[lextable.table[k + 1].idxTI].id, elem.id_buf);
					    	else sprintf(buff, "%s и %s", idtable.table[lextable.table[k + 1].idxTI].id_buf, elem.id_buf);
					    	Log::WriteError(log, Error::geterror_id(121, buff, lextable.table[k].sn));
					    	memset(buff, NULL, STR_LITERAL_MAXSIZE);
					    }
			}
	}
	bool Good_Braces(Log::LOG log, LT::LexTable& lextable)
	{
		bool rc = true;
		int k, num_of_left(0), num_of_right(0);
		for (int i(0); i < lextable.size; i++)
		{
			if (lextable.table[i].lexema == LEX_EQUAL || lextable.table[i].lexema == LEX_OUT)
			{
				for (k = i + 1; lextable.table[k].lexema != LEX_SEMICOLON; k++)
					switch (lextable.table[k].lexema)
					{
					case LEX_LEFTTHESIS: num_of_left++; break;
					case LEX_RIGHTTHESIS: num_of_right++; break;
					}
				i = k;
				if (num_of_left != num_of_right)
				{
					Log::WriteError(log, Error::geterrorin(122, lextable.table[k].sn));
					rc = false;
				}
				num_of_left = num_of_right = 0;
			}
		}
		return rc;
	}
	bool Good_Param_of_Function(Log::LOG log, LT::LexTable& lextable, IT::IdTable& idtable)
	{
		bool rc = true;
		int k(0), num_of_param(1);
		bool LeftTheSis = false;
		for (int i(0); i < lextable.size; i++)
		{
			if ((lextable.table[i].lexema == LEX_RIGHTTHESIS && lextable.table[i + 1].lexema == LEX_LEFTBRACE)
				|| (lextable.table[i].lexema == LEX_SEMICOLON && lextable.table[i+1].lexema == LEX_BRACELET))
				LeftTheSis = !LeftTheSis;
			if (idtable.size > 0 && idtable.table[lextable.table[i].idxTI].idtype == IT::F && LeftTheSis)
			{
				for (k = i + 2; lextable.table[k].lexema != LEX_RIGHTTHESIS; k++)
				{
					switch (lextable.table[k].lexema)
					{
					case LEX_COMMA: num_of_param++; break;
					case LEX_ID: 
					case LEX_LITERAL:
						if (lextable.table[k + 1].lexema != LEX_ID && lextable.table[k + 1].lexema != LEX_LITERAL)
						{
							if (idtable.table[lextable.table[i].idxTI + num_of_param].iddatatype != idtable.table[lextable.table[k].idxTI].iddatatype)
							{
								Log::WriteError(log, Error::geterrorin(127, lextable.table[i].sn));
								rc = false;
							}
						}
						else Log::WriteError(log, Error::geterrorin(106, lextable.table[k].sn));
						break;
					}
				}
				if (idtable.table[lextable.table[i].idxTI].number_of_param != num_of_param)
				{
					Log::WriteError(log, Error::geterror_id(126, idtable.table[lextable.table[i].idxTI].id, lextable.table[i].sn));
					rc = false;
				}
				i = k;
				num_of_param = 1;
			}
		}
		return rc;
	}
	void Good_Return(Log::LOG log, LT::LexTable& lextable, IT::IdTable& idtable)
	{
		bool good = true;
		for (int i(0); i < lextable.size; i++)
			if (idtable.size && idtable.table[lextable.table[i].idxTI].idtype == IT::F && !idtable.table[lextable.table[i].idxTI].std_lib)
			{
				int k(i + 1);
				while (k < lextable.size && lextable.table[k].lexema != LEX_BRACELET && good)
				{
					if (lextable.table[k].lexema == LEX_RETURN)
					{
						while (lextable.table[k + 1].lexema == LEX_LEFTTHESIS) k++;
						if (idtable.table[lextable.table[k+1].idxTI].iddatatype != idtable.table[lextable.table[i].idxTI].iddatatype)
						{
							Log::WriteError(log, Error::geterror_id(123, idtable.table[lextable.table[i].idxTI].id, lextable.table[k].sn));
							good = false;
						}
					}
					k++;
				}
				i = k;
			}
			else 
				if (lextable.table[i].lexema == LEX_MAIN)
			    {
			    	int k(i + 1);
					if (k < lextable.size)
					{
						while (k < lextable.size && lextable.table[k].lexema != LEX_BRACELET && good)
						{
							if (lextable.table[k].lexema == LEX_RETURN)
							{
								while (lextable.table[k + 1].lexema == LEX_LEFTTHESIS) k++;
								if (idtable.table[lextable.table[k + 1].idxTI].iddatatype != IT::INT)
								{
									Log::WriteError(log, Error::geterror_id(123, "main", lextable.table[k].sn));
									good = false;
								}
							}
							k++;
						}
						i = k;
					}
			    }
	}
	void Null_String(Log::LOG log, const IT::Entry& elem)
	{
		if (elem.value.vstr.len<1) Log::WriteError(log, Error::geterrorin(124,elem.idxfirstLE));
	}
}