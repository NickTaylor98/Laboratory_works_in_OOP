// Lab08_OOP.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include "..\..\Lab02_OOP\Lab02_OOP\Class.h"
#include "..\..\Lab07_OOP\Lab07_OOP\Matrix.h"
#include "Exeptions.h"
#define BIG_NUMBER 0x7ffff
int main()
{
	setlocale(LC_ALL, "");
	try
	{
		Student* stud = new Student();
		/*ifstream* fin =  new ifstream("Laba.txt"); //Исключение на файловый поток
		stud->Insert(fin);*/

		//stud->setCourse(7); // исключение на максимальный курс

		//stud->setFaculty("fgdgsgsfdgfdsgd"); //исключение на длинное название факультета
		
		
		/*unsigned int number(0xfffffff);  // Исключение на проблемы с выделением памяти
		auto stud2 = new Student[number < BIG_NUMBER ? number: throw new Exeption_Memory("Проблемы с выделением памяти")]; */

		//stud->setGroup(100); // assert()


		//stud->setGroup(100); //NDEBUG
		throw Spec_Exception();
		throw "rge";
	}
	catch (Exeption_Course* ex)
	{
		cerr << (*ex).getError()  << " " <<  __LINE__ << " " << __FILE__ << endl;
		delete ex;
	}
	catch (Exeption_Faculty* ex)
	{
		cerr << (*ex).getError() << endl;
		delete ex;
	}
	catch (Exeption_Memory* ex)
	{
		cerr << (*ex).getError() << endl;
		delete ex;
	}
	catch (Exeption_Fstream* ex)
	{
		cerr << (*ex).getError() << endl;
		delete ex;
	}
	catch (Basic_Exeption* ex)
	{
		cerr << (*ex).getError() << endl;
		delete ex;
	}
	catch (exception ex)
	{
		cerr << "Unknown exception" << endl;
	};
	system("pause");
    return EXIT_SUCCESS;
}

