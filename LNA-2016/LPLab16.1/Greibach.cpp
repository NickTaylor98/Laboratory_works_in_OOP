#include "stdafx.h"
#define GRB_ERROR_SERIES 600
#define MAX_SIZE_FOR_GRB_RULE 200
namespace GRB
{
#define NS(n) Rule::Chain::N(n)
#define TS(n) Rule::Chain::T(n)
Greibach greibach(NS('S'), TS('$'), 6,
		Rule(NS('S'), GRB_ERROR_SERIES, 7,   //  Структура программы
			Rule::Chain(9, TS('v'), TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';'), NS('S')),
			Rule::Chain(13, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), NS('S')),
			Rule::Chain(14, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(9, TS('m'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}')),
			Rule::Chain(10, TS('m'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), NS('S')),
			Rule::Chain(13, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S'))
		),
		Rule(NS('F'), GRB_ERROR_SERIES + 1, 2,
			Rule::Chain(2, TS('t'), TS('i')),   // параметры ф-ии
			Rule::Chain(4, TS('t'), TS('i'), TS(','), NS('F'))
		),
		Rule(NS('N'), GRB_ERROR_SERIES + 2, 8,  // возможные конструкции в ф-иях
			Rule::Chain(5, TS('v'), TS('t'), TS('i'), TS(';'), NS('N')),                         //0
			Rule::Chain(4, TS('v'), TS('t'), TS('i'), TS(';')),									 //1
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('N')),						 //2
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),									 //3
			Rule::Chain(4, TS('O'), NS('E'), TS(';'), NS('N')),				                     //4
			Rule::Chain(3, TS('O'), NS('E'), TS(';')),						                     //5
			Rule::Chain(7, TS('v'), TS('t'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')),		 //6
			Rule::Chain(6, TS('v'), TS('t'), TS('i'), TS('='), NS('E'), TS(';'))				 //7
		),
		Rule(NS('E'), GRB_ERROR_SERIES + 3, // выражения
			6,
		Rule::Chain(1, TS('i')),
		Rule::Chain(1, TS('l')),
		Rule::Chain(2, TS('i'), NS('E')),
		Rule::Chain(2, TS('l'), NS('E')),
		Rule::Chain(2, TS('i'), NS('M')),
		Rule::Chain(2, TS('l'), NS('M'))
	),
	Rule(NS('M'), GRB_ERROR_SERIES + 4, 3, // знаки
		Rule::Chain(1, TS('o')),
		Rule::Chain(2, TS('o'), NS('M')),
		Rule::Chain(3, TS('o'), NS('E'), NS('M'))
	)
);

	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)
	{
		nt = new GRBALPHABET[size = psize];
		int* p = (int*)&s;
		for (short i(0); i < psize; ++i)
			nt[i] = /*(GRBALPHABET)*/p[i] & 0xffff;
	};
	Rule::Rule(GRBALPHABET pnn, int piderror, short psize, Chain c, ...)
	{
		nn = pnn;
		iderror = piderror;
		chains = new Chain[size = psize];
		Chain* p = &c;
		for (int i(0); i < size; i++)
			chains[i] = p[i];
	};
	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottom, short psize, Rule r, ...)
	{
		startN = pstartN;
		stbottomT = pstbottom;
		rules = new Rule[size = psize];
		Rule* p = &r;
		for (int i(0); i < size; i++)
			rules[i] = p[i];
	};

	Greibach getGreibach()
	{
		return greibach;
	};

	short Greibach::getRule(GRBALPHABET pnn, Rule& prule)
	{
		short rc = -1, k = 0;
		while (k < size && rules[k].nn != pnn)
			k++;
		if (k < size)
			prule = rules[rc = k];
		return rc;
	};

	Rule Greibach::getRule(short n)
	{
		Rule rc;
		if (n < size) rc = rules[n];
		return rc;
	};

	char* Rule::getCRule(char* b, short nchain) // получить правило в виде N->цепочка
	{
		char* bchain = new char[MAX_SIZE_FOR_GRB_RULE];
		b[0] = Chain::alphabet_to_char(nn);	b[1] = '-'; b[2] = '>'; b[3] = 0x00;
		chains[nchain].getCChain(bchain);
		CONCAT(b,bchain);
		delete[] bchain;
		return b;
	};

	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j)
	{
		short rc = -1;
		while (j < size && chains[j].nt[0] != t) ++j;
		rc = (j < size ? j : -1);
		if (rc >= 0) pchain = chains[rc];
		return rc;
	};

	char* Rule::Chain::getCChain(char* b) // получить правую сторону правила
	{
		for (int i(0); i < size; i++) 
			b[i] = Chain::alphabet_to_char(nt[i]);
		b[size] = 0x00;
		return b;
	};
}