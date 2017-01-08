#pragma once
#define ID_MAXSIZE				 10			// ������������ ���������� �������� � ��������������
#define STR_LITERAL_MAXSIZE      255        // ������������ ����� �������� � �������� ��������
#define ID_WITH_PREFIX_MAXSIZE   20			// ������������ ���������� �������� � �������������� � ���������
#define TI_MAXSIZE				 4096		// ������������ ���������� ����� � ������� ���������������
#define TI_INT_DEFAULT			 0x00000000	// �������� �� ��������� ��� int
#define	TI_STR_DEFAULT			 0x00		// �������� �� ��������� ��� str
#define TI_NULLIDX				 0xffffffff  // ��� �������� ������� ���������������

namespace IT // ������� ���������������
{
	enum IDDATATYPE { DEFD = 0, INT = 1, STR = 2}; // ���� ������ ���������������
	enum IDTYPE     {             //���� ���������������
		              DEFT = 0,   // ����������
		                 V = 1,   // ����������
		                 P = 2,   // ��������
		                 F = 3,   // �������
		                 L = 4,   // �������
		                 M = 5,   // ������� �������
		                 O = 6	  // ��������
	                 }; 

	struct Entry
	{
		int idxfirstLE;				 // ������ ������ ������ � ������� ������
		char id_buf[ID_MAXSIZE];	 // ������������� ��� ��������
		char id[ID_WITH_PREFIX_MAXSIZE];	 // �������������
		bool is_var = false;		 // ��������� ������ �������
		IDDATATYPE iddatatype;		 // ��� ������
		IDTYPE idtype;				 // ��� ��������������
		union
		{
			int vint;            // �������� int
			struct
			{
				unsigned int len;                       // ���������� �������� � str
				char str[STR_LITERAL_MAXSIZE - 1]; // ������� str
			} vstr;							  // �������� str
		} value;							  // �������� ��������������
		bool std_lib;                         // ������� ����������� ����������
		int number_of_param;                  // ����� ���������� (��� �������) 
		Entry() { iddatatype = DEFD; idtype = DEFT; idxfirstLE = 0;  number_of_param = 0;};
	};

	struct IdTable
	{
		bool if_double_i = false;
		int IT_num = 0;
		bool f_main = false;
		int maxsize; // ������� ��
		int size; // ������� ������ ��
		Entry* table; //  ������ ����� ��
	};

	IdTable Create // ������� ��
		(
			int size // ������� ��
			);
	void Add( // �������� ������ � ��
		IdTable&idtable, // ��������� ��
		Entry entry // ������ ��
		);
	Entry GetEntry( // �������� ������ ��
		IdTable& idtable, // ��������� ��
		int n // ����� ���������� ������
		);
	/*int IsId(
		IdTable& idtable, // ��������� ��
		char id[ID_MAXSIZE] // �������������
		);*/
	int IsId(Log::LOG, IdTable& idtable, IT::Entry id);
	int IsLiteral(IdTable& idtable, IT::Entry elem);
	void Delete_Elem(IdTable& idtable, LT::LexTable& lextable, int index);
	void Delete(IdTable& idtable);
}