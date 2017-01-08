#pragma once
#define ERROR_THROW(id) Error::geterror(id); // throw ERROR_THROW(id)
#define ERROR_THROW_IN(id, l, c) Error::geterrorin(id, l, c); // throw ERROR_THROW(id, строка, колонка)
#define ERROR_ENTRY(id, m) {id, m, {-1, -1}} // элемент таблицы ошибок
#define ERROR_MAXSIZE_MESSAGE 200 // максимальная длина сообщения об ошибке
#define ERROR_ENTRY_NODEF(id) ERROR_ENTRY(-id, "Неопределенная ошибка") // 1 неопределенный элемент таблицы ошибок
// ERROR_ENTRY_NODEF10(id) - 10 неопреопределенных элементов таблицы ошибок
#define ERROR_ENTRY_NODEF10(id)   ERROR_ENTRY_NODEF(id + 0), ERROR_ENTRY_NODEF(id+1), ERROR_ENTRY_NODEF(id+2), ERROR_ENTRY_NODEF(id+3), \
	                              ERROR_ENTRY_NODEF(id + 4), ERROR_ENTRY_NODEF(id + 5), ERROR_ENTRY_NODEF(id + 6), ERROR_ENTRY_NODEF(id + 7), \
	                              ERROR_ENTRY_NODEF(id + 8), ERROR_ENTRY_NODEF(id + 9)
// ERROR_ENTRY_NODEF100(id) - 100 неопределенных элементов таблицы ошибок
#define ERROR_ENTRY_NODEF100(id) ERROR_ENTRY_NODEF10(id + 0), ERROR_ENTRY_NODEF10(id + 10), ERROR_ENTRY_NODEF10(id + 20), ERROR_ENTRY_NODEF10(id + 30), \
	                             ERROR_ENTRY_NODEF10(id + 40), ERROR_ENTRY_NODEF10(id + 50), ERROR_ENTRY_NODEF10(id + 60), ERROR_ENTRY_NODEF10(id + 70),\
	                             ERROR_ENTRY_NODEF10(id + 80), ERROR_ENTRY_NODEF10(id + 90)
#define ERROR_MAX_ENTRY 1000 // количество элементов в таблице ошибок


namespace Error
{
	struct ERROR // тип исключения для throw ERROR_THROW | ERRor _THROW_IN и catch(ERROR)
	{
		int id; // код ошибки
		char message[ERROR_MAXSIZE_MESSAGE]; // сообщения об ошибке
		struct IN // расширение для ошибок при обработке входных данных
		{
			short line; // номер строки (0,1,2,...)
			short col; // номер позиции в строке (0,1,2,...
		} inext;
	};
	ERROR geterror(int id);
	ERROR geterrorin(int id, int line=0, int col=0);
	ERROR geterror_id(int id, char* wrong, int line=0, int col=0);
}