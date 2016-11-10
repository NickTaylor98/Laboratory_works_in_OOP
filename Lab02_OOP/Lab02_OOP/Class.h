//Создать класс Student : id, Фамилия, Имя, Отчество, Дата рождения, 
//Адрес, Телефон, Факультет, Курс, Группа.Функции - члены реализуют запись и
//считывание полей(проверка корректности), расчет возраста студента Создать 
//массив объектов.Вывести : a) список студентов заданного факультета; d) список учебной группы.
#pragma once
#include <string>
using namespace std;
using us = unsigned short;
struct Data
{
	us Day;
	us Month;
	unsigned int Year;
	Data();
	Data(us day, us month, unsigned int year);
};
struct Adress
{
	string Street;
	string City;
	string Region;
	string Country;
	us House;
	us Flat;
	Adress();
	Adress(string city, string street, string region, string country, us house, us flat);
	~Adress();
};
class Student
{
	string Surname;
	string Name;
	string Second_Name;
	Data Birthday;
	Adress Adress_of_student;
	string Telephone;
	string Faculty;
	us Course;
	us Group;
	static const us MaxCourse = 5;
	const us MaxGroup = 10;
	bool Sex;// пол человека: true - мужской, false - женский.
public:
	Student();
	Student(string name, string surname, string second_name);
	Student(string, string, string,Data, Adress, string, string, us, us, bool);
	Student(const Student &);
	~Student() noexcept;
	string getSurname() const;
	string getName() const;
	string getSecond_Name() const;
	Data getBirthday() const;
	Adress getAdress() const;
	string getTelephone() const;
	string getFaculty() const;
	us getCourse() const;
	us getGroup() const;

	void setSurname(string surname);
	void setName(string name);
	void setSecond_Name(string sec_name);
	void setBirthday(Data birthday);
	void setAdress(Adress adress);
	void setTelephone(string telephone);
	void setFaculty(string faculty);
	void setCourse(us course);
	void setGroup(us group);
	
	void Insert(ifstream*);
	void Print() const;
	static us Age(Data data);

	Student operator+(const Student&);
	Student operator=(const Student&);
	bool operator>(const Student&);
};
void Print_From_One_Faculty(Student arr[], us size, string fac);
void Print_From_One_Group(Student arr[], us size, us group);