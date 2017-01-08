#pragma once
//#define LEXEMA_FIXSIZE 1 // ������������� ������ �������
#define	LT_MAXSIZE 4096 // ������������ ���-�� ����� � �������
#define LT_TI_NULLIDX 0xffffffff // ��� �������� TL
#define LEX_INT				't'
#define	LEX_STR			    't'

#define LEX_ID				'i'
#define LEX_LITERAL			'l'

#define LEX_FUNCTION		'f'
#define LEX_VAR				'v'
#define LEX_RETURN			'r'
#define LEX_OUT			    'O'
#define LEX_MAIN			'm'

#define LEX_SEMICOLON		';'
#define	LEX_COMMA			','
#define LEX_LEFTBRACE		'{'
#define LEX_BRACELET		'}'
#define LEX_LEFTTHESIS	    '('
#define	LEX_RIGHTTHESIS		')'
#define LEX_PLUS			'o'
#define LEX_MINUS			'o'
#define LEX_STAR			'o'
#define LEX_DIRSLASH		'o'
#define LEX_EQUAL			'='


namespace LT // ������� ������
{
	enum Priority { PN_DEFAULT, PN_LEFTTHESIS, PN_PLUS, PN_MINUS = 2, PN_STAR, PN_DIRSLASH = 3 }; // priority
	enum Let { LT_INT = 1, LT_STR = 2, LT_BOOL = 3 }; // for type of lexem
	enum Pin { PIN_DEF = 0, PIN_I = 1, PIN_S = 2, PIN_F = 3, PIN_M = 4, PIN_B = 5 }; // type of identifier
	enum Var { PIN_VAR = 6 }; // for var
	struct Entry
	{
		char lexema; // �������
		int sn; // ����� ������
		int idxTI; // ������ � ��
		int pn; // ���������
	};

	struct LexTable
	{
		int maxsize; // ������� ��
		int size; // ������� ������ ��
		Entry* table; // ������ ����� ��
	};

	LexTable Create( // ������� ��
		int size // ������� ��
		);
	void Add( // �������� ������ � ��
		LexTable& lextable, // ��������� ��
		Entry entry // ������ ��
		);
	Entry GetEntry( //  �������� ������ ��
		LexTable& lextable, //  ��������� ��
		int n // ����� ���������� ������
		);
	void Delete(LexTable& lextable);
	void Delete_Elem(LexTable&, char);
}