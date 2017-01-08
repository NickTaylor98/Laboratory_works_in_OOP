#pragma once
namespace SA
{
	void Create_Good_Id(char* &id); //������������� �������� �� ����� ��������������
	bool Good_Literal(Log::LOG log, IT::Entry& elem); //������������� �������� �� ����� ��������� ��������
	bool If_Var_Id(Log::LOG log, LT::Entry& lem, IT::Entry& elem); //������������� �������� �� ���������� ��������������
	void Unknown_Type(Log::LOG log, IT::Entry& elem); // ����������� ��� ��������������
	void Good_Type_of_Operand(Log::LOG log, LT::LexTable lextable, IT::IdTable idtable);
	bool Good_Braces(Log::LOG log, LT::LexTable& lextable); //������� ����������� ������������ ����������� ������ � ���������
	void Good_Return(Log::LOG log, LT::LexTable& lextable, IT::IdTable& idtable); // �������� �� ������������ ������������ ���� � ����� �������
	void Null_String(Log::LOG log, const IT::Entry& elem); //�������� �� ������ ������� �����
	bool Good_Param_of_Function(Log::LOG log, LT::LexTable& lextable, IT::IdTable& idtable); //�������� �� ���������� ���������� ����������
}