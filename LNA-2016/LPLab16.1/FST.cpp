#include "stdafx.h"
#define IN_CODE_ENDL 0x0A
#define IN_STR_ENDL "\n"
#define IN_STR_LET '"'
#define IN_CODE_SPASE 0x20
#define IN_CODE_SEMICOLON ';'
#define IN_SIZE 1024*1024

namespace FST
{
	RELATION::RELATION(char c, short ns) : symbol(c), nnode(ns) { }

	NODE::NODE() {}
	NODE::NODE(short n, RELATION rel, ...)
	{
		RELATION* current = &rel;
		relations = new RELATION[n_relation = n];
		for (int i = 0; i < n; i++) relations[i] = current[i];
	}

	FST::FST() { }

	FST::FST(char* s, short ns, NODE n, ...)
	{
		string = s;
		errors = 0;
		NODE* current = &n;
		nodes = new NODE[nstates = ns];
		for (int i = 0; i < ns; i++) nodes[i] = current[i];
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short)*nstates);
		rstates[0] = 0;
		position = -1;
	}

	FSA::FSA() { }

	FSA::FSA(FST f, char l, int n, int pr) : fst(f), lexema(l), CID(n), PN(pr) { }

	void FSA::setFSA(char* s) 
	{
		this->fst.position = -1;
		this->fst.string = s;
		this->fst.rstates[0] = 0;
	}

	bool step(FST& fst, short* &cur_states)
	{
		bool rc = false;
		std::swap(cur_states, fst.rstates);
		for (short i = 0; i < fst.nstates; i++)
		{
			if (cur_states[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						//Log::WriteErrorCL(Error::geterror(111));
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						fst.errors = fst.position;
						rc = true;
					}
				}
		}
		return rc;
	}

	bool execute(FST& fst)
	{
		bool rc = true;
		short* cur_states = new short[fst.nstates];
		memset(cur_states, 0xff, sizeof(short)*fst.nstates);
		short str_len = strlen(fst.string);
		for (short i = 0; i < str_len && rc; i++)
		{
			fst.position++;
			rc = step(fst, cur_states);
		}
		return (rc ? (fst.rstates[fst.nstates - 1] == str_len) : rc);
	}
}