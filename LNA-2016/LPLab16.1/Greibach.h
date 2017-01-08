#pragma once
#include "stdafx.h"

#define NS(n)		     GRB::Rule::Chain::N(n)
#define TS(n)		     GRB::Rule::Chain::T(n)
#define ISNS(n)		     GRB::Rule::Chain::isN(n)
//#define MFST_TRACE1		 printf("%-6d: %-20s%-30s%-20s\n",++FST_TRACE_n,rule.getCRule(rbuf,nrulechain),getCLenta(lbuf,lenta_position),getCSt(sbuf));
#define MFST_TRACE1(file)	 fprintf(file, "%-6d: %-20s%-30s%-20s\n",++FST_TRACE_n,rule.getCRule(rbuf,nrulechain),getCLenta(lbuf,lenta_position),getCSt(sbuf));
//#define MFST_TRACE2		 printf("%-6d: %-20c%-30s%-20s\n",FST_TRACE_n, ' ',getCLenta(lbuf,lenta_position),getCSt(sbuf));
#define MFST_TRACE2(file)		 fprintf(file, "%-6d: %-20c%-30s%-20s\n",FST_TRACE_n, ' ',getCLenta(lbuf,lenta_position),getCSt(sbuf));
//#define MFST_TRACE3		 printf("%-6d: %-20c%-30s%-20s\n",++FST_TRACE_n, ' ',getCLenta(lbuf,lenta_position),getCSt(sbuf));
#define MFST_TRACE3(file)	 fprintf(file, "%-6d: %-20c%-30s%-20s\n",++FST_TRACE_n, ' ',getCLenta(lbuf,lenta_position),getCSt(sbuf));
//#define MFST_TRACE4(c)	 printf("%-6d: %-20s\n",++FST_TRACE_n, c);
#define MFST_TRACE4(file, c)	 fprintf(file, "%-6d: %-20s\n",++FST_TRACE_n, c);
//#define MFST_TRACE5(c)	 printf("%-6d: %-20s\n", FST_TRACE_n, c);
#define MFST_TRACE5(file, c)	 fprintf(file, "%-6d: %-20s\n", FST_TRACE_n, c);
//#define MFST_TRACE6(c,k) printf("%-6d: %-20s%d\n", FST_TRACE_n, c, k);
#define MFST_TRACE6(file, c,k) fprintf(file, "%-6d: %-20s%d\n", FST_TRACE_n, c, k);
//#define MFST_TRACE7            printf("%-6d: %-20s\n", state.lenta_position, rule.getCRule(rbuf,state.nrulechain));
#define MFST_TRACE7(file)      fprintf(file, "%-6d: %-20s\n", state.lenta_position, rule.getCRule(rbuf,state.nrulechain));
using GRBALPHABET = short; // ������� �������� ���������� ��������� > 0, ����������� < 0
namespace GRB
{
	struct Rule // ������� � ���������� �������
	{
		GRBALPHABET nn; // ���������� (����� ������ �������) < 0
		int iderror; // ������������� ���������������� ���������
		short size; // ���������� ������� - ������ ������ �������
		struct Chain // ������� (������ ����� �������)
		{
			short size; // ����� �������
			GRBALPHABET* nt; // ������� ���������� (>0) � ������������ (<0)
			Chain() { size = 0; nt = nullptr; };
			Chain(
				short psize, // ���������� �������� � �������
				GRBALPHABET s, ... // ������� (�������� ��� ����������)
				);
			char* getCChain(char* b); // �������� ������ ������� �������
			static GRBALPHABET T(char t) { return GRBALPHABET(t); }; // ��������
			static GRBALPHABET N(char n) { return GRBALPHABET(n) | 0x8000; }; // ����������
			static bool isT(GRBALPHABET s) { return s > 0; }; // �������� ?
			static bool isN(GRBALPHABET s) { return !isT(s); }; // ���������� ?
			static char alphabet_to_char(GRBALPHABET s) { return isT(s) ? char(s) : char(s & 0x7fff); }; // GRBALPHABET->char
		}*chains; // ������ ������� - ������ ������ �������
		Rule() { nn = 0x00; size = 0; chains = nullptr; }
		Rule(
			GRBALPHABET pnn, // ���������� (<0)
			int iderror, // ������������� ���������������� ��������� (Error)
			short psize, // ���������� ������� - ������ ������ �������
			Chain c, ... // �������� ������� - ������ ������ ������� 
			);
		char* getCRule( // �������� ������� � ���� N->������� (��� ����������)
			char* b, // �����
			short nchain // ����� ������� (������ �����) � �������
			);
		short Rule::getNextChain( // �������� ��������� �� j ���������� �������, ������� �� ����� ��� -1
			GRBALPHABET t, // ������ ������ �������
			Rule::Chain& pchain, // ������������ �������
			short j // ����� �������
			);
	};

	struct Greibach // ���������� �������
	{
		short size; // ���������� ������
		GRBALPHABET startN; // ��������� ������
		GRBALPHABET stbottomT; // ��� �����
		Rule* rules; // ��������� ������
		Greibach() { short size = 0; startN = 0; stbottomT = 0; rules = 0; };
		Greibach(
			GRBALPHABET pstartN, // ��������� ������
			GRBALPHABET pstbottom, // ��� �����
			short psize, // ���������� ������
			Rule r, ... // �������
			);
		short getRule( // �������� �������, ������������ ����� ������� ��� -1
			GRBALPHABET pnn, // ����� ������ �������
			Rule& prule // ������������ ������� ����������
			);
		Rule getRule(short n); // �������� ������� �� ������
	};
	Greibach getGreibach(); // �������� ����������
}