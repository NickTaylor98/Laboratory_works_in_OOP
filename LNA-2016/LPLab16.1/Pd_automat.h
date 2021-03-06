#pragma once
#include "stdafx.h"
#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3

using MFSTSTSTACK = std::stack<short>; // ���� ��������
//#define MFST_TRACE_START puts("��� : �������             ������� �����                 ����");
//#define MFST_TRACE_START printf("%-6s: %-20s%-30s%-20s\n", "���", "�������", "������� �����", "����");
#define MFST_TRACE_START(x) fprintf(x, "\n%-6s: %-20s%-30s%-20s\n", "���", "�������", "������� �����", "����");
namespace MFST
{
	struct MfstState // ��������� ��������
	{
		short lenta_position; // ������� �� �����
		short nrule;          // ����� �������� �������
		short nrulechain;     // ����� ������� �������, �������� �������
		MFSTSTSTACK st;       // ���� ��������
		MfstState();
		MfstState(
			short pposition,  // ������� �� �����
			MFSTSTSTACK pst,  // ���� �������� 
			short pnrulechain // ����� ������� �������, �������� �������
			);
		MfstState(
			short pposition, // ������� �� �����
			MFSTSTSTACK pst, // ���� ��������
			short pnrule, // ����� �������� �������
			short pnrulechain // ����� ������� �������, �������� �������
			);
	};
	struct Mfst // ���������� �������
	{
		enum RC_STEP { // ��� �������� ������� step
			NS_OK, // ������� ������� � �������, ������� �������� � ����
			NS_NORULE, // �� ������� ������� ���������� (������ � ����������)
			NS_NORULECHAIN, //�� ������� ���������� ������� ������� (������ � �������� ����)
			NS_ERROR, // ����������� �������������� ������ ����������
			TS_OK, // ���.������ ����� == ������� �����, ������������ �����, pop �����
			TS_NOK, // ���.������ ����� != ������� �����, �������������� ���������
			LENTA_END, // ������� ������� ����� >= lenta_size
			SURPRISE // ����������� ��� �������� (������ � step)
		};
		struct MfstDiagnosis // �����������
		{
			short lenta_position; // ������� �� �����
			RC_STEP rc_step; // ��� ���������� ����
			short nrule; // ����� �������
			short nrule_chain; // ����� ������� �������
			MfstDiagnosis();
			MfstDiagnosis( // �����������
				short plenta_position, // ������� �� �����
				RC_STEP prc_step, // ��� ���������� ����
				short pnrule, // ����� �������
				short pnrule_chain // ����� ������� �������
				);
		} diagnosis[MFST_DIAGN_NUMBER]; // ��������� ����� �������� ���������

		GRBALPHABET* lenta; // ���������������� (TS/NS) ����� (�� LEX)
		short lenta_position; // ������� ������� �� �����
		short nrule; // ����� �������� �������
		short nrulechain; // ����� ������� �������, �������� �������
		short lenta_size; // ������ �����
		GRB::Greibach grebach; // ���������� �������
		P::LEX lex;
		MFSTSTSTACK st; // ���� ��������
		std::stack<MfstState> storestate; // ���� ��� ���������� ���������
		Mfst();
		Mfst(
			P::LEX plex, // ��������� ������ ������������ �����������
			GRB::Greibach pgrebach // ���������� �������
			);
		char* getCSt(char* buf); // �������� ���������� �����
		char* getCLenta(char* buf, short pos, short n = 25); // �����: n �������� � pos
		char* getDiagnosis(short n, char* buf); // �������� n-�� ������ ����������� ��� 0x00
		bool savestate(FILE* file); // ��������� ��������� ��������
		bool restate(FILE* file); // ������������ ��������� ��������
		bool push_chain( // ��������� ������� ������� � ����
			GRB::Rule::Chain chain // ������� �������
			);
		RC_STEP step(FILE* file); // ��������� ��� ��������
		bool start(FILE* file); // ��������� �������
		bool savediagnosis(
			RC_STEP pprc_step // ��� ���������� ����
			);
		void printrules(FILE* file); // ������ ������������������ ������

		struct Deducation // �����
		{
			short size; // ���������� ����� � ������
			short* nrules; // ����� ������ ����������
			short* nrulechains; // ������ ������� ������ ���������� (nrules)
			Deducation() { size = 0; nrules = 0; nrulechains = 0; };
		} deducatuon;
		bool savededucation(); // ��������� ������ ������
	};
};