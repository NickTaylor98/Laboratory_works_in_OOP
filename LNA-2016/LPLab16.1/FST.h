#pragma once
#define START_FSATable FST::FSA FSATable[] = {
#define FINISH_FSATable };
#define _INT { { "", 4,\
FST::NODE(1, FST::RELATION('i', 1)),\
FST::NODE(1, FST::RELATION('n', 2)),\
FST::NODE(1, FST::RELATION('t', 3)),\
FST::NODE() }, LEX_INT, LT::PIN_I, LT::PN_DEFAULT }
#define _STR { { "", 4,\
FST::NODE(1, FST::RELATION('s', 1)),\
FST::NODE(1, FST::RELATION('t', 2)),\
FST::NODE(1, FST::RELATION('r', 3)),\
FST::NODE() }, LEX_STR, LT::PIN_S, LT::PN_DEFAULT }
#define _LITERAL_1 { { "", 2,\
	FST::NODE(20, FST::RELATION('1', 0), FST::RELATION('1', 1),\
	FST::RELATION('2', 0), FST::RELATION('2', 1), FST::RELATION('3', 0), FST::RELATION('3', 1), FST::RELATION('4', 0),\
	FST::RELATION('4', 1), FST::RELATION('5', 0), FST::RELATION('5', 1), FST::RELATION('6', 0), FST::RELATION('6', 1),\
	FST::RELATION('7', 0), FST::RELATION('7', 1), FST::RELATION('8', 0), FST::RELATION('8', 1), FST::RELATION('9', 0),\
	FST::RELATION('9', 1), FST::RELATION('0', 0), FST::RELATION('0', 1)),\
	FST::NODE() }, LEX_LITERAL, LT::LT_INT, LT::PN_DEFAULT }
#define _LITERAL_2 { { "", 3,\
	FST::NODE(1, FST::RELATION('"', 1)),\
	FST::NODE(155, FST::RELATION(' ', 1),\
	FST::RELATION('а', 1), FST::RELATION('б', 1), FST::RELATION('в', 1), FST::RELATION('г', 1), FST::RELATION('д', 1),\
	FST::RELATION('е', 1), FST::RELATION('ё', 1), FST::RELATION('ж', 1), FST::RELATION('з', 1), FST::RELATION('и', 1),\
	FST::RELATION('к', 1), FST::RELATION('л', 1), FST::RELATION('м', 1), FST::RELATION('н', 1), FST::RELATION('о', 1),\
	FST::RELATION('п', 1), FST::RELATION('р', 1), FST::RELATION('й', 1), FST::RELATION('с', 1), FST::RELATION('т', 1),\
	FST::RELATION('у', 1), FST::RELATION('ф', 1), FST::RELATION('х', 1), FST::RELATION('ц', 1), FST::RELATION('ч', 1),\
	FST::RELATION('ш', 1), FST::RELATION('щ', 1), FST::RELATION('ъ', 1), FST::RELATION('ы', 1), FST::RELATION('ь', 1),\
	FST::RELATION('э', 1), FST::RELATION('ю', 1), FST::RELATION('я', 1), FST::RELATION('a', 1), FST::RELATION('b', 1),\
	FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1),\
	FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
	FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1),\
	FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1),\
	FST::RELATION('w', 1), FST::RELATION('x', 1), FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('1', 1),\
	FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
	FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1), FST::RELATION('.', 1),\
    FST::RELATION(',', 1), FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION(':', 1), FST::RELATION(';', 1),\
    FST::RELATION('(', 1), FST::RELATION(')', 1), FST::RELATION('%', 1), FST::RELATION('#', 1), FST::RELATION('*', 1),\
    FST::RELATION('/', 1), FST::RELATION('<', 1), FST::RELATION('>', 1), FST::RELATION('\'', 1),FST::RELATION('^', 1),\
    FST::RELATION('&', 1), FST::RELATION('~', 1), FST::RELATION('$', 1), FST::RELATION('-', 1), FST::RELATION('+', 1),\
    FST::RELATION('А', 1), FST::RELATION('Б', 1), FST::RELATION('В', 1), FST::RELATION('Г', 1), FST::RELATION('Д', 1),\
	FST::RELATION('Е', 1), FST::RELATION('Ё', 1), FST::RELATION('Ж', 1), FST::RELATION('З', 1), FST::RELATION('И', 1),\
	FST::RELATION('К', 1), FST::RELATION('Л', 1), FST::RELATION('М', 1), FST::RELATION('Н', 1), FST::RELATION('О', 1),\
	FST::RELATION('П', 1), FST::RELATION('Р', 1), FST::RELATION('Й', 1), FST::RELATION('С', 1), FST::RELATION('Т', 1),\
	FST::RELATION('У', 1), FST::RELATION('Ф', 1), FST::RELATION('Х', 1), FST::RELATION('Ц', 1), FST::RELATION('Ч', 1),\
	FST::RELATION('Ш', 1), FST::RELATION('Щ', 1), FST::RELATION('Ъ', 1), FST::RELATION('Ы', 1), FST::RELATION('Ь', 1),\
	FST::RELATION('Э', 1), FST::RELATION('Ю', 1), FST::RELATION('Я', 1), FST::RELATION('A', 1), FST::RELATION('B', 1),\
	FST::RELATION('C', 1), FST::RELATION('D', 1), FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1),\
	FST::RELATION('H', 1), FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),\
	FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('Q', 1),\
	FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1), FST::RELATION('U', 1), FST::RELATION('V', 1),\
	FST::RELATION('W', 1), FST::RELATION('X', 1), FST::RELATION('Y', 1), FST::RELATION('Z', 1), FST::RELATION('=', 1),\
    FST::RELATION('\\', 1), /* \ */ FST::RELATION('"', 2)),\
	FST::NODE() }, LEX_LITERAL, LT::LT_STR , LT::PN_DEFAULT}
#define _FUNCTION { { "", 9,\
FST::NODE(1, FST::RELATION('f', 1)),\
FST::NODE(1, FST::RELATION('u', 2)),\
FST::NODE(1, FST::RELATION('n', 3)),\
FST::NODE(1, FST::RELATION('c', 4)),\
FST::NODE(1, FST::RELATION('t', 5)),\
FST::NODE(1, FST::RELATION('i', 6)),\
FST::NODE(1, FST::RELATION('o', 7)),\
FST::NODE(1, FST::RELATION('n', 8)),\
FST::NODE() }, LEX_FUNCTION, LT::PIN_F, LT::PN_DEFAULT }
#define _VAR { { "", 4,\
FST::NODE(1, FST::RELATION('v', 1)),\
FST::NODE(1, FST::RELATION('a', 2)),\
FST::NODE(1, FST::RELATION('r', 3)),\
FST::NODE() }, LEX_VAR,   LT::PIN_VAR, LT::PN_DEFAULT }
#define _RETURN { { "", 7,\
FST::NODE(1, FST::RELATION('r', 1)),\
FST::NODE(1, FST::RELATION('e', 2)),\
FST::NODE(1, FST::RELATION('t', 3)),\
FST::NODE(1, FST::RELATION('u', 4)),\
FST::NODE(1, FST::RELATION('r', 5)),\
FST::NODE(1, FST::RELATION('n', 6)),\
FST::NODE() }, LEX_RETURN, LT::PIN_DEF , LT::PN_DEFAULT}
#define _OUT { { "", 4,\
FST::NODE(1, FST::RELATION('o', 1)),\
FST::NODE(1, FST::RELATION('u', 2)),\
FST::NODE(1, FST::RELATION('t', 3)),\
FST::NODE() }, LEX_OUT, LT::PIN_DEF, LT::PN_DEFAULT }
#define _MAIN { { "", 5,\
FST::NODE(1, FST::RELATION('m', 1)),\
FST::NODE(1, FST::RELATION('a', 2)),\
FST::NODE(1, FST::RELATION('i', 3)),\
FST::NODE(1, FST::RELATION('n', 4)),\
FST::NODE() }, LEX_MAIN, LT::PIN_M , LT::PN_DEFAULT}
#define _SEMICOLON	{ { "", 2, FST::NODE(1, FST::RELATION(';', 1)), FST::NODE() }, LEX_SEMICOLON, LT::PIN_DEF, LT::PN_DEFAULT }
#define _COMMA		{ { "", 2, FST::NODE(1, FST::RELATION(',', 1)), FST::NODE() }, LEX_COMMA, LT::PIN_DEF, LT::PN_DEFAULT }
#define _LEFTBRACE   { { "", 2, FST::NODE(1, FST::RELATION('{', 1)), FST::NODE() }, LEX_LEFTBRACE, LT::PIN_DEF, LT::PN_DEFAULT }
#define _BRACELET	{ { "", 2, FST::NODE(1, FST::RELATION('}', 1)), FST::NODE() }, LEX_BRACELET, LT::PIN_DEF, LT::PN_DEFAULT }
#define _LEFTTHESIS	{ { "", 2, FST::NODE(1, FST::RELATION('(', 1)), FST::NODE() }, LEX_LEFTTHESIS, LT::PIN_DEF, LT::PN_LEFTTHESIS }
#define _RIGHTTHESIS { { "", 2, FST::NODE(1, FST::RELATION(')', 1)), FST::NODE() }, LEX_RIGHTTHESIS, LT::PIN_DEF, LT::PN_DEFAULT }
#define _PLUS		{ { "", 2, FST::NODE(1, FST::RELATION('+', 1)),FST::NODE() }, LEX_PLUS, LT::PIN_DEF, LT::PN_PLUS }
#define _MINUS		{ {"", 2, FST::NODE(1, FST::RELATION('-', 1)), FST::NODE() }, LEX_MINUS, LT::PIN_DEF, LT::PN_MINUS }
#define _STAR		{ {"", 2, FST::NODE(1, FST::RELATION('*', 1)), FST::NODE() }, LEX_STAR, LT::PIN_DEF, LT::PN_STAR }
#define _DIRSLASH	{ {"", 2, FST::NODE(1, FST::RELATION('/', 1)), FST::NODE() }, LEX_DIRSLASH, LT::PIN_DEF, LT::PN_DIRSLASH }
#define _EQUAL		{ { "", 2, FST::NODE(1, FST::RELATION('=', 1)), FST::NODE() }, LEX_EQUAL, LT::PIN_DEF, LT::PN_DEFAULT }
#define _ID	{ { "", 2,\
	FST::NODE(52, FST::RELATION('a', 0), FST::RELATION('a', 1),\
	FST::RELATION('b', 0), FST::RELATION('b', 1), FST::RELATION('c', 0), FST::RELATION('c', 1), FST::RELATION('d', 0),\
	FST::RELATION('d', 1), FST::RELATION('e', 0), FST::RELATION('e', 1), FST::RELATION('f', 0), FST::RELATION('f', 1),\
	FST::RELATION('g', 0), FST::RELATION('g', 1), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0),\
	FST::RELATION('i', 1), FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1),\
	FST::RELATION('l', 0), FST::RELATION('l', 1), FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0),\
	FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1), FST::RELATION('p', 0), FST::RELATION('p', 1),\
	FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1), FST::RELATION('s', 0),\
	FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),\
	FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0),\
	FST::RELATION('x', 1), FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),\
	FST::NODE() }, LEX_ID, LT::PIN_DEF, LT::PN_DEFAULT }


namespace FST
{
	struct RELATION  // ребро:символ -> вершина графа переходов КА
	{
		char symbol;  // символ перехода
		short nnode; // номер смежной вершины
		RELATION(
			char c = 0x00,    // символ перехода
			short ns = 0      // новое состояние
			);
	};

	struct NODE  // вершина графа перехода
	{
		short n_relation;      // количество инциндентных ребер
		RELATION *relations;  // инцидентные ребра
		NODE();
		NODE(
			short n,           // количество инциндентных ребер
			RELATION rel, ... // список ребр
			);
	};

	struct FST // недетерминированный КА
	{
		char* string;   // цепочка (строка, завершатся 0х00)
		short errors;
		short position; // текущая позиция в цепочке
		short nstates;  // количество состояний автомата 
		NODE* nodes;    // граф переходов: [0] - начальное состояние, [nstate-1] - конечное
		short* rstates;  // возможные состояния автомата на данной позиции
		FST(
			char* s,    // цепочка (строка, завершатся 0х00)
			short ns,   // количество состояний автомата
			NODE n, ... // Список состояний (граф перехода)
			);
		FST();
	};

	bool execute(  // выполнить распознавание цепочки
		FST& fst1   // недетерминированный КА
		);

	struct FSA
	{
		FST fst;
		char lexema;
		int CID;
		int PN;
		FSA(FST f, char l, int n, int pr);
		FSA();
		void setFSA(char* s);
	};

}