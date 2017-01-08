#pragma once
namespace SA
{
	void Create_Good_Id(char* &id); //семантическа€ проверка на длину идентификатора
	bool Good_Literal(Log::LOG log, IT::Entry& elem); //семантическа€ проверка на длину строчного литерала
	bool If_Var_Id(Log::LOG log, LT::Entry& lem, IT::Entry& elem); //семантическа€ проверка на объ€вление идентификатора
	void Unknown_Type(Log::LOG log, IT::Entry& elem); // неизвестный тип идентификатора
	void Good_Type_of_Operand(Log::LOG log, LT::LexTable lextable, IT::IdTable idtable);
	bool Good_Braces(Log::LOG log, LT::LexTable& lextable); //функци€ определени€ правильности расстановки скобок в выражении
	void Good_Return(Log::LOG log, LT::LexTable& lextable, IT::IdTable& idtable); // проверка на соответствие возращаемого типа с типом функции
	void Null_String(Log::LOG log, const IT::Entry& elem); //проверка на строку нулевой длины
	bool Good_Param_of_Function(Log::LOG log, LT::LexTable& lextable, IT::IdTable& idtable); //проверка на правильное количество параметров
}