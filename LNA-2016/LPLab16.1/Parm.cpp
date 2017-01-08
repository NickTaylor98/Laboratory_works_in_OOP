#include "stdafx.h"
#define CONCAT(x,y) wcsncat_s(x, PARM_MAX_SIZE, y, 5)

namespace Parm
{ // ID - подстрока
	int Search(int argc, _TCHAR* argv[], _TCHAR* Type)
	{
		int l = 1;
		while (l < argc && !wcsstr(argv[l], Type)) l++;
		return l < argc? l: -1;
	}
	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM rc;
		if (argc < 2) throw ERROR_THROW(100);
		for (int i = 1; i < argc; i++) if (wcslen(argv[i]) > PARM_MAX_SIZE) throw ERROR_THROW(104);
		int l = Search(argc, argv, PARM_IN);
		if (l == argc) throw ERROR_THROW(100);
		wcscpy_s(rc.in, argv[l] + 4);
		wcscpy_s(rc.out, argv[l] + 4); CONCAT(rc.out, PARM_OUT_DEFAULT_EXT);
		wcscpy_s(rc.log, argv[l] + 4); CONCAT(rc.log, PARM_LOG_DEFAULT_EXT);
		wcscpy_s(rc.sintax, argv[l] + 4); wcsncat(rc.sintax, PARM_SINTAX_DEFAULT_EXT, wcslen(PARM_SINTAX_DEFAULT_EXT));
		wcscpy_s(rc.generation, argv[l] + 4); wcsncat(rc.generation, PARM_GENER_DEFAULT_EXT, wcslen(PARM_GENER_DEFAULT_EXT));
		l = Search(argc, argv, PARM_SIN_AN); if (l>0)       wcscpy_s(rc.sintax, argv[l] + wcslen(PARM_SIN_AN));
		l = Search(argc, argv, PARM_GENER); if (l>0)       wcscpy_s(rc.generation, argv[l] + wcslen(PARM_GENER));
		l = Search(argc, argv, PARM_OUT); if (l > 0)		wcscpy_s(rc.out, argv[l] + 5);
		l = Search(argc, argv, PARM_LOG); if (l > 0)		wcscpy_s(rc.log, argv[l] + 5);
		l = Search(argc, argv, PARM_LOG_ID); if (l > 0)		rc.LT_log = false;
		l = Search(argc, argv, PARM_LOG_LT); if (l > 0)		rc.ID_log = false;
		l = Search(argc, argv, PARM_NOT_SHOW); if (l > 0)	rc.LT_log =  rc.ID_log = false;
		l = Search(argc, argv, PARM_ALL_REALIZATION); if (l > 0) rc.All_Real = true;
		return rc;
	}
}