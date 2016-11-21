// Lab02_OOP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Class.h"
#define NUMBER_OF_STUDENTS 4

int main()
{
	setlocale(LC_ALL, "");
	Student* stud = new Student[NUMBER_OF_STUDENTS];
	ifstream* fin = new ifstream("d:/Laba2.txt");
	for (int i(0); i < NUMBER_OF_STUDENTS; i++)
		stud[i].Insert(fin);
	for (int i(0); i < NUMBER_OF_STUDENTS; i++)
		stud[i].Print();
	Print_From_One_Faculty(stud, NUMBER_OF_STUDENTS, "FIT");
	Print_From_One_Group(stud, NUMBER_OF_STUDENTS, 5);
	for (int i(0); i < NUMBER_OF_STUDENTS; i++)
		stud[i].~Student();
	system("pause");
	return 0;
}