// Lab09_OOP(2).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Container.h"
#include <iostream>
#include <map>
int main()
{
	setlocale(LC_ALL, "");
	int size(0);
	unique_ptr<Container> cont(new Container{3.3213,313.12,43, 32, 85,3212,321,53434.543});
	unique_ptr<map<int, double>> cont1(new map<int,double>());
	(*cont).Print();
	(*cont).Sort();
	(*cont).Print();

	
	int Counter = 0;
	double* arr = (*cont).Find(200, 100000, size);
	for (int i(0); i < size; i++) (*cont1).insert({Counter++ , arr[i]});
	for (auto i: *cont1)  printf("%g ", (i).second);
	printf("\n");
	(*cont).Print();
	//sort((*cont1).begin(), (*cont1).end(), [](const pair <int, double>&a, const pair<int, double>&b) {return a.second > b.second; }); не существует сортировки на ассоциативные контеёнеры

	
	
	system("pause");
    return 0;
}

