#include "stdafx.h"
#include "Generation.h"
#define MAX_SIZE_OF_LINE 250
#define FLAG_S ";S"
#define FLAG_F ";F"
#define FLAG_N ";N"
#define FLAG_E ";E"
#define FLAG_W ";W"
#define FLAG_R ";R"
#define FLAG_M ";M"
#define FUNCT_0(id) sprintf(buff, "\n%s PROC ;F\n ;N\n push ;E\n pop eax\n ret\n %s ENDP\n ;S", id, id)
#define FUNCT_5(id) sprintf(buff, "\n%s PROC ;F\n push ;E\n pop eax\n ret\n %s ENDP\n ;S", id, id)
#define MAIN_0 "\nmain PROC\n push FOR_RUSSIAN\n call SetConsoleOutputCP\n ;N\n push ;E\n call ExitProcess\n main ENDP\nend main"
#define PARAM_0(id, type) sprintf(buff,"%s:%s", id, type)
#define PARAM_1(id, type) sprintf(buff, "%s:%s, ;F", id, type)
#define BODY_FUNCT_2_0(id) sprintf(buff, "\n push ;E\n mov %s, eax\n ;N", id)
#define BODY_FUNCT_2_1(id) sprintf(buff, "\n push ;E\n pop %s\n ;N", id)
#define BODY_FUNCT_3_0(id) sprintf(buff, "\n push ;E\n pop %s", id)
#define BODY_FUNCT_3_1(id) sprintf(buff, "\n push ;E\n mov %s, eax", id)
#define BODY_FUNCT_4_1     strcpy(buff, "\n push ;E\n call out_i\n ;N")
#define BODY_FUNCT_4_2_0   strcpy(buff, "\n push ;E\n call out_s\n ;N")
#define BODY_FUNCT_4_2_1(id) sprintf(buff, "\n push offset %s\n call out_s\n ;N", id)
#define BODY_FUNCT_5_1 strcpy(buff, "\n push ;E\n call out_i")
#define BODY_FUNCT_5_2_0 strcpy(buff, "\n push ;E\n call out_s")
#define BODY_FUNCT_5_2_1(id) sprintf(buff, "\n push offset %s\n call out_s", id)
#define BODY_FUNCT_8_0(id, idf)  sprintf(buff, "\n push %s\n pop %s\n ;N", id, idf)
#define BODY_FUNCT_8_0_0(id)  sprintf(buff, "\n push ;E\n pop %s\n ;N", id)
#define BODY_FUNCT_9_0_0(id) sprintf(buff, "\n push ;E\n pop %s", id)
#define BODY_FUNCT_8_1(id, idf)  sprintf(buff, "\n push offset %s\n pop %s\n ;N", id, idf)
#define BODY_FUNCT_9_0(id, idf)  sprintf(buff, "\n push %s\n pop %s", id, idf)
#define BODY_FUNCT_9_1(id, idf)  sprintf(buff, "\n push offset %s\n pop %s", id, idf)
#define EXPRESSION_0_0(id) sprintf(buff, "offset %s", id)
#define EXPRESSION_0_1(id) sprintf(buff, "\n call %s\n push eax", id)
#define EXPRESSION_2_0_0_0(id) sprintf(buff, "%s\n push ;E", id)
#define EXPRESSION_2_0_0_1(id) sprintf(buff, "offset %s\n push ;E", id)
#define EXPRESSION_2_0_1_0(id) sprintf(buff, "%s\n ;E", id)
#define EXPRESSION_2_0_1_1(id) sprintf(buff, "offset %s\n ;E", id)
#define EXPRESSION_2_1(id) sprintf(buff, "\n call %s\n push eax\n push ;E", id)
#define EXPRESSION_4_0(id) sprintf(buff, "%s\n ;M", id)
#define EXPRESSION_4_1(id) sprintf(buff, "\n call %s\n push eax\n ;M", id) 
#define FACT_PARAM_2(id) sprintf(buff, "\n push %s", id)
#define OPERATION_PLUS "\n pop ebx\n pop eax\n add eax,ebx\n push eax"
#define OPERATION_MINUS "\n pop ebx\n pop eax\n sub eax,ebx\n push eax"
#define OPERATION_MUL "\n pop ebx\n pop eax\n imul eax,ebx\n push eax"
#define OPERATION_DIV "\n call divide\n push eax"
namespace GNR
{
	char* Create_Assembly_Line()
	{
		char* rc = new char[MAX_SIZE_OF_ASSEMBLY_FILE];
		memset(rc, NULL, MAX_SIZE_OF_ASSEMBLY_FILE);
		return rc;
	}
	void Create_Head_of_Assembly(char* &line)
	{
		CONCAT(line, "\n"                   \
			" .586\n"                       \
			" .model flat,stdcall\n"        \
			" includelib kernel32.lib\n"    \
			" includelib libucrt.lib\n"     \
			" includelib STD_LNA_2016.lib\n");
	}
	void Create_Stack_of_Assembly(char* &line)
	{
		CONCAT(line, "\n .stack 4096");
	}
	void Create_Const_of_Assembly(char* &line, IT::IdTable idtable)
	{
		Create_Stack_of_Assembly(line);
		CONCAT(line, "\n .const\n"                       \
			         " FOR_RUSSIAN sdword       1251");
		char* buff = new char[MAX_SIZE_OF_LINE];
		for (int i(0); i < idtable.size; i++)
			if (idtable.table[i].idtype == IT::L)
			{
				memset(buff, NULL, MAX_SIZE_OF_LINE);
				switch (idtable.table[i].iddatatype)
				{
				case IT::INT: sprintf(buff, "\n %s sdword      %d", idtable.table[i].id, idtable.table[i].value.vint); break;
				case IT::STR: sprintf(buff, "\n %s byte     \"%s\",0", idtable.table[i].id, idtable.table[i].value.vstr.str); break;
				}
				CONCAT(line, buff);
			}
		delete[] buff;
	}
    void Create_Data_of_Assembly(char* &line, IT::IdTable idtable)
	{
		CONCAT(line, "\n .data");
		char* buff = new char[MAX_SIZE_OF_LINE];
		for (int i(0); i < idtable.size; i++)
		{
			memset(buff, NULL, MAX_SIZE_OF_LINE);
			if (idtable.table[i].idtype == IT::V)
			{
				switch (idtable.table[i].iddatatype)
				{
				case IT::INT: sprintf(buff, "\n %s sdword      0h", idtable.table[i].id); break;
				case IT::STR: sprintf(buff, "\n %s dword  255  dup(0)", idtable.table[i].id); break;
				}
			}
			CONCAT(line, buff);
		}
		delete[] buff;
	}
	void Create_Proto_Functions_of_Assembly(char* &line, IT::IdTable idtable)
	{
		CONCAT(line, 
			"\n ExitProcess        proto : DWORD\n"                   \
			" SetConsoleOutputCP proto : SDWORD\n"                   \
			" out_i              proto : SDWORD\n"                   \
			" out_s              proto : DWORD\n"                    \
			" strlength          proto : DWORD\n"                    \
			" ipow               proto : SDWORD, :DWORD\n"           \
			" uppercase          proto : DWORD\n"                    \
			" lowercase          proto : DWORD\n"                    \
			" divide             proto : SDWORD, :SDWORD\n");
	}
	char* Type_of_Param(IT::IDDATATYPE type)
	{
		char* rc = new char[strlen("sdword")];
		switch (type)
		{
		case IT::INT:  strcpy(rc, "sdword"); break;
		case IT::STR:  strcpy(rc, "dword"); break;
		}
		return rc;
	}
	void Create_Code(FILE* file, char* &line, IT::IdTable idtable, LT::LexTable lextable, std::stack<MFST::MfstState> st)
	{
		CONCAT(line, "\n .code\n ;S");
		char* buff = new char[MAX_SIZE_OF_LINE];
		char* help = new char[MAX_SIZE_OF_ASSEMBLY_FILE];
		for (int i(0); i < st.size(); i++)
		{
			memset(buff, NULL, MAX_SIZE_OF_LINE);
			switch (st._Get_container()[i].nrule)
			{
			case 0: // Функции
				if (strstr(line, FLAG_S))
				{
					strcpy(help, strstr(line, FLAG_S));
					memset(strstr(line, FLAG_S), NULL, strlen(FLAG_S));
					switch (st._Get_container()[i].nrulechain)
					{
					case 0: 
						strcpy(buff, ";S"); break; // S->vtfi(F);S
					case 1:   //S->tfi(F){NR}S
					case 2:   //S->tfi(F){NR}S;
						FUNCT_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position + 2].idxTI].id);
						break;
					case 3: //S->m(){Nrl;}
					case 4: //S->m(){Nrl;};
						strcpy(buff, MAIN_0); break;
					case 5: // S->tfi(F){R}S
					case 6: //S->tfi(F){R}S;
						FUNCT_5(idtable.table[lextable.table[st._Get_container()[i].lenta_position + 2].idxTI].id);
						break;
					}
				}
				break;
			case 1:  // Параметры (формальные)
				if (strstr(line, FLAG_F))
				{
					strcpy(help, strstr(line, FLAG_F));
					memset(strstr(line, FLAG_F), NULL, strlen(FLAG_F));
					switch (st._Get_container()[i].nrulechain)
					{
					case 0: //F-> ti
						PARAM_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position + 1].idxTI].id, Type_of_Param(idtable.table[lextable.table[st._Get_container()[i].lenta_position + 1].idxTI].iddatatype));
						break;
					case 1: // F-> ti, F
						PARAM_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position + 1].idxTI].id, Type_of_Param(idtable.table[lextable.table[st._Get_container()[i].lenta_position + 1].idxTI].iddatatype));
						break;
					}
				}
				break;
			case 2: // Начинка функций
				if (strstr(line, FLAG_N))
				{
					strcpy(help, strstr(line, FLAG_N));
					memset(strstr(line, FLAG_N), NULL, strlen(FLAG_N));
					switch (st._Get_container()[i].nrulechain)
		     		{
		     		case 0://N->vti;N 
						strcpy(buff, FLAG_N);
						break;
		     		case 1: //N->vti;
		     				break;
		     		case 2: //N->i=E;N
		     		{
		     			if (st._Get_container()[i + 1].nrulechain != 1 && st._Get_container()[i + 1].nrulechain != 0)
		     				BODY_FUNCT_2_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
		     			else BODY_FUNCT_2_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
		     		}
		     		break;
		     	    case 3: // N->i=E;
					{
		     			if (st._Get_container()[i + 1].nrulechain != 1 && st._Get_container()[i + 1].nrulechain != 0)
		     				BODY_FUNCT_3_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
		     			else BODY_FUNCT_3_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
		     		}
		     		break;
		     	    case 4: // N->OE;N
					{
						if (st._Get_container()[i + 1].nrulechain == 0 || st._Get_container()[i + 1].nrulechain == 1)
						{
							if (idtable.table[lextable.table[st._Get_container()[i + 1].lenta_position].idxTI].iddatatype == IT::INT)
								BODY_FUNCT_4_1;
							else if (idtable.table[lextable.table[st._Get_container()[i + 1].lenta_position].idxTI].iddatatype == IT::STR)
								BODY_FUNCT_4_2_0;
						}
						else
						{
							int k = 1;
							while (idtable.table[lextable.table[st._Get_container()[i].lenta_position + k].idxTI].idtype != IT::F
								&& lextable.table[st._Get_container()[i].lenta_position + k].lexema != LEX_PLUS) k++;
							if (idtable.table[lextable.table[st._Get_container()[i].lenta_position + k].idxTI].iddatatype == IT::INT)
								BODY_FUNCT_4_1;
							else if (idtable.table[lextable.table[st._Get_container()[i].lenta_position + k].idxTI].iddatatype == IT::STR)
								BODY_FUNCT_4_2_0;
						}
		     		}
		     		break;
		     	    case 5: // N->OE;
					{
						if (st._Get_container()[i + 1].nrulechain == 0 || st._Get_container()[i + 1].nrulechain == 1)
						{
							if (idtable.table[lextable.table[st._Get_container()[i + 1].lenta_position].idxTI].iddatatype == IT::INT)
								BODY_FUNCT_5_1;
							else if (idtable.table[lextable.table[st._Get_container()[i + 1].lenta_position].idxTI].iddatatype == IT::STR)
								BODY_FUNCT_5_2_0;
						}
						else //если в выводе есть функция, то надо найти её и вывести в соответствии с её типом
						{
							int k = 1;
							while (idtable.table[lextable.table[st._Get_container()[i].lenta_position + k].idxTI].idtype != IT::F &&
								lextable.table[st._Get_container()[i].lenta_position + k].lexema != LEX_PLUS) k++;
							if (idtable.table[lextable.table[st._Get_container()[i].lenta_position + k].idxTI].iddatatype == IT::INT)
								BODY_FUNCT_5_1;
							else if (idtable.table[lextable.table[st._Get_container()[i].lenta_position + k].idxTI].iddatatype == IT::STR)
								BODY_FUNCT_5_2_0;
						}
		     		}
		     		break;
					case 6: //N->vti=E;N
						BODY_FUNCT_8_0_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position + 2].idxTI].id);
						break; 
					case 7: //N->vti=E;
						BODY_FUNCT_9_0_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position + 2].idxTI].id);
						break;
		     		break;
		     		}
				}
				break;
			case 3: // выражения
				if (strstr(line, FLAG_E))
				{
					strcpy(help, strstr(line, FLAG_E));
					memset(strstr(line, FLAG_E), NULL, strlen(FLAG_E));
					switch (st._Get_container()[i].nrulechain)
					{
					case 0: // E->i
						if (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].idtype != IT::F)
						{
							if (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].iddatatype == IT::INT
								|| (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].idtype == IT::P ||
                /*добавил*/			idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].idtype == IT::V &&
									idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].iddatatype == IT::STR))
								strcpy(buff, idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);							
							else
								if (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].iddatatype == IT::STR)
									EXPRESSION_0_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						}
						else EXPRESSION_0_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						break;
					case 1: // E->l
						if (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].iddatatype == IT::INT)
							strcpy(buff, idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						else if (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].iddatatype == IT::STR)
							EXPRESSION_0_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						else
							EXPRESSION_0_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						break;
					case 2: //E->iE
						if (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].idtype != IT::F)
						{
							if (idtable.table[lextable.table[st._Get_container()[i + 1].lenta_position].idxTI].idtype != IT::F)
								EXPRESSION_2_0_0_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
							else
								EXPRESSION_2_0_1_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						}
						else
							EXPRESSION_2_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id); // call 
						break;
					case 3: //E->lE
						if (idtable.table[lextable.table[st._Get_container()[i + 1].lenta_position].idxTI].idtype != IT::F)
							if(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].iddatatype != IT::STR)
								EXPRESSION_2_0_0_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
							else 
								EXPRESSION_2_0_0_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						else
							if(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].iddatatype != IT::STR)
								EXPRESSION_2_0_1_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
							else EXPRESSION_2_0_1_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						break;
					case 4: //E->iM
					case 5: //E->lM
						if (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].idtype != IT::F)
							EXPRESSION_4_0(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id);
						else
							EXPRESSION_4_1(idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id); // call 
						break;
					}
				}
				break;
			case 4: // Знаки
				if (strstr(line, FLAG_M))
				{
					strcpy(help, strstr(line, FLAG_M));
					memset(strstr(line, FLAG_M), NULL, strlen(FLAG_M));
					if (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].iddatatype == IT::INT)
					{
						switch (idtable.table[lextable.table[st._Get_container()[i].lenta_position].idxTI].id[0])
						{
						case '+': strcpy(buff, OPERATION_PLUS); break;//pop eax pop ebx add eax,ebx push eax 
						case '-': strcpy(buff, OPERATION_MINUS); break;
						case '*': strcpy(buff, OPERATION_MUL); break;
						case '/': strcpy(buff, OPERATION_DIV); break;
						}
					}
					switch (st._Get_container()[i].nrulechain)
					{
					case 0: break;
					case 1: CONCAT(buff, "\n ;M"); break;
					case 2: CONCAT(buff, "\n push ;E\n ;M"); break;
					}
				}
				break;
			default:
				break;
			}
			CONCAT(CONCAT(line, buff), help + 2);
			memset(help, NULL, strlen(help));
			fprintf(file,"\n\n--------------------------------\n\n%s", line);
		}
		delete[] buff, help;
		st.~stack();
		fclose(file);
	}
	void Generation(Parm::PARM parm, IT::IdTable idtable, LT::LexTable lextable, std::stack<MFST::MfstState>& st)
	{
		char* line (Create_Assembly_Line());
		Create_Head_of_Assembly(line);
		Create_Proto_Functions_of_Assembly(line, idtable);
		Create_Const_of_Assembly(line, idtable);
		Create_Data_of_Assembly(line, idtable);
		Create_Code(fopen(Log::From_UTF_to_ASCII(parm.generation), "w"),line, idtable, lextable, st);
		FILE* file = fopen(Log::From_UTF_to_ASCII(parm.out), "w");
		fprintf(file,"%s",line);
		fclose(file);
		delete[] line;
	}
}