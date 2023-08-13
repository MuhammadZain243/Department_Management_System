#pragma once
#include"Prototype.h"
#include<iostream>
using namespace std;

//-------------------------Date Class-------------------------

//Constructor
Date::Date(int d = 0, int m = 0, int y = 0) :Day(d), Month(m), Year(y)
{
}

//Setter Function
void Date::set_Day(int d)
{
	Day = d;
}
void Date::set_Month(int m)
{
	Month = m;
}
void Date::set_Year(int y)
{
	Year = y;
}

//Getter Function
int Date::get_Day()
{
	return Day;
}
int Date::get_Month()
{
	return Month;
}
int Date::get_Year()
{
	return Year;
}

//Display Function
void Date::Display()
{
	cout << "\tDay - Month -  Year : " << Day << " - " << Month << " - " << Year;
}
//cin operator for Date
istream& operator >>(istream& in, Date& d)
{
	do {
		cout << "Enter Day : ";
		in >> d.Day;
		if (d.Day < 32 && d.Day>0)
		{
			break;
		}
	} while (true);

	do {
		cout << "Enter Month : ";
		in >> d.Month;
		if (d.Month < 13 && d.Month>0)
		{
			break;
		}
	} while (true);

	cout << "Enter Year : ";
	in >> d.Year;
	return in;
}
ostream& operator<<(ostream& out, Date& d)
{
	out << "\tDay - Month -  Year : " << d.Day << " - " << d.Month << " - " << d.Year;
	return out;
}

//---------------------------Student Class Defination--------------------
//Constructor
Student::Student()
{
	name = "NILL";
	id = "NILL";
	number_of_course = 0;
	count = 0;
	course_list = new Course * [number_of_course];
}

//Setter Function
void Student::set_Name(string n)
{
	name = n;
}
void Student::set_ID(string i)
{
	id = i;
}
void Student::setNumber_of_Course(int noc)
{
	number_of_course = noc;
	course_list = new Course * [number_of_course];
}
void Student::set_Joining_Date(Date d)
{
	joining_date = d;
}
void Student::set_Course_list(Course* c)
{
	if (count < number_of_course)
	{
		course_list[count] = c;
		count++;
	}
}

//Getter Function
string Student::get_Name()
{
	return name;
}
string Student::get_ID()
{
	return id;
}
Date Student::get_Joining_Date()
{
	return joining_date;
}
int Student::getNumber_of_Course()
{
	return number_of_course;
}
Course* Student::get_Course_list()
{
	return *course_list;
}

//Display Function
void Student::DisplayStudent()
{
	cout << "\nStudent ID : " << id;
	cout << "\nStudent Name : " << name;
	cout << "\nJoining Date : ";
	joining_date.Display();
}
void Student::Display_Course_List()
{
	cout << "\nNumber Of Courses : " << number_of_course;
	cout << "\n";
	for (int i = 0; i < number_of_course; i++)
	{
		cout << "\n\tCourse " << i + 1 << "\n";
		cout << "======================================\n";
		course_list[i]->DisplayCourse();
		cout << "\n";
	}
}

//cin operator overload for Student
istream& operator >>(istream& in, Student& s)
{
	cout << "Enter Student ID : ";
	in >> s.id;
	cout << "Enter Student Name : ";
	in >> s.name;
	cout << "\nEnter Joining Date \n";
	cout << "------------------------------\n";
	cin >> s.joining_date;
	return in;
}
//cout operator overlaod for Student
ostream& operator <<(ostream& out, Student& s)
{
	out << "\nStudent ID : " << s.id;
	out << "\nStudent Name : " << s.name;
	cout << "\nJoining Date : " << s.joining_date;
	out << "\nNumber Of Courses : " << s.number_of_course;
	for (int i = 0; i < s.number_of_course; i++)
	{
		out << "\n\tCourse " << i + 1 << "\n";
		out << "======================================\n";
		s.course_list[i]->DisplayCourse();
		cout << "\n";
	}
	return out;
}

//-----------------------Course Class Defination ------------------------
//Constructor
Course::Course()
{
	title = "NILL";
	code = "NILL";
	number_of_student = 0;
	number_of_teacher = 0;
	count = 0;
	size = 0;
	student_list = new Student * [number_of_student];
	tec = new Faculty * [number_of_teacher];
}

//Setter Function
void Course::set_Title(string n)
{
	title = n;
}
void Course::set_Code(string c)
{
	code = c;
}
void Course::set_Start_Date(Date d)
{
	start_date = d;
}
void Course::set_Number_of_Student(int nos)
{
	number_of_student = nos;
	student_list = new Student * [number_of_student];
}
void Course::set_Student_List(Student* s)
{
	if (count < number_of_student)
	{
		student_list[count] = s;
		count++;
	}
}
void Course::set_Number_of_Teacher(int t)
{
	number_of_teacher = t;
	tec = new Faculty * [number_of_teacher];
}
void Course::Assign_Teacher(Faculty* f)
{
	if (size < number_of_teacher)
	{
		tec[size] = f;
		size++;
	}
}

//Getter Function
string Course::get_Code()
{
	return code;
}
string Course::get_Title()
{
	return title;
}
Date Course::get_Start_Date()
{
	return start_date;
}
int Course::get_Number_Of_Student()
{
	return number_of_student;
}
Student* Course::get_StudentList()
{
	return *student_list;
}
int Course::get_Number_of_Teacher()
{
	return number_of_student;
}
Faculty* Course::get_Teacher()
{
	return *tec;
}

//Display Function
void Course::DisplayCourse()
{
	cout << "\nCourse Code : " << code;
	cout << "\nCourse Name : " << title;
	cout << "\nStart Time ";
	start_date.Display();
}
void Course::Display_Student_List()
{
	cout << "\nNumber Of Student : " << number_of_student;
	cout << "\n";
	for (int i = 0; i < number_of_student; i++)
	{
		cout << "\n\tStudent " << i + 1 << "\n";
		cout << "====================================\n";
		student_list[i]->DisplayStudent();
		cout << "\n";
	}
}
void Course::Display_Faculty_List()
{
	cout << "\nNumber Of Teacher : " << number_of_teacher;
	cout << "\n";
	for (int i = 0; i < number_of_teacher; i++)
	{
		cout << "\nTeacher " << i + 1 << "\n";
		cout << "====================================\n";
		tec[i]->Display_Faculty();
		cout << "\n";
	}
}

//cin operator for Course
istream& operator >>(istream& in, Course& c)
{
	cout << "Enter Course Code : ";
	in >> c.code;
	cout << "Enter Course Name : ";
	in >> c.title;
	cout << "\nEnter Starting Date \n";
	cout << "-------------------------\n";
	cin >> c.start_date;
	return in;
}

//cout operator for Course
ostream& operator <<(ostream& out, Course& c)
{
	out << "\nCourse Code : " << c.code;
	out << "\nCourse Name : " << c.title;
	cout << "\nStart Date : " << c.start_date;
	out << "\nNumber Of Student : " << c.number_of_student;
	out << "\n";
	for (int i = 0; i < c.number_of_student; i++)
	{
		out << "\n\tStudent " << i + 1 << "\n";
		out << "====================================\n";
		c.student_list[i]->DisplayStudent();
		out << "\n";
	}
	out << "\nNumber Of Teacher : " << c.number_of_teacher;
	out << "\n";
	for (int i = 0; i < c.number_of_teacher; i++)
	{
		out << "\nTeacher " << i + 1 << "\n";
		out << "====================================\n";
		c.tec[i]->Display_Faculty();
		out << "\n";
	}
	return out;
}

//----------------------Faculty Class Defination-----------------------
//Constructor
Faculty::Faculty(string n = "NILL", string i = "NILL")
{
	name = n;
	id = i;
	count = 0;
	course_list_size = 0;
	course_list = new Course * [course_list_size];
}

//Setter Function
void Faculty::set_Faculty_Name(string n)
{
	name = n;
}
void Faculty::set_Faculty_ID(string i)
{
	id = i;
}
void Faculty::set_Faculty_Joining_Date(Date d)
{
	joing_date = d;
}
void Faculty::set_Course_List_Size(int size)
{
	course_list_size = size;
	course_list = new Course * [course_list_size];
}
void Faculty::set_Course_List(Course* c)
{
	if (count < course_list_size)
	{
		course_list[count] = c;
		count++;
	}
}

//Getter Function
string Faculty::get_Faculty_Name()
{
	return name;
}
string Faculty::get_Faculty_ID()
{
	return id;
}
Date Faculty::get_Faculty_Joining_Date()
{
	return joing_date;
}
int Faculty::get_Course_List_Size()
{
	return course_list_size;
}
Course* Faculty::get_Course_List()
{
	return *course_list;
}

//Display Function
void Faculty::Display_Faculty()
{
	cout << "\nFaculty ID : " << id;
	cout << "\nFaculty Name : " << name;
	cout << "\nJoining Date : ";
	joing_date.Display();
}
void Faculty::Display_Course_List()
{
	cout << "\nCourse List Size : " << course_list_size;
	for (int i = 0; i < course_list_size; i++)
	{
		cout << "\n\tCourse " << i + 1 << "\n";
		cout << "<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n";
		course_list[i]->DisplayCourse();
		cout << "\n";
	}
}

//cin operator overload for Faculty
istream& operator >>(istream& in, Faculty& f)
{
	cout << "Enter Faculty ID : ";
	in >> f.id;
	cout << "Enter Faculty Name : ";
	in >> f.name;
	cout << "\nJoining Date\n";
	cout << "------------------------\n";
	cin >> f.joing_date;
	return in;
}
//cout operator overload for Faculty
ostream& operator <<(ostream& out, Faculty& f)
{
	out << "\nFaculty ID : " << f.id;
	out << "\nFaculty Name : " << f.name;
	out << "\nJoining Date : ";
	cout << f.joing_date;
	cout << "\nCourse List Size : " << f.course_list_size;
	for (int i = 0; i < f.course_list_size; i++)
	{
		cout << "\n\tCourse " << i + 1 << "\n";
		cout << "<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n";
		f.course_list[i]->DisplayCourse();
		cout << "\n";
	}
	return out;
}


//-----------------------Resolving Class -----------------------------

//Constructor
Re::Re()
{
	c1 = 0;
	c2 = 0;
	c3 = 0;
	number_of_course = 0;
	number_of_student = 0;
	number_of_teacher = 0;
	student_list = new Student * [number_of_student];
	course_list = new Course * [number_of_course];
	tec_list = new Faculty * [number_of_teacher];
}

//Set Number Of Student
void Re::set_Number_Of_Student(int nos)
{
	number_of_student = nos;
	student_list = new Student * [number_of_student];
}

//Set Number Of Course
void Re::set_Number_Of_Course(int noc)
{
	number_of_course = noc;
	course_list = new Course * [number_of_course];
}

//Set Number Of Teacher
void Re::set_Number_of_Teacher(int nt)
{
	number_of_teacher = nt;
	tec_list = new Faculty * [number_of_teacher];
}

//Set Student List
void Re::set_Student_List(Student* s)
{
	if (c1 < number_of_student)
	{
		student_list[c1] = s;
		c1++;
	}
}

//Set Course List
void Re::set_Course_List(Course* c)
{
	if (c2 < number_of_course)
	{
		course_list[c2] = c;
		c2++;
	}
}

//Set Teacher List
void Re::set_Teacher_List(Faculty* f)
{
	if (c3 < number_of_teacher)
	{
		tec_list[c3] = f;
		c3++;
	}
}

//Creat Relation Between Student And Course
void Re::Connect_Student_And_Course(int sindux, int cindux)
{
	temps = &student_list[sindux];
	tempc1 = &course_list[cindux];

	student_list[sindux]->set_Course_list(*tempc1);
	course_list[cindux]->set_Student_List(*temps);
}

//Creat Relation Between Course And Faculty
void Re::Connect_Course_And_Faculty(int cindux, int tindux)
{
	tempc2 = course_list[cindux];
	tempt = &tec_list[tindux];

	course_list[cindux]->Assign_Teacher(*tempt);
	tec_list[tindux]->set_Course_List(tempc2);
}

//----------------------------------- Admin------------------------------

//Constructor
Admin::Admin(string n = "NILL", string i = "NILL") :name(n), id(i)
{
	course = 0;
	student = 0;
	teacher = 0;
	co = new Course * [course];
	st = new Student * [student];
	tec = new Faculty * [teacher];
}

//Setter Function
void Admin::set_Name(string n)
{
	name = n;
}
void Admin::set_ID(string i)
{
	id = i;
}
void Admin::set_Joining_Date(Date o)
{
	joining_date = o;
}
void Admin::set_Number_of_Course(int noc)
{
	course = noc;
	co = new Course * [course];
}
void Admin::set_Number_of_Student(int nos)
{
	student = nos;
	st = new Student * [student];
}
void Admin::set_Number_of_Teacher(int noT)
{
	teacher = noT;
	tec = new Faculty * [teacher];
}
void Admin::set_Course(Course* c)
{
	for (int i = 0; i < course; i++)
	{
		co[i] = &c[i];
	}
}
void Admin::set_Student(Student* s)
{
	for (int i = 0; i < student; i++)
	{
		st[i] = &s[i];
	}
}
void Admin::set_Teacher(Faculty* t)
{
	for (int i = 0; i < teacher; i++)
	{
		tec[i] = &t[i];
	}
}

//Getter Function
string Admin::get_Name()
{
	return name;
}
string Admin::get_ID()
{
	return id;
}
Date Admin::get_Joining_Date()
{
	return joining_date;
}
int Admin::get_Number_Of_Course()
{
	return course;
}
int Admin::get_Number_Of_Student()
{
	return student;
}
int Admin::get_Number_Of_Teacher()
{
	return teacher;
}
Course* Admin::get_Course()
{
	return *co;
}
Student* Admin::get_Student()
{
	return *st;
}
Faculty* Admin::get_Faculty()
{
	return *tec;
}
void Admin::Display_INFO()
{
	cout << "\nAdmin ID : " << id;
	cout << "\nAdmin Name : " << name;
	cout << "\nJoining Date  : " << joining_date;
}
void Admin::Display_Course_INFO()
{
	cout << "\n";
	for (int i = 0; i < course; i++)
	{
		cout << "Course " << i + 1 << " INFO ";
		cout << "\n****************************************************\n";
		co[i]->DisplayCourse();
		co[i]->Display_Student_List();
		co[i]->Display_Student_List();
		cout << "\n****************************************************\n\n";
	}
}
void Admin::Display_Student_INFO()
{
	cout << "\n";
	for (int i = 0; i < student; i++)
	{
		cout << "Student " << i + 1 << " INFO";
		cout << "\n****************************************************\n";
		st[i]->DisplayStudent();
		st[i]->Display_Course_List();
		cout << "\n****************************************************\n\n";
	}
}
void Admin::Display_Faculty_INFO()
{
	cout << "\n";
	for (int i = 0; i < teacher; i++)
	{
		cout << "Teacher " << i + 1 << " INFO";
		cout << "\n****************************************************\n";
		tec[i]->Display_Faculty();
		tec[i]->Display_Course_List();
		cout << "\n****************************************************\n\n";
	}
}

istream& operator >>(istream& in, Admin& a)
{
	cout << "Enter Admin ID : ";
	in >> a.id;
	cout << "Enter Admin Name : ";
	in >> a.name;
	cout << "Enter Joining Date \n";
	cout << "=============================\n";
	cin >> a.joining_date;
	return in;
}
ostream& operator <<(ostream& out, Admin& a)
{
	cout << "Admin ID : " << a.id;
	cout << "Admin Name : " << a.name;
	cout << "Joining Date  : " << a.joining_date;

	cout << "\n";
	for (int i = 0; i < a.course; i++)
	{
		cout << "Course " << i + 1 << " INFO ";
		cout << "\n****************************************************\n";
		cout << a.co[i];
		cout << "\n****************************************************\n\n";
	}

	cout << "\n";
	for (int i = 0; i < a.teacher; i++)
	{
		cout << "Teacher " << i + 1 << " INFO";
		cout << "\n****************************************************\n";
		cout << a.tec[i];
		cout << "\n****************************************************\n\n";
	}

	cout << "\n";
	for (int i = 0; i < a.teacher; i++)
	{
		cout << "Teacher " << i + 1 << " INFO";
		cout << "\n****************************************************\n";
		cout << a.tec[i];
		cout << "\n****************************************************\n\n";
	}
	return out;
}
