#pragma once
#define ID_MAXSIZE				 10			// максимальное количество символов в идентификаторе
#define STR_LITERAL_MAXSIZE      255        // максимальное число символов в строчном литерале
#define ID_WITH_PREFIX_MAXSIZE   20			// максимальное количество символов в идентификаторе с префиксом
#define TI_MAXSIZE				 4096		// максимальное количество строк в таблице идентификаторов
#define TI_INT_DEFAULT			 0x00000000	// значение по умолчанию для int
#define	TI_STR_DEFAULT			 0x00		// значение по умолчанию для str
#define TI_NULLIDX				 0xffffffff  // нет элемента таблицы идентификаторов

namespace IT // таблица идентификаторов
{
	enum IDDATATYPE { DEFD = 0, INT = 1, STR = 2}; // типы данных идентификаторов
	enum IDTYPE     {             //типы идентификаторов
		              DEFT = 0,   // неизвестно
		                 V = 1,   // переменная
		                 P = 2,   // параметр
		                 F = 3,   // функция
		                 L = 4,   // литерал
		                 M = 5,   // главная функция
		                 O = 6	  // оператор
	                 }; 

	struct Entry
	{
		int idxfirstLE;				 // индекс первой строки в таблице лексем
		char id_buf[ID_MAXSIZE];	 // идентификатор без префикса
		char id[ID_WITH_PREFIX_MAXSIZE];	 // идентификатор
		bool is_var = false;		 // объявлена внутри функции
		IDDATATYPE iddatatype;		 // тип данных
		IDTYPE idtype;				 // тип идентификатора
		union
		{
			int vint;            // значение int
			struct
			{
				unsigned int len;                       // количество символов в str
				char str[STR_LITERAL_MAXSIZE - 1]; // символы str
			} vstr;							  // значение str
		} value;							  // значение идентификатора
		bool std_lib;                         // функции стандартной библиотеки
		int number_of_param;                  // число параметров (для функций) 
		Entry() { iddatatype = DEFD; idtype = DEFT; idxfirstLE = 0;  number_of_param = 0;};
	};

	struct IdTable
	{
		bool if_double_i = false;
		int IT_num = 0;
		bool f_main = false;
		int maxsize; // емкость ТИ
		int size; // текущий размер ТИ
		Entry* table; //  массив строк ТИ
	};

	IdTable Create // создать ТИ
		(
			int size // емкость ТИ
			);
	void Add( // добавить строку в ТИ
		IdTable&idtable, // экземпляр ТИ
		Entry entry // строка ТИ
		);
	Entry GetEntry( // получить строку ТТ
		IdTable& idtable, // экземпляр ТИ
		int n // номер получаемой строки
		);
	/*int IsId(
		IdTable& idtable, // экземпляр ТИ
		char id[ID_MAXSIZE] // идентификатор
		);*/
	int IsId(Log::LOG, IdTable& idtable, IT::Entry id);
	int IsLiteral(IdTable& idtable, IT::Entry elem);
	void Delete_Elem(IdTable& idtable, LT::LexTable& lextable, int index);
	void Delete(IdTable& idtable);
}