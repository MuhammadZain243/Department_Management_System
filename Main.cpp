#include"Prototype.h"
#include"Defination.h"
#include<iostream>
using namespace std;

//-----------------------Main Function---------------------
int main()
{
	int nos, noc, nOt, size;
	string cid, sid, tid;
	int sindux = -1, cindux = -1, tindux = -1;
	int course, student, teacher;

	cout << " _____________________________________________\n";
	cout << "|                 DATA OF COURSE              |\n";
	cout << "|_____________________________________________|\n\n\n";
	cout << "Enter Total Number Course : ";
	cin >> course;
	Course* c;
	c = new Course[course];

	cout << "Enter Number Of Student For Each Course : ";
	cin >> nos;
	cout << "Enter Number Of Teacher For Each Course : ";
	cin >> nOt;
	cout << "\n";
	for (int i = 0; i < course; i++)
	{
		cout << "Enter Course " << i + 1 << " Data \n";
		cout << "=================================================\n";
		cin >> c[i];
		c[i].set_Number_of_Student(nos);
		c[i].set_Number_of_Teacher(nOt);
		cout << "\n";
	}


	cout << " _____________________________________________\n";
	cout << "|                DATA OF STUDENT              |\n";
	cout << "|_____________________________________________|\n\n\n";
	cout << "Enter Number Of Student : ";
	cin >> student;
	Student* s;
	s = new Student[student];

	cout << "Enter Number Of Courses For Each Student : ";
	cin >> noc;
	cout << "\n";
	for (int i = 0; i < student; i++)
	{
		cout << "Enter Student " << i + 1 << " Data\n";
		cout << "==============================================\n";
		cin >> s[i];
		s[i].setNumber_of_Course(noc);
		cout << "\n";
	}

	cout << " _____________________________________________\n";
	cout << "|                DATA OF Faculty              |\n";
	cout << "|_____________________________________________|\n\n\n";
	cout << "Enter Number Of Teacher : ";
	cin >> teacher;
	Faculty* f;
	f = new Faculty[teacher];

	cout << "Enter Number Of Coures For Each Teacher : ";
	cin >> size;
	cout << "\n";
	for (int i = 0; i < teacher; i++)
	{
		cout << "Enter Teacher " << i + 1 << " Data\n";
		cout << "==============================================\n";
		cin >> f[i];
		f[i].set_Course_List_Size(size);
		cout << "\n";
	}


	Re cs;
	cs.set_Number_Of_Course(noc);
	cs.set_Number_Of_Student(nos);
	cs.set_Number_of_Teacher(size);
	for (int i = 0; i < noc; i++)
	{
		cs.set_Course_List(&c[i]);
	}
	for (int i = 0; i < nos; i++)
	{
		cs.set_Student_List(&s[i]);
	}
	for (int i = 0; i < size; i++)
	{
		cs.set_Teacher_List(&f[i]);
	}

	cout << "\n-----------------------------------------------------";
	cout << "\n\tCourse And Student ";
	cout << "\n-----------------------------------------------------\n";
	for (int i = 0; i < nos; i++)
	{
		do {
			cout << "Enter Student ID : ";
			cin >> sid;
			for (int j = 0; j < student; j++)
			{
				if (sid == s[j].get_ID())
				{
					sindux = j;
					break;
				}
			}
			if (sindux != -1)
			{
				break;
			}
		} while (true);

		for (int j = 0; j < s[sindux].getNumber_of_Course(); j++)
		{
			do {
				cout << "Enter Course " << j + 1 << " Code : ";
				cin >> cid;
				for (int k = 0; k < course; k++)
				{
					if (cid == c[k].get_Code())
					{
						cindux = k;
						break;
					}
				}
				if (cindux != -1)
				{
					break;
				}
			} while (true);

			cs.Connect_Student_And_Course(sindux, cindux);
		}
		cout << "\n-----------------------------------------------------\n";
	}

	cout << "\n-----------------------------------------------------";
	cout << "\n\tCourse And Teacher ";
	cout << "\n-----------------------------------------------------\n";
	for (int i = 0; i < size; i++)
	{
		do {
			cout << "Enter Course Code : ";
			cin >> cid;
			for (int j = 0; j < course; j++)
			{
				if (cid == c[j].get_Code())
				{
					cindux = j;
					break;
				}
			}
			if (cindux != -1)
			{
				break;
			}
		} while (true);

		for (int j = 0; j < c[cindux].get_Number_of_Teacher(); j++)
		{
			do {
				cout << "Enter Teacher " << j + 1 << " ID : ";
				cin >> tid;
				for (int k = 0; k < teacher; k++)
				{
					if (tid == f[k].get_Faculty_ID())
					{
						tindux = k;
						break;
					}
				}
				if (tindux != -1)
				{
					break;
				}
			} while (true);
			cs.Connect_Course_And_Faculty(cindux, tindux);
		}
		cout << "\n-----------------------------------------------------\n";
	}

	cout << "\n\n";
	cout << "!===================================!\n";
	cout << "|          Studetn INFO             |\n";
	cout << "!===================================!\n";
	for (int i = 0; i < student; i++)
	{
		cout << "\tStudent " << i + 1 << "\n";
		cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		s[i].DisplayStudent();
		s[i].Display_Course_List();
		cout << "\n";
	}


	cout << "\n\n";
	cout << "!==================================!\n";
	cout << "|           Course INFO            |\n";
	cout << "!==================================!\n";
	for (int i = 0; i < course; i++)
	{
		cout << "\tCourse " << i + 1 << "\n";
		cout << "<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		c[i].DisplayCourse();
		c[i].Display_Student_List();
		c[i].Display_Faculty_List();
		cout << "\n";
	}

	cout << "\n\n";
	cout << "!===================================!\n";
	cout << "|          Faculty INFO             |\n";
	cout << "!===================================!\n";
	for (int i = 0; i < teacher; i++)
	{
		cout << "\tTeacher " << i + 1 << "\n";
		cout << "<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
		cout << "dfsjglh";
		f[i].Display_Faculty();
		f[i].Display_Course_List();
		cout << "\n";
	}

	Admin A;
	cin >> A;
	A.set_Number_of_Course(course);
	A.set_Number_of_Student(student);
	A.set_Number_of_Teacher(teacher);
	A.set_Course(c);
	A.set_Student(s);
	A.set_Teacher(f);

	cout << "\n\n\tADMIN INFO ";
	cout << "\n****************************************************\n";
	A.Display_INFO();

	cout << "\n\n\tCourse INFO";
	cout << "\n****************************************************\n";
	A.Display_Course_INFO();

	cout << "\n\n\tStudent INFO";
	cout << "\n****************************************************\n";
	A.Display_Student_INFO();

	cout << "\n\n\tFaculty INFO";
	cout << "\n****************************************************\n";
	A.Display_Faculty_INFO();
}
