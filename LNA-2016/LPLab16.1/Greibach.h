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
using GRBALPHABET = short; // символы алфавита грамматики терминалы > 0, нетерминалы < 0
namespace GRB
{
	struct Rule // правило в грамматике Грейбах
	{
		GRBALPHABET nn; // нетерминал (левый символ правила) < 0
		int iderror; // идентификатор диагностического сообщения
		short size; // количество цепочек - правых частей правила
		struct Chain // цепочка (правая часть правила)
		{
			short size; // длина цепочки
			GRBALPHABET* nt; // цепочка терминалов (>0) и нетерминалов (<0)
			Chain() { size = 0; nt = nullptr; };
			Chain(
				short psize, // количество символов в цепочка
				GRBALPHABET s, ... // символы (терминал или нетерминал)
				);
			char* getCChain(char* b); // получить правую сторону правила
			static GRBALPHABET T(char t) { return GRBALPHABET(t); }; // терминал
			static GRBALPHABET N(char n) { return GRBALPHABET(n) | 0x8000; }; // нетерминал
			static bool isT(GRBALPHABET s) { return s > 0; }; // терминал ?
			static bool isN(GRBALPHABET s) { return !isT(s); }; // нетерминал ?
			static char alphabet_to_char(GRBALPHABET s) { return isT(s) ? char(s) : char(s & 0x7fff); }; // GRBALPHABET->char
		}*chains; // массив цепочек - правых частей правила
		Rule() { nn = 0x00; size = 0; chains = nullptr; }
		Rule(
			GRBALPHABET pnn, // нетерминал (<0)
			int iderror, // идентификатор диагностического сообщения (Error)
			short psize, // количество цепочек - правых частей правила
			Chain c, ... // можество цепочек - правых частей правила 
			);
		char* getCRule( // получить правило в виде N->цепочка (для распечатки)
			char* b, // буфер
			short nchain // номер цепочки (правой части) в правиле
			);
		short Rule::getNextChain( // получить следующую за j подходязую цепочку, вернуть ее номер или -1
			GRBALPHABET t, // первый символ цепочки
			Rule::Chain& pchain, // возвращаемая цепочка
			short j // номер цепочки
			);
	};

	struct Greibach // грамматика Грейбах
	{
		short size; // количество правил
		GRBALPHABET startN; // стартовый символ
		GRBALPHABET stbottomT; // дно стека
		Rule* rules; // множество правил
		Greibach() { short size = 0; startN = 0; stbottomT = 0; rules = 0; };
		Greibach(
			GRBALPHABET pstartN, // стартовый символ
			GRBALPHABET pstbottom, // дно стека
			short psize, // количество правил
			Rule r, ... // правила
			);
		short getRule( // получить правило, возвращается номер правила или -1
			GRBALPHABET pnn, // левый символ правила
			Rule& prule // возвращаемое правило грамматики
			);
		Rule getRule(short n); // получить правило по номеру
	};
	Greibach getGreibach(); // получить грамматику
}