// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Person.h"
#include "Student.h"
#include "University.h"
#include <set>
#include <iostream>
#include <fstream>

const string UNIVERSITIES_FILE_NAME = "univer.txt";
const string STUDENTS_FILE_NAME = "students.txt";

bool IsUniversityExist(const set<shared_ptr<CUniversity>> &universities, const string &name)
{
	for (auto &university : universities)
	{
		if (university->GetName() == name)
		{
			return true;
		}
	}

	return false;
}

void PrintUniversities(const set<shared_ptr<CUniversity>> &universities)
{
	size_t i = 1;
	for (auto &university : universities)
	{
		cout << university->GetName() << endl;
	}
}

void PrintStudentInfo(const shared_ptr<const CStudent> &student)
{
	cout << "Name: " << student->GetName() << endl;
	cout << (student->IsMale() ? "Male" : "Female") << endl;
	cout << "Age: " << student->GetAge() << endl;
	cout << "Growth: " << student->GetGrowth() << endl;
	cout << "Weight: " << student->GetWeight() << endl;
	cout << "Study year: " << student->GetYearOfStudy() << endl;
	cout << "University name: " << student->GetUniversity()->GetName() << endl << endl;
}

void ChangeUniversityForStudent(const shared_ptr<CUniversity> &university, 
	set<shared_ptr<CStudent>> &students, shared_ptr<CStudent> &student)
{
	students.erase(student);
	student->SetUniversity(university);
	students.insert(student);
}

bool ChangeUniversityName(const set<shared_ptr<CUniversity>> &universities, const shared_ptr<CUniversity> &university,
	const string &newName)
{
	if (!IsUniversityExist(universities, newName))
	{
		university->SetName(newName);
		return true;
	}

	return false;
}

bool DeleteStudent(set<shared_ptr<CStudent>> &students, shared_ptr<CStudent> &student)
{
	if (students.erase(student))
	{
		return true;
	}
	return false;
}

void DeleteAllStudentsFromSameUniversity(set<shared_ptr<CStudent>> &students,
	shared_ptr<CUniversity> &university)
{
	for (auto &student : students)
	{
		if (student->GetUniversity() == university)
		{
			students.erase(student);
		}
	}
}

bool DeleteUniversity(set<shared_ptr<CUniversity>> &universities,
	shared_ptr<CUniversity> &university, set<shared_ptr<CStudent>> &students)
{
	if (universities.find(university) != universities.end())
	{
		DeleteAllStudentsFromSameUniversity(students, university);
		universities.erase(university);
		university = nullptr;
	}
	return true;
}

void PrintStudents(const shared_ptr<const CUniversity> &university,
	const set<shared_ptr<CStudent>> &students)
{
	size_t i = 1;
	for (auto &student : students)
	{
		if (student->GetUniversity() == university)
		{
			PrintStudentInfo(student);
		}
	}
}

void PrintAllStudents(const set<shared_ptr<CStudent>> &students)
{
	size_t i = 1;
	for (auto &student : students)
	{
		PrintStudentInfo(student);
	}
}

bool AddUniversity(set<shared_ptr<CUniversity>> &universities, const string &name)
{
	if (!IsUniversityExist(universities, name))
	{
		auto universityPtr = make_shared<CUniversity>(name);
		universities.insert(universityPtr);

		return true;
	}

	return false;
}

void ChangeAge(shared_ptr<CStudent> &student, int age)
{
	student->SetAge(age);
}

void ChangeHeight(shared_ptr<CStudent> &student, int growth)
{
	student->SetGrowth(growth);
}

void ChangeYear(shared_ptr<CStudent> &student, int year)
{
	student->SetYearOfStudy(year);
}

void AddStudent(set<shared_ptr<CStudent>> &students, shared_ptr<CStudent> &student)
{
	students.insert(student);
}

set<shared_ptr<CUniversity>> LoadUniversities()
{
	set<shared_ptr<CUniversity>> universities;

	ifstream fin(UNIVERSITIES_FILE_NAME);
	string name;

	while (getline(fin, name))
	{
		auto university = make_shared<CUniversity>(name);
		universities.insert(university);
	}

	return universities;
}

void SaveUniversities(const set<shared_ptr<CUniversity>> &universities)
{
	ofstream fout(UNIVERSITIES_FILE_NAME);

	for (auto &curUniversity : universities)
	{
		fout << curUniversity->GetName() << endl;
	}
}


set<shared_ptr<CStudent>> LoadStudents(const set<shared_ptr<CUniversity>> &universities)
{
	set<shared_ptr<CStudent>> students;

	ifstream fin(STUDENTS_FILE_NAME);
	string name, age, growth, studyYear, weight, male, universityName;
	while (getline(fin, name))
	{
		getline(fin, age);
		getline(fin, growth);
		getline(fin, weight);
		getline(fin, studyYear);
		getline(fin, male);
		getline(fin, universityName);

		shared_ptr<CUniversity> university;
		for (auto &curUniversity : universities)
		{
			if (curUniversity->GetName() == universityName)
			{
				university = curUniversity;
				break;
			}
		}

		bool isMale = (male == "male");
	
		auto student = make_shared<CStudent>(name, isMale, stoi(age), stoi(weight), stoi(growth), university ,stoi(studyYear));
		students.insert(student);
	}
	return students;
}

void SaveStudents(const set<shared_ptr<CStudent>> &students)
{
	ofstream fout(STUDENTS_FILE_NAME);

	for (auto &curStudent : students)
	{
		fout << curStudent->GetName() << endl << curStudent->GetAge() << endl << curStudent->GetGrowth() << endl;
		fout << curStudent->GetWeight() << endl; fout << curStudent->GetYearOfStudy() << endl;
		
		if (curStudent->IsMale())
		{
			fout << "male" << endl;
		}
		else
		{
			fout << "female" << endl;
		}

		fout << curStudent->GetUniversity()->GetName() << endl;
	}
}

string GetUniversityInfo()
{
	string university;
	cout << "Input university name : ";
	cin >> university;

	return university;
}

string GetStudentInfo()
{
	string student;
	cout << "Input student's name : ";
	cin >> student;

	return student;
}

shared_ptr<CUniversity> GetUniversity(const set<shared_ptr<CUniversity>> &universities, const string &name)
{
	for (auto &university : universities)
	{
		if (university->GetName() == name)
		{
			return university;
		}
	}

	return nullptr;
}

void GetChangeableStudent(int &age, int &growth, int &weight, int &studyYear)
{
	cout << "Input student's age : ";
	cin >> age;

	cout << "Input student's height : ";
	cin >> growth;

	cout << "Input student's weight : ";
	cin >> weight;

	cout << "Input student's year of study : ";
	cin >> studyYear;
}

shared_ptr<CStudent> GetNewStudent(const set<shared_ptr<CUniversity>> &universities)
{
	string name;
	cout << "Input student's name : ";
	cin >> name;

	int age, growth, weight, studyYear;
	GetChangeableStudent(age, growth, weight, studyYear);

	string gender;
	cout << "gender male/female : ";
	cin >> gender;
	bool isMale = gender == "male";

	auto university = GetUniversity(universities, GetUniversityInfo());

	return make_shared<CStudent>(name, isMale, age, weight, growth, university, studyYear);
}

shared_ptr<CStudent> GetStudent(const set <shared_ptr<CStudent>> &students, const string &name)
{
	for (auto &student : students)
	{
		if (student->GetName() == name)
		{
			return student;
		}
	}

	return nullptr;
}

void PrintActions()
{
	cout << "1. Add university" << endl;
	cout << "2. Delete university" << endl;
	cout << "3. Add student" << endl;
	cout << "4. Delete student" << endl;
	cout << "5. Change university" << endl;
	cout << "6. Change student" << endl;
	cout << "7. Change student's university" << endl;
	cout << "8. Print universities" << endl;
	cout << "9. Print students from university" << endl;
	cout << "10. Print students" << endl << endl;
	cout << "0. Exit" << endl << endl;
}

void MainActions(set<shared_ptr<CUniversity>> &universities, set<shared_ptr<CStudent>> &students)
{
	int choice = 1;
	PrintActions();
	while (choice != 0)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
				  if (AddUniversity(universities, GetUniversityInfo()))
				  {
					  cout << "University has added";
				  }
				  else
				  {
					  cout << "Error adding university";
				  }
				  cout << endl;
				  break;
		}
		case 2:
		{
				  if (auto university = GetUniversity(universities, GetUniversityInfo()))
				  {
					  if (DeleteUniversity(universities, university, students))
					  {
						  cout << "Deleted";
					  }
					  else
					  {
						  cout << "Error deleting";
					  }
					  cout << endl;
				  }
				  break;
		}
		case 3:
		{
				  if (auto student = GetNewStudent(universities))
				  {
					  if (student->GetUniversity())
					  {
						  AddStudent(students, student);
						  cout << "Student has added";
					  }
					  else
					  {
						  cout << "Error adding";
					  }
					  cout << endl;
				  }
				  break;
		}
		case 4:
		{
				  if (auto student = GetStudent(students, GetStudentInfo()))
				  {
					  if (DeleteStudent(students, student))
					  {
						  cout << "Deleted";
					  }
					  else
					  {
						  cout << "Error deleting";
					  }
					  cout << endl;
				  }
				  break;
		}
		case 5:
		{
				  string universityInfo = GetUniversityInfo();
				  if (auto university = GetUniversity(universities, universityInfo))
				  {
					  string newName = GetUniversityInfo();
					  university->SetName(newName);
					  cout << "Name has changed";
				  }
				  else
				  {
					  cout << "Error changing name";
				  }
				  cout << endl;
				  break;
		}
		case 6:
		{
				  if (auto student = GetStudent(students, GetStudentInfo()))
				  {
					  int age, growth, weight, studyYear;
					  GetChangeableStudent(age, growth, weight, studyYear);
					  student->SetAge(age);
					  student->SetGrowth(growth);
					  student->SetYearOfStudy(studyYear);
					  student->SetWeight(weight);
					  cout << "Changed";
				  }
				  else
				  {
					  cout << "No such student";
				  }
				  cout << endl;
				  break;
		}
		case 7:
		{
				  if (auto student = GetStudent(students, GetStudentInfo()))
				  {
					  if (auto university = GetUniversity(universities, GetUniversityInfo()))
					  {
						  ChangeUniversityForStudent(university, students, student);
						  cout << "Changed";
					  }
					  else
					  {
						  cout << "No such university";
					  }
				  }
				  else
				  {
					  cout << "No such student";
				  }
				  cout << endl;
				  break;
		}
		case 8:
		{
				  PrintUniversities(universities);
				  break;
		}
		case 9:
		{
				  if (auto university = GetUniversity(universities, GetUniversityInfo()))
				  {
					  PrintStudents(university, students);
				  }
				  else
				  {
					  cout << "No matches" << endl;
				  }
				  break;
		}
		case 10:
		{
				   PrintAllStudents(students);
				   break;
		}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto universities = LoadUniversities();
	auto students = LoadStudents(universities);

	MainActions(universities, students);
	
	SaveUniversities(universities);
	SaveStudents(students);
	return 0;
}

