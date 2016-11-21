#include "stdafx.h"
#include "..\..\Lab02_OOP\Lab02_OOP\Class.h"
Data::Data(us day, us month, unsigned int year)
{
	day < 32 ? Day = day : Day = 0;
	month < 13 ? Month = month : Month = 0; 
	(year < 2016 && year > 1970) ? Year = year : Year = 0;
}
Data::Data() { /*Day = Month = Year = 0;*/ Day = 13, Month = 02, Year = 1998; }
Adress::Adress(string city, string street, string region, string country, us house, us flat) : Street(street), City(city), Region(region),
Country(country), House(house), Flat(flat) {}
Adress::~Adress()
{
	Region.~basic_string();
	Street.~basic_string();
	City.~basic_string();
	Country.~basic_string();
	House = 0;
	Flat = 0;
}
Adress::Adress()
{
	Street = City = Region = Country = "No information";
	House = Flat = 0;
}
Student Student::operator= (const Student& stud)
{
	this->Adress_of_student = stud.Adress_of_student;
	this->Birthday = stud.Birthday;
	this->Course = stud.Course;
	this->Faculty = stud.Faculty;
	this->Group = stud.Group;
	this->Name = stud.Name;
	return *(this);
}
Student Student::operator+(const Student& stud)
{
	*(this) = Student(stud);
	return *this;
}
bool Student::operator>(const Student& stud)
{
	bool rc(false);
	if (this->Age(this->Birthday) > stud.Age(stud.Birthday)) rc = true;
	return rc;
}
Student::Student(string name, string surname, string second_name)
{
	Student();
	Surname = surname;
	Name = name;
	Second_Name = second_name;
}
Student::Student()
{
	Sex = true;
	Course = Group = 0;
	Birthday = Data::Data();
	Adress_of_student = Adress::Adress("Minsk", "Belorusskaya", "Minsk", "Belarus", 21, 713);
	Surname = "Laptev";
	Name = "Nikita";
	Second_Name = "Alexandrovich";
	Telephone = "+375447589180";
	Faculty = "FIT";
}
Student::Student( string surname, string name, string second_name, Data birthday, Adress adress, string tel, string fac, us group, us course, bool sex)
{
	Student(surname, name, second_name);
	Sex = sex;
	Birthday = birthday;
	Adress_of_student = adress;
	Telephone = tel;
	Faculty = fac;
	(group < MaxGroup) ? Group = group : group = MaxGroup;
	(course < MaxCourse) ? Course = course : course = MaxCourse;
}
Student::Student(const Student &student)
{
	Birthday = student.Birthday;
	Adress_of_student = student.Adress_of_student;
	Telephone = student.Telephone;
	Faculty = student.Faculty;
	Group = student.Group;
	Course = student.Course;
	Surname = student.Surname;
	Name = student.Name;
	Second_Name = student.Second_Name;
}
Student::~Student() noexcept
{
	Course = Group = 0;
	Birthday = Data::Data();
	Adress_of_student.~Adress();
	Surname.~basic_string();
	Name.~basic_string();
	Second_Name.~basic_string();
	Telephone.~basic_string();
	Faculty.~basic_string();
}
string Student::getSurname() const { return Surname; }
string Student::getName() const { return Name; }
string Student::getSecond_Name() const { return Second_Name; }
Data Student::getBirthday() const { return Birthday; }
Adress Student::getAdress() const { return Adress_of_student; }
string Student::getTelephone() const { return Telephone; }
string Student::getFaculty() const { return Faculty; }
us Student::getCourse() const { return Course; }
us Student::getGroup() const { return Group; }
void Student::setSurname(string surname) { Surname = surname; }
void Student::setName(string name) { Name = name; }
void Student::setSecond_Name(string sec_name) { Second_Name = sec_name; }
void Student::setBirthday(Data birthday) { Birthday = birthday; }
void Student::setAdress(Adress adress) { Adress_of_student = adress; }
void Student::setTelephone(string telephone) { Telephone = telephone; }
void Student::setFaculty(string faculty) { Faculty = faculty; }
void Student::setCourse(us course) { Course = course; }
void Student::setGroup(us group) { Group = group; }
us Student::Age(Data data) { return (data.Month > 9 || (data.Month == 9 && data.Day > 24)) ? 2016 - data.Year - 1 : 2016 - data.Year; }
void Student::Insert(ifstream* fin)
{
	if (fin)
		*fin  >> Surname >> Name >> Second_Name >> Birthday.Day
		>> Birthday.Month >> Birthday.Year >> Adress_of_student.Street >>
		Adress_of_student.City >> Adress_of_student.Region >> Adress_of_student.Country
		>> Adress_of_student.House >> Adress_of_student.Flat >> Telephone >> Faculty >> Course
		>> Group >> Sex;
	else cout << "Файл не открывется" << endl;
}
void Student::Print() const
{
	cout << "Имя студента: " << Name << endl;
	cout << "Фамилия студента: " << Surname << endl;
	cout << "Отчество студента: " << Second_Name << endl;
	cout << "Пол студента: " << (Sex ? "мужской" : "женский") << endl;
	cout << "Дата рождения студента: " << Birthday.Day << "." << Birthday.Month << "." << Birthday.Year << endl;
	cout << "Возраст студента: " << Age(Birthday) << endl;
	cout << "Адрес студента: " << Adress_of_student.City << ", " <<
		Adress_of_student.Region << " region, " << Adress_of_student.Country << ", " << Adress_of_student.Street << ", "
		<< Adress_of_student.House << ", " << Adress_of_student.Flat << endl;
	cout << "Телефон студента: " << Telephone << endl;
	cout << "Факультет студента: " << Faculty << endl;
	cout << "Kурс студента: " << Course << endl;
	cout << "Группа студента: " << Group << endl;
}
void  Print_From_One_Faculty(Student arr[], us size, string fac)
{
	bool rc = true;
	cout << "На данном факультете (" << fac << ") обучаются:" << endl;
	for (int i{ 0 }; i < size; i++)
		if (arr[i].getFaculty() == fac)
		{
			cout << arr[i].getName() << " " << arr[i].getSurname() << " " << arr[i].getSecond_Name() << endl;
			rc = false;
		}
	if (rc) cout << "Не найдено таких студентов" << endl;
}
void  Print_From_One_Group(Student arr[], us size, us group)
{
	bool rc = true;
	cout << "В данной группе (№" << group << ") обучаются:" << endl;
	for (int i{ 0 }; i < size; i++)
		if (arr[i].getGroup() == group)
		{
			cout << arr[i].getName() << " " << arr[i].getSurname() << " " << arr[i].getSecond_Name() << endl;
			rc = false;
		}
	if (rc) cout << "Не найдено таких студентов" << endl;
}