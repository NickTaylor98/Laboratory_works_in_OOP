// Lab09_OOP(2).cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "Functor.h"
#include <iostream>
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
	puts("\n");
	(*cont).Print();
	//sort((*cont1).begin(), (*cont1).end(), [](const pair <int, double>&a, const pair<int, double>&b) {return a.second > b.second; }); не существует сортировки на ассоциативные контеёнеры

	//nth_element<map>(cont1->begin(),cont1->at(3),cont1->end()); у ассоциативного контейнера нет random_access_iterator

	unique_ptr<Container> cont3(new Container{});
	cont3->Merge(*cont, *cont1);
	cont3->Print();
	puts("\n");
	
	arr = cont3->Find(10, 100, size);
	printf("Элементов, удовлетворяющих условию: %u\n", size - 1);

	string str("Nikita");
	char* str_0 = new char[strlen("Laptev")];
	strcpy(str_0,"Laptev");
	string str1(str_0);
	string str2(5, 'L');
	str2 = str1 + " " + str;
	str1 = str2.substr(0,4);
	cout << str2 << "\n" << str1 << "\n";

	auto sd = plus<double>();
	vector <double> vec1{0.0, 1.0, 2.0, 4.0};
	vector <double> vec2{ 0.0, 1.0, 2.0, 4.0 };
	vector <double> vec3{0.0, 0.0, 0.0, 0.0};
	transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), Functor<double,plus>(sd));
	puts("\n"); 
	for (auto i : vec3) printf("%f ", i); puts("\n");

	binder1st< less<double> > less_than(less<double>(), 3.0);
	printf("Количество элементов больших 3: %u\n", count_if(vec3.begin(), vec3.end(), less_than));
	binder2nd <less <double>> more_than(less<double>(), 3.0);
	printf("Количество элементов меньших 3: %u\n", count_if(vec3.begin(), vec3.end(), more_than));

	system("pause");
    return 0;
}