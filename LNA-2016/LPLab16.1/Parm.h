#pragma once
#define PARM_IN	L"-in:" // ���� ��� ����� ��������� ����
#define PARM_OUT L"-out:" // ���� ��� ����� ���������� ����
#define PARM_SIN_AN L"-sintan:" // key for file of sintax analyse
#define PARM_GENER L"-gener:" // key for file of generation
#define PARM_LOG_LT L"-lt" // key for showing only lexem table
#define PARM_LOG_ID L"-id" // key for showing only id table
#define PARM_NOT_SHOW L"-not_show" // key not to show both tables
#define PARM_ALL_REALIZATION L"-all_real" // key for showing the realization of the analyse
#define PARM_LOG L"-log:" // ���� ��� ����� �������
#define PARM_MAX_SIZE 200 // ����. ����� ������ ���������
#define PARM_OUT_DEFAULT_EXT L".asm" // ���������� ����� ���������� ���� �� ���������
#define PARM_LOG_DEFAULT_EXT L".log" // ���������� ����� ��� ��������� �� ���������
#define PARM_SINTAX_DEFAULT_EXT L".sintax.log"
#define PARM_GENER_DEFAULT_EXT L".gener.log"
namespace Parm // ��������� ������� ����������
{
	struct PARM
	{
		bool LT_log = true;
		bool ID_log = true;
		bool All_Real = false;
		wchar_t in[PARM_MAX_SIZE];
		wchar_t out[PARM_MAX_SIZE];
		wchar_t log[PARM_MAX_SIZE];
		wchar_t sintax[PARM_MAX_SIZE];
		wchar_t generation[PARM_MAX_SIZE];
	};

	PARM getparm(int argc, _TCHAR* argv[]);
}
