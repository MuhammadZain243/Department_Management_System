#pragma once
#include<iostream>
using namespace std;

class Course;
class Faculty;
class Student;

//-------------------------Date Class________________________
class Date
{
private:
	int Day, Month, Year;
public:
	Date(int d, int m, int y);

	void set_Day(int d);
	void set_Month(int m);
	void set_Year(int y);

	int get_Day();
	int get_Month();
	int get_Year();

	void Display();

	friend istream& operator >>(istream& in, Date& d);
	friend ostream& operator <<(ostream& out, Date& d);
};
//-------------------------Student Class----------------------
class Student
{
private:
	Date joining_date;
	string name;
	string id;
	Course** course_list;
	int number_of_course;
	int count;
public:
	Student();

	void SET_ALL_DATA(string n, string i, int noc)
	{
		set_Name(n);
		set_ID(i);
		setNumber_of_Course(noc);
	}
	void set_Joining_Date(Date d);
	void set_Name(string n);
	void set_ID(string i);
	void set_Course_list(Course* c);
	void setNumber_of_Course(int noc);

	string get_Name();
	string get_ID();
	int getNumber_of_Course();
	Course* get_Course_list();
	Date get_Joining_Date();

	void DisplayStudent();
	void Display_Course_List();

	friend istream& operator >>(istream& in, Student& s);
	friend ostream& operator <<(ostream& out, Student& s);
};

//--------------------------Course Class-------------------------
class Course
{
private:
	Date start_date;
	string title;
	string code;
	Student** student_list;
	Faculty** tec;
	int number_of_student;
	int count;
	int size;
	int number_of_teacher;
public:
	Course();

	void SET_ALL_DATA(string n, string c)
	{
		set_Title(n);
		set_Code(c);
	}
	void set_Start_Date(Date d);
	void set_Title(string n);
	void set_Code(string c);
	void set_Number_of_Student(int nos);
	void set_Student_List(Student* s);
	void Assign_Teacher(Faculty* f);
	void set_Number_of_Teacher(int t);

	string get_Title();
	string get_Code();
	Date get_Start_Date();
	int get_Number_Of_Student();
	Student* get_StudentList();
	Faculty* get_Teacher();
	int get_Number_of_Teacher();

	void DisplayCourse();
	void Display_Student_List();
	void Display_Faculty_List();

	friend istream& operator >>(istream& in, Course& c);
	friend ostream& operator <<(ostream& out, Course& c);
};
//---------------------------Faculty Class------------------------------
class Faculty
{
private:
	string name;
	string id;
	Date joing_date;
	Course** course_list;
	int course_list_size;
	int count;
public:
	Faculty(string n, string i);

	void set_Faculty_Name(string name);
	void set_Faculty_ID(string i);
	void set_Faculty_Joining_Date(Date d);
	void set_Course_List_Size(int size);
	void set_Course_List(Course* c);

	string get_Faculty_Name();
	string get_Faculty_ID();
	Date get_Faculty_Joining_Date();
	int get_Course_List_Size();
	Course* get_Course_List();

	void Display_Faculty();
	void Display_Course_List();

	friend istream& operator >>(istream& in, Faculty& f);
	friend ostream& operator <<(ostream& out, Faculty& f);
};

//---------------------------------Resolving Class---------------
class Re
{
private:
	Student** student_list;
	Course** course_list;
	Faculty** tec_list;
	int number_of_student, number_of_course, number_of_teacher;
	Student** temps;
	Course** tempc1;
	Course* tempc2;
	Faculty** tempt;
	int c1, c2, c3;
public:
	Re();
	void set_Number_Of_Student(int nos);
	void set_Number_Of_Course(int noc);
	void set_Number_of_Teacher(int nt);
	void set_Student_List(Student* s);
	void set_Course_List(Course* c);
	void set_Teacher_List(Faculty* f);
	void Connect_Student_And_Course(int sindux, int cindux);
	void Connect_Course_And_Faculty(int cindux, int tindux);
};

//------------------------ Admin ---------------------------

class Admin
{
private:
	string name;
	string id;
	Date joining_date;
	Course** co;
	Student** st;
	Faculty** tec;
	int student, course, teacher;
public:
	Admin(string n, string i);

	void set_Name(string n);
	void set_ID(string i);
	void set_Joining_Date(Date o);
	void set_Number_of_Student(int nos);
	void set_Number_of_Course(int noc);
	void set_Number_of_Teacher(int noT);
	void set_Course(Course* c);
	void set_Student(Student* s);
	void set_Teacher(Faculty* t);

	string get_Name();
	string get_ID();
	Date get_Joining_Date();
	int get_Number_Of_Student();
	int get_Number_Of_Course();
	int get_Number_Of_Teacher();
	Course* get_Course();
	Student* get_Student();
	Faculty* get_Faculty();

	void Display_INFO();
	void Display_Student_INFO();
	void Display_Course_INFO();
	void Display_Faculty_INFO();

	friend istream& operator >>(istream& in, Admin& a);
	friend ostream& operator <<(ostream& out, Admin& a);
};
