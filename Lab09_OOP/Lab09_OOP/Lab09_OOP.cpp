// Lab09_OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Container.h"
#include "Container2.h"
#define SIZE_OF_ARRAY 50
int main()
{
	setlocale(LC_ALL, "");
	auto cont = new Container{ 12.0,12.0,32.0 };
	Container_Second* cont1 = new Container_Second{ {3.1345 ,1 }, {4.456,2}, {5.1213,4} };
	(*cont).Print();
//	(*cont).Insert(34.0,34.0,34.0,34.0,34.0,DBL_MAX);
//	double* arr = new double[SIZE_OF_ARRAY]; 
//	for (ui i(0); i < SIZE_OF_ARRAY; i++) arr[i] = (double)i;
//	(*cont).Change(34, arr, SIZE_OF_ARRAY);
	ui n = 2;
	(*cont).Change(n, (*cont1).GetArray(), (*cont1).getSize());
	(*cont).Print();
	(*cont1).Print();
	delete cont, cont1;
	system("pause");
    return EXIT_SUCCESS;
}

