#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <set>
#include "StudOperations.h"
const std::string STUDENTS_FILE_NAME = "1-students.txt";

void PrintStudentInfo(const std::shared_ptr<const CStudent> &student)
{
	std::cout << "Name: " << student->GetName() << std::endl;
	std::cout << (student->IsMale() ? "Male" : "Female") << std::endl;
	std::cout << "Age: " << student->GetAge() << std::endl;
	std::cout << "Growth: " << student->GetGrowth() << std::endl;
	std::cout << "Weight: " << student->GetWeight() << std::endl;
	std::cout << "Study year: " << student->GetYearOfStudy() << std::endl;
	std::cout << "University name: " << student->GetUniversity()->GetName() << std::endl << std::endl;
}

void ChangeUniversityForStudent(const std::shared_ptr<CUniversity> &university,
	std::set<std::shared_ptr<CStudent>> &students, std::shared_ptr<CStudent> &student)
{
	students.erase(student);
	student->SetUniversity(university);
	students.insert(student);
}

bool ChangeUniversityName(const std::set<std::shared_ptr<CUniversity>> &universities, const std::shared_ptr<CUniversity> &university,
	const std::string &newName)
{
	if (!IsUniversityExist(universities, newName))
	{
		university->SetName(newName);
		return true;
	}

	return false;
}

bool DeleteStudent(std::set<std::shared_ptr<CStudent>> &students, std::shared_ptr<CStudent> &student)
{
	if (students.erase(student))
	{
		return true;
	}
	return false;
}



void PrintStudents(const std::shared_ptr<const CUniversity> &university,
	const std::set<std::shared_ptr<CStudent>> &students)
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

void PrintAllStudents(const std::set<std::shared_ptr<CStudent>> &students)
{
	size_t i = 1;
	for (auto &student : students)
	{
		PrintStudentInfo(student);
	}
}



void ChangeAge(std::shared_ptr<CStudent> &student, int age)
{
	student->SetAge(age);
}

void ChangeHeight(std::shared_ptr<CStudent> &student, int growth)
{
	student->SetGrowth(growth);
}

void ChangeYear(std::shared_ptr<CStudent> &student, int year)
{
	student->SetYearOfStudy(year);
}

void AddStudent(std::set<std::shared_ptr<CStudent>> &students, std::shared_ptr<CStudent> &student)
{
	students.insert(student);
}

std::set<std::shared_ptr<CStudent>> LoadStudents(const std::set<std::shared_ptr<CUniversity>> &universities)
{
	std::set<std::shared_ptr<CStudent>> students;

	std::ifstream fin(STUDENTS_FILE_NAME);
	std::string name, age, growth, studyYear, weight, male, universityName;
	while (getline(fin, name))
	{
		getline(fin, age);
		getline(fin, growth);
		getline(fin, weight);
		getline(fin, studyYear);
		getline(fin, male);
		getline(fin, universityName);

		std::shared_ptr<CUniversity> university;
		for (auto &curUniversity : universities)
		{
			if (curUniversity->GetName() == universityName)
			{
				university = curUniversity;
				break;
			}
		}

		bool isMale = (male == "male");

		auto student = std::make_shared<CStudent>(name, isMale, stoi(age), stoi(weight), stoi(growth), university, stoi(studyYear));
		students.insert(student);
	}
	return students;
}

void SaveStudents(const std::set<std::shared_ptr<CStudent>> &students)
{
	std::ofstream fout(STUDENTS_FILE_NAME);

	for (auto &curStudent : students)
	{
		fout << curStudent->GetName() << std::endl << curStudent->GetAge() << std::endl << curStudent->GetGrowth() << std::endl;
		fout << curStudent->GetWeight() << std::endl; fout << curStudent->GetYearOfStudy() << std::endl;

		if (curStudent->IsMale())
		{
			fout << "male" << std::endl;
		}
		else
		{
			fout << "female" << std::endl;
		}

		fout << curStudent->GetUniversity()->GetName() << std::endl;
	}
}



std::string GetStudentInfo()
{
	std::string student;
	std::cout << "Input student's name : ";
	std::cin >> student;

	return student;
}



void GetChangeableStudent(int &age, int &growth, int &weight, int &studyYear)
{
	std::cout << "Input student's age : ";
	std::cin >> age;

	std::cout << "Input student's height : ";
	std::cin >> growth;

	std::cout << "Input student's weight : ";
	std::cin >> weight;

	std::cout << "Input student's year of study : ";
	std::cin >> studyYear;
}

std::shared_ptr<CStudent> GetNewStudent(const std::set<std::shared_ptr<CUniversity>> &universities)
{
	std::string name;
	std::cout << "Input student's name : ";
	std::cin >> name;

	int age, growth, weight, studyYear;
	GetChangeableStudent(age, growth, weight, studyYear);

	std::string gender;
	std::cout << "gender male/female : ";
	std::cin >> gender;
	bool isMale = gender == "male";

	auto university = GetUniversity(universities, GetUniversityInfo());

	return std::make_shared<CStudent>(name, isMale, age, weight, growth, university, studyYear);
}

std::shared_ptr<CStudent> GetStudent(const std::set <std::shared_ptr<CStudent>> &students, const std::string &name)
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