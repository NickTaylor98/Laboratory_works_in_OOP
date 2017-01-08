#include "stdafx.h"
// #define MAX_SIZE_POLISH 100
namespace PN
{
	void PolishNotation(LT::LexTable& lextable, IT::IdTable& idtable)
	{
		for (int i(0); i < lextable.size; i++)
			if (lextable.table[i].lexema == '=' || lextable.table[i].lexema == 'r' || lextable.table[i].lexema =='O')
			{
				PolishNotation(i + 1, lextable, idtable); 
				for (int k = i + 1; lextable.table[k].lexema != LEX_SEMICOLON && k<lextable.size; k++)
					if (k!=lextable.size)
						printf("%c", lextable.table[k].lexema); printf("\n");
			}
		LT::Delete_Elem(lextable, 0x00);
		for (int i(0); i < lextable.size; i++) printf("%c", lextable.table[i].lexema);
	}
    void PolishNotation(int lextable_pos, LT::LexTable& lextable, IT::IdTable& idtable)
	{
		std::stack<LT::Entry> st_for_operations;
		LT::Entry deflt{};
		int i(lextable_pos), pos(lextable_pos), numb(0), numb_of_all(0);
		for (; lextable.table[i].lexema != LEX_SEMICOLON; i++)
			{
				switch (lextable.table[i].lexema)
				{
				case LEX_LEFTTHESIS: st_for_operations.push(lextable.table[i]); break;
				case LEX_PLUS:
					 if (!st_for_operations.empty())
						while (!st_for_operations.empty() && lextable.table[i].pn <= st_for_operations.top().pn)
						{
							lextable.table[pos++] = st_for_operations.top();
							numb++;
							st_for_operations.pop();
						}
					st_for_operations.push(lextable.table[i]); break;
				case LEX_ID:
				case LEX_LITERAL: 
					switch (idtable.table[lextable.table[i].idxTI].idtype)
					{
					case IT::V :
					case IT::L :
					case IT::P : lextable.table[pos++] = lextable.table[i]; numb++; break;
					case IT::F:
						{
							std::stack<LT::Entry> st_for_functions;
							while (lextable.table[i].lexema != LEX_RIGHTTHESIS)
								if (lextable.table[i].lexema != LEX_COMMA && lextable.table[i].lexema != LEX_LEFTTHESIS)
								{
									st_for_functions.push(lextable.table[i++]);
									numb_of_all++;
								}
								else
								{
									i++;
									numb_of_all++;
								}
							while (!st_for_functions.empty() && idtable.table[st_for_functions.top().idxTI].idtype != IT::F)
							{
								lextable.table[pos++] = st_for_functions.top();
								numb++;
								st_for_functions.pop();
							}
							lextable.table[pos++] = st_for_functions.top(); // 
							numb++;										    //   special for function
							st_for_functions.pop();							// 
						}
						break;
					}
					break;
				case LEX_RIGHTTHESIS:
					if (!st_for_operations.empty())
					{
						while (!st_for_operations.empty() && st_for_operations.top().lexema != LEX_LEFTTHESIS)
						{
							lextable.table[pos++] = st_for_operations.top();
							numb++;
							st_for_operations.pop();
						}
						st_for_operations.pop();
					}
					break;
				default: return;
				}
				numb_of_all++;
			}
		while (!st_for_operations.empty()) 
		{
			lextable.table[pos++] = st_for_operations.top();
			numb++;
			st_for_operations.pop();
		}
		for (int j(numb); j<numb_of_all; j++)  lextable.table[lextable_pos + j] = deflt;
	}
}