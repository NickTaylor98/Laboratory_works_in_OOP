#include "stdafx.h"
#define IN_ID TOTAL_KA-8 // TOTAL_KA == ���-�� ���������
namespace P
{
	START_FSATable // ������ ��������� (in FST.h)
		_INT,
		_STR,
		_FUNCTION,
		_VAR,
		_RETURN,
		_OUT,
		_SEMICOLON,
		_COMMA,
		_LEFTBRACE,
		_BRACELET,
		_LEFTTHESIS,
		_RIGHTTHESIS,
		_EQUAL,
		_PLUS,
		_MINUS,
		_STAR,
		_DIRSLASH,
		_MAIN,
		_LITERAL_1,
		_LITERAL_2,
		_ID
	FINISH_FSATable
	void add(char* &buff, int &temp, In::element &ml, char current, Log::LOG log) // �������� � ���������
	{
		buff[temp++] = current; // ���������� ������� ������
		buff[temp] = 0x00;      // ����� ������
		temp = 0;               // ��������
		ml.mtxt[ml.msize] = new char[strlen(buff) + 1];
		strcpy(ml.mtxt[ml.msize++], buff); // ������
	}
	In::element split(In::element el, In::IN in, Log::LOG log) // ����������
	{
		In::element ml;
		ml.msize = 0;
		ml.mtxt = new char*[MAX_EL]; //
		int i(0), temp(0);
		char* buff = new char[MAX_EL];
		char current, next;
		bool r = true;
		while (el.txt[i] != 0x00)
		{
			bool I = true; // if true, then write current symbol
			current = el.txt[i]; next = el.txt[i + 1];
			if (in.code[current] == in.R) //  R - "
			{
				if (!r) { // ����� ��������� " �� 2-�� ���, �� ���������� ����� �� " �� " � ���������
					add(buff, temp, ml, current, log);
					I = false;
				}
				r = !r;
			}
			if (r)
			{ // T - ����������� ������
				if (in.code[current] == in.T) // ���������� �����
				{
					switch (in.code[next]) // ���� ��������� ������: ���������, ������ ��� | , ��:
					{
					case in.S: 
					case in.O: 
					case in.P: add(buff, temp, ml, current, log); I = false; break; // ���������� � ���������
					}
					if (next == 0x00)
					{
						add(buff, temp, ml, current, log); 
						I = false;
					}
				}
				switch (in.code[current]) // ���� ������� ��������� ��� |, ��:
				{
				case in.O: I = false; break;
				case in.S: 
				case in.P: add(buff, temp, ml, current, log); I = false; break; // ���������� � ���������
				}
			}
			if (I) buff[temp++] = current; // ������ ��������
			i++;
		}
		/*puts("\n\n\t\t���������� split : \n");						// ����� � �������
		for (int k(0); k < ml.msize; k++)							    // ����� � �������
		printf("%s\n",ml.mtxt[k]);									    // ����� � �������*/
		return ml;
	}
	void output_Split(Log::LOG log, In::element ml)
	{
		Log::WriteLine(log, "\n\n\t\t���������� split : \n", "");
		int k(0);
		while(k < ml.msize) 
			Log::WriteLine(log, Log::From_Int_To_String(k), " ", ml.mtxt[k++], IN_CODE_ENDL, "");
	}
	In::element deleterp(In::IN in) // �������� ������ ��������
	{
		In::element el; // ������������ ���������
		int i(0), n(-1);
		el.size = -1;
		el.txt = new char[in.size];
		bool r = true, IF_DEL_SPACE;
		char current, next;
		for (int i(0); i <= in.size; i++)
		{
			IF_DEL_SPACE = false; // if false, then write current symbol
			current = in.text[i]; next = in.text[i + 1]; // ��������� current - ������� ������, next - ���������
			in.code[current] == in.R ? r = !r : r;     // R - " ; ����� r == true, r = !true => r = false ; ���������� �������� �� 
			if (r)                                                                                                // ������ ������� � " "
			{
				switch (in.code[current]) // ��������, ����� �� ������ ������
				{
				case in.O:  // O - ������
					switch (in.code[next])
					{
					case in.O:							   // ������� �� ��������� ������
					case in.S:	IF_DEL_SPACE = true; break;// ������ ������ ����� �����������
					}											// S - ����������, P - | (������ ��������� ������). 							        	 
					if (in.code[el.txt[el.size]] == in.S || //������ ������ ����� ����������
						el.size < 0 ||                      //������ ������ � ������ ������ ������
						in.code[el.txt[el.size]] == in.P) IF_DEL_SPACE = true; // ������ ������ � ������ ����� (�� �������� ��� 1-��)
					break;
				case in.P: if (in.code[next] == in.P)      IF_DEL_SPACE = true; break;
				} 
			}
			if (!IF_DEL_SPACE) el.txt[++el.size] = current;  // ���������� ������ � ���������
		}
		el.txt[++el.size] = 0x00;
		//printf("\n\t\t���������� deleterp : \n\n%s\n", el.txt);					// ����� � �������
		return el;
	}
	void output_Delete_Probel(Log::LOG log, In::element elem)
	{
		Log::WriteLine(log, "\n\t\t���������� deleterp : \n\n", elem.txt, IN_CODE_ENDL, "");
	}
	int Search(IT::IdTable idtable, IT::IDTYPE type)
	{
		int rc(idtable.size);
		while (rc >= 0 && idtable.table[rc].idtype != type) rc--;
		return rc;
	}
	IT::IDDATATYPE Search(LT::LexTable& lextable, IT::IdTable& idtable, char lexema)
	{
		int rc(lextable.size - 1);
		while (rc >= 0 && lextable.table[rc].lexema != lexema) rc--;
		return idtable.table[lextable.table[--rc].idxTI].iddatatype;
	}
	bool Operator(bool& check, LT::Entry& LT_struct, IT::Entry& IT_struct, char lexema_from_fsa, char to_change, FST::FSA fsa, int& i)
	{
		bool rc1 = false;
		if (fsa.lexema == to_change) // '+' , '-', '*', '/'
		{
			IT_struct.id_buf[0] = to_change; IT_struct.id_buf[1] = 0x00;
			IT_struct.id[0] = lexema_from_fsa; IT_struct.id[1] = 0x00;
			IT_struct.idtype = IT::O;
			IT_struct.idxfirstLE = LT_struct.sn;
			IT_struct.iddatatype = IT::INT;
			rc1 = check = true;
		}
		return rc1;
	}
	bool checkExpression(FST::FSA fsa,LT::LexTable& lextable, LT::Entry &LT_struct, 
		                 IT::IdTable &idtable, IT::Entry &IT_struct, In::element ml,
		                 int i, std::stack<int>&PIN, bool& check, char* & range_of_vision,
		                 Log::LOG log)
	{
		fsa.setFSA(ml.mtxt[i]);
		bool rc = FST::execute(fsa.fst);
		if (rc)
		{
			LT_struct.lexema = fsa.lexema; // ������ ������������ �������
			LT_struct.pn = fsa.PN;
			LT_struct.idxTI = TI_NULLIDX;
			static bool in_brackets = false;
			if (fsa.lexema == LEX_LEFTTHESIS && idtable.table[idtable.size - 1].idtype == IT::F) in_brackets = !in_brackets;
			else if (fsa.lexema == LEX_RIGHTTHESIS && in_brackets) in_brackets = !in_brackets;
			else if (fsa.lexema == LEX_ID) // ���� �������������:
			{
				int k(0);
				SA::Create_Good_Id(ml.mtxt[i]);
				strcpy(IT_struct.id_buf, ml.mtxt[i]);
				if (!PIN.empty() && lextable.table[lextable.size-2].lexema != LEX_OUT) // ���. �������� ����� �������� ������ �����������
				{ // ���� ������ �� �� ����
					for (size_t i(PIN.size()); i > 0; i--)
					{
						switch (PIN.top()) // ������� ������� ������
						{
						case LT::PIN_VAR: IT_struct.is_var   = true; break;
						case LT::PIN_I: IT_struct.iddatatype = IT::INT;	  IT_struct.value.vint = TI_INT_DEFAULT; break;
						case LT::PIN_S: IT_struct.iddatatype = IT::STR;   IT_struct.value.vstr.len = TI_STR_DEFAULT; break;
						case LT::PIN_F: IT_struct.idtype     = IT::F; break;
						case LT::PIN_M: idtable.f_main       = true; break;
						}
						PIN.pop(); // ���������� �� ����� 
					}
					IT_struct.idxfirstLE = LT_struct.sn; // ���������� � �� ������ ������ ������� �������������� � ��
					LT_struct.idxTI = idtable.size; // ������� ������ �� == ����������� ������, �� ���� ����� ����� ��������� �� �� ��
					
					if (!IT_struct.is_var && IT_struct.idtype != IT::F && in_brackets) 
					{
						IT_struct.idtype = IT::P;
						CONCAT(strcpy(IT_struct.id, range_of_vision), IT_struct.id_buf);
						int k = Search(idtable, IT::F);
						if (k >= 0) idtable.table[k].number_of_param++;
						IT_struct.is_var = true;
					}
					if (IT_struct.idtype == IT::F && IT::IsId(log, idtable, IT_struct) == TI_NULLIDX)
					{
						IT_struct.is_var ? IT_struct.std_lib = true : IT_struct.std_lib = false;
						if (!idtable.f_main) strcpy(range_of_vision, strcpy(IT_struct.id, IT_struct.id_buf));
						else                 strcpy(IT_struct.id, IT_struct.id_buf);
						IT_struct.is_var = true;
					}
					if (IT_struct.idtype == IT::DEFT && IT_struct.is_var)
					{
						if (!strlen(range_of_vision)) 
							Log::WriteError(log, Error::geterror_id(125, IT_struct.id_buf, IT_struct.idxfirstLE));
						CONCAT(strcpy(IT_struct.id, range_of_vision), IT_struct.id_buf);
						IT_struct.idtype = IT::V;
					}
					if (IT_struct.iddatatype == IT::DEFD) SA::Unknown_Type(log, IT_struct);
					if (IT::IsId(log, idtable, IT_struct) != TI_NULLIDX) rc = false; //�������� �� ������������ ��������������
				}
				else if (PIN.empty() || lextable.table[lextable.size - 2].lexema == LEX_OUT)
				{
					if (ml.mtxt[i+1][0] != LEX_LEFTTHESIS) CONCAT(strcpy(IT_struct.id, range_of_vision),IT_struct.id_buf);
					else strcpy(IT_struct.id, IT_struct.id_buf);
					k = IT::IsId(log, idtable, IT_struct);//ml.mtxt[i]);
					if (k != TI_NULLIDX) // ���� ����� �� ���
					{
						LT_struct.idxTI = k; // ���������� ������ �� ��
						idtable.if_double_i = true; // ���� ������ true, ����� �� ��������� � ��
						IT_struct.is_var = true; // ���������� ��������� ����� �������� ������������
					}
				}
			}
			else
			{
				if (fsa.lexema == LEX_LITERAL) // ���� �������
				{

					LT_struct.idxTI = idtable.size;
					IT_struct.idxfirstLE = LT_struct.sn;
					IT_struct.idtype = IT::L;
					IT_struct.is_var = true; // �������� ������ �������� ������������
					memset(IT_struct.id_buf, NULL, ID_MAXSIZE);
					switch (fsa.CID)
					{
					case LT::LT_INT:
						IT_struct.iddatatype = IT::INT;
						IT_struct.value.vint = atoi(ml.mtxt[i]); // ���������� �������� �������� � ���������
						break;
					case LT::LT_STR:
					{
						IT_struct.iddatatype = IT::STR;
						IT_struct.value.vstr.len = strlen(ml.mtxt[i]) - 2; // ���������� ����� ������ ��� " "
						SA::Null_String(log, IT_struct);
						if (SA::Good_Literal(log, IT_struct))
						{
							memset(IT_struct.value.vstr.str, NULL, IT_struct.value.vstr.len + 1);
							memmove(IT_struct.value.vstr.str, ml.mtxt[i] + 1, IT_struct.value.vstr.len);
						}
						else { rc = false; i++; }
					} 
					break; 
					}
					int k = IT::IsLiteral(idtable, IT_struct);
					if (k != TI_NULLIDX)
					{
						LT_struct.idxTI = k;
						idtable.if_double_i = true;
					}
					else CONCAT(strcpy(IT_struct.id, "L"), Log::From_Int_To_String(idtable.IT_num++));
				}
				else if (fsa.lexema == LEX_MAIN)
					{
						strcpy(range_of_vision, strcpy(IT_struct.id, strcpy(IT_struct.id_buf, "main")));
						IT_struct.idtype = IT::M;
						IT_struct.idxfirstLE = LT_struct.sn;
						LT_struct.idxTI = idtable.size;
						IT_struct.iddatatype = IT::DEFD;
						IT_struct.is_var = true;
						if (!PIN.empty()) Log::WriteError(log, Error::geterrorin(108, IT_struct.idxfirstLE));
						PIN.push(fsa.CID);
					}
					else if (fsa.lexema == LEX_BRACELET || //������ ����������� ������ 
						(fsa.lexema == LEX_SEMICOLON && idtable.table[Search(idtable, IT::F)].std_lib) && !idtable.f_main) //����� ������� �� ����������� ���������
					{
						memset(range_of_vision, NULL, ID_MAXSIZE);
						while (!PIN.empty()) PIN.pop();
					}
				else if (Operator(check, LT_struct, IT_struct, ml.mtxt[i][0], LEX_PLUS, fsa, i))
				{
					int k = IT::IsId(log, idtable, IT_struct);
					if (k != TI_NULLIDX)
					{
						LT_struct.idxTI = k;
						idtable.if_double_i = true;
					}
					else
					{
						LT_struct.idxTI = idtable.size;
						LT::Add(lextable, LT_struct);
						IT::Add(idtable, IT_struct);
						if (lextable.table[lextable.size - 2].lexema == LEX_PLUS) 
							Log::WriteError(log, Error::geterrorin(120, IT_struct.idxfirstLE));
						rc = false;
					}
				}
				else if (fsa.CID != LT::PIN_DEF) PIN.push(fsa.CID); // ������� � ���� 
			}
		}
		return rc;
	}
	void output_LT(Log::LOG log, LT::LexTable lextable)
	{
		Log::WriteLine(log, "\n ������� ������ : \n\n", "");
		for (int k = 0; k < lextable.size; k++)
		{
			if (lextable.table[k].sn != lextable.table[k - 1].sn)
			{
				Log::WriteLine(log, IN_CODE_ENDL, "");
				lextable.table[k].sn < 10 ? Log::WriteLine(log, "0", Log::From_Int_To_String(lextable.table[k].sn), ":", ""): Log::WriteLine(log, Log::From_Int_To_String(lextable.table[k].sn), ":", "");
			}
			fprintf(log.stream, "%c",lextable.table[k].lexema); 
			if (lextable.table[k].lexema == 'i') Log::WriteLine(log, "[", Log::From_Int_To_String(lextable.table[k].idxTI), "]", "");
		}
		Log::WriteLine(log, "\n", "");
	}
	void output_IT(Log::LOG log, IT::IdTable idtable)
	{
		Log::WriteLine(log, "\n\n ������� ��������������� : \n\n", "");
		for (int k = 0; k < idtable.size; k++)
		{
			switch (idtable.table[k].iddatatype)
			{
			case IT::STR:
				switch (idtable.table[k].idtype)
				{
				case IT::F: Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " str F [", Log::From_Int_To_String(idtable.table[k].idxfirstLE), "]", IN_CODE_ENDL, ""); break;
				case IT::V: Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " str V [", Log::From_Int_To_String(idtable.table[k].idxfirstLE), "]", IN_CODE_ENDL, ""); break;
				case IT::P: Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " str P [", Log::From_Int_To_String(idtable.table[k].idxfirstLE), "]", IN_CODE_ENDL, ""); break;
				case IT::L: Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " str L = <", idtable.table[k].value.vstr.str, "> length = ", Log::From_Int_To_String((int)idtable.table[k].value.vstr.len), IN_CODE_ENDL, ""); break;
				case IT::O: Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " str operator [", Log::From_Int_To_String(idtable.table[k].idxfirstLE), "]", IN_CODE_ENDL, ""); break;
				}
				break;
			case IT::INT:
				switch (idtable.table[k].idtype)
				{
				case IT::F:Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " int F [", Log::From_Int_To_String(idtable.table[k].idxfirstLE), "]", IN_CODE_ENDL, ""); break;
				case IT::V:Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " int V [", Log::From_Int_To_String(idtable.table[k].idxfirstLE), "]", IN_CODE_ENDL, ""); break;
				case IT::P:Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " int P [", Log::From_Int_To_String(idtable.table[k].idxfirstLE), "]", IN_CODE_ENDL, ""); break;
			    case IT::L:Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " int L = ", Log::From_Int_To_String(idtable.table[k].value.vint), IN_CODE_ENDL, ""); break;
				case IT::O:Log::WriteLine(log, Log::From_Int_To_String(k), " : ", idtable.table[k].id, " int operator [", Log::From_Int_To_String(idtable.table[k].idxfirstLE), "]", IN_CODE_ENDL, ""); break;
				}
				break;
			}
		}
	}
	LEX Par(In::IN in, Log::LOG log, Parm::PARM parm)
	{
		LEX Tables;
		In::element el = deleterp(in);
		In::element ml = split(el, in, log);
		if (parm.All_Real) { output_Delete_Probel(log, el);  output_Split(log, ml); }
		int i(0), FSA_size(i);
		LT::Entry LT_struct; 
		Tables.Lextable = LT::Create(LT_MAXSIZE);
		IT::Entry IT_struct; 
		Tables.Idtable = IT::Create(ARR);
		bool check = false;
		std::stack<int>PIN; LT_struct.sn = 1;
		char * range_of_vision = new char[ID_MAXSIZE];
		memset(range_of_vision, NULL, ID_MAXSIZE);
		for (int i(0); i < ml.msize; i++)
		{
			Tables.Idtable.if_double_i = false;
			if (in.code[ml.mtxt[i][0]] == in.P) LT_struct.sn++;
			else
			{
				while (!check && FSA_size < TOTAL_KA)
				{
					if (checkExpression(FSATable[FSA_size], Tables.Lextable, LT_struct, Tables.Idtable,
						                IT_struct, ml, i, PIN, check, 
						                range_of_vision, log)) // ��������� �� ���������
					{
							LT::Add(Tables.Lextable, LT_struct); // ������ � ��
							if (FSA_size >= IN_ID && !Tables.Idtable.if_double_i)
								if (SA::If_Var_Id(log, LT_struct, IT_struct))
									IT::Add(Tables.Idtable, IT_struct); // ������ � ��
						check = true;
					}
					FSA_size++;
				}
			}
			check = false;
			IT_struct = IT::Entry();//{ IT::DEFD, IT::DEFT };
			FSA_size = 0;
		}
		LT_struct.lexema = '$';
		LT::Add(Tables.Lextable, LT_struct);
		i = Search(Tables.Idtable, IT::M);
		if (i >= 0) IT::Delete_Elem(Tables.Idtable, Tables.Lextable, i);
		SA::Good_Type_of_Operand(log, Tables.Lextable, Tables.Idtable);
		SA::Good_Return(log, Tables.Lextable, Tables.Idtable);
		if (parm.LT_log) output_LT(log, Tables.Lextable); // ����� � ���
		if (parm.ID_log && SA::Good_Braces(log, Tables.Lextable) && SA::Good_Param_of_Function(log, Tables.Lextable, Tables.Idtable))
			output_IT(log, Tables.Idtable);  // ����� � ���
		delete[] range_of_vision;
		return Tables;
	}
}
