#include "stdafx.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] // ������� ������
	{
		ERROR_ENTRY(0, "������������ ��� ������"), // ��� ������ ��� ��������� 0 - ERROR_MAX_ENTRY
		ERROR_ENTRY(1, "��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5), ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "�������� -in ������ ���� �����"),
		ERROR_ENTRY(101, "������ �������� ����� ���������"),
		ERROR_ENTRY(102, "SemAn: ����������� ��� ��������������: "), 
		ERROR_ENTRY(103, "SemAn: ������������ ��������������: "),
		ERROR_ENTRY(104, "��������� ����� �������� ���������"),
		ERROR_ENTRY(105, "LexAn: ������� �������� ������� ������, ����������� ������������ ������"),
		ERROR_ENTRY(106, "SemAn: �������� ���������� ����� ������������� ������ ��� ������ �������"), 
		ERROR_ENTRY(107, "SemAn: ������������� �������������: "), 
		ERROR_ENTRY(108, "SemAn: �������� ����� ������� �������"), 
		ERROR_ENTRY(109, "LexAn: �������� ������ �������������� ��� ��������"),
		ERROR_ENTRY(110, "������ ��� �������� ����� � �������� ������ (-in)"),
		ERROR_ENTRY(111, "������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(112, "������ ��� �������� ����� ��������� (-log)"),
		ERROR_ENTRY(113, "LexAn: �������� ������ ������� ���������������"),
	    ERROR_ENTRY(114, "LexAn: ������� �������� ������� ���������������, ����������� ������������ ������"),
		ERROR_ENTRY(115, "LexAn: ������� ������ �������� ������� ������� ���������������"),
		ERROR_ENTRY(116, "LexAn: ������� �������� ������ ������� ���������������"), 
		ERROR_ENTRY(117, "LexAn: �������� ������ ������� ������"),
		ERROR_ENTRY(118, "LexAn: ������� ������ �������� ������� ������� ������"), 
		ERROR_ENTRY(119, "LexAn: ������� �������� ������ ������� ������"),
		ERROR_ENTRY(120, "LexAn: �� ����������� ������������� ���� ������ ������ ����������"),
		ERROR_ENTRY(121, "SemAn: ��������������� ����� ���������������: " ),
		ERROR_ENTRY(122, "SemAn: �������� ��������� (��������, ��������� ������)"),
		ERROR_ENTRY(123, "SemAn: �� ������������ ���� ������������� �������� � ����� �������: "),
		ERROR_ENTRY(124, "SemAn: ��������� ������� ������� �����"), 
		ERROR_ENTRY(125, "SemAn: ���������� ����������� ��������������: "), 
		ERROR_ENTRY(126, "SemAn: �������� ����� ���������� �������: "),
		ERROR_ENTRY(127, "SemAn: �� ������� �������, ����������� ��������� ��������� �����"),
		ERROR_ENTRY(128, "SemAn: ��������� ������������ ����� ��������� ��������"),
		ERROR_ENTRY(129, "SemAn: ��������� �������������� �������� ��� ���� str �� �������������"),
		ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500), 
		ERROR_ENTRY(600, "SinAn: �������� ��������� ���������"),
		ERROR_ENTRY(601, "SinAn: �������� �������� ���������� � �������"),
		ERROR_ENTRY(602, "SinAn: ������ ������ �������"),
		ERROR_ENTRY(603, "SinAn: �������� ���������"),
		ERROR_ENTRY(604, "SinAn: ������ � ������"),
		ERROR_ENTRY_NODEF(605),ERROR_ENTRY_NODEF(606),
		ERROR_ENTRY_NODEF(607),ERROR_ENTRY_NODEF(608),
		ERROR_ENTRY_NODEF(609),
		ERROR_ENTRY_NODEF10(610), ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630),ERROR_ENTRY_NODEF10(640),
		ERROR_ENTRY_NODEF10(650), ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680),
		ERROR_ENTRY_NODEF10(690),ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	ERROR geterror(int id)
	{
		return (id > 0 && id < ERROR_MAX_ENTRY) ? errors[id] : errors[0];
	}
	ERROR geterrorin(int id, int line, int col)
	{
		ERROR ret = geterror(id);
		ret.inext.line = line;
		ret.inext.col = col;
		return ret;
	}
	ERROR geterror_id(int id, char* wrong_id, int line, int col)
	{
		ERROR rc = geterrorin(id,line, col);
		CONCAT(rc.message, wrong_id);
		return rc;
	}
}