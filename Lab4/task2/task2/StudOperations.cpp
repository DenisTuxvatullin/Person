#include "stdafx.h"
#include "StudOperations.h"
#include "UniverOperations.h"
#include "University.h"
#include "Student.h"

void StudOperations::PrintStudentInfo(const std::shared_ptr<const CStudent> &student)
{
	std::cout << "Name: " << student->GetName() << std::endl;
	std::cout << (student->IsMale() ? "Male" : "Female") << std::endl;
	std::cout << "Age: " << student->GetAge() << std::endl;
	std::cout << "Growth: " << student->GetGrowth() << std::endl;
	std::cout << "Weight: " << student->GetWeight() << std::endl;
	std::cout << "Study year: " << student->GetYearOfStudy() << std::endl;
	std::cout << "University name: " << student->GetUniversity()->GetName() << std::endl << std::endl;
}

void StudOperations::ChangeUniversityForStudent(const Univer &university,
	std::set<Student> &students, Student &student)
{
	student->SetUniversity(university);
	students.insert(student);
}

bool StudOperations::ChangeUniversityName(const std::set<Univer> &universities, const Univer &university,
	const std::string &newName)
{
	if (!uOperation->IsUniversityExist(universities, newName))
	{
		university->SetName(newName);
		return true;
	}
	return false;
}

bool StudOperations::DeleteStudent(std::set<Student> &students, Student &student)
{
	return students.erase(student) == 1;
}

void StudOperations::PrintStudents(const std::shared_ptr<const CUniversity> &university,
	const std::set<Student> &students)
{
	auto it = std::find_if(students.begin(), students.end(), [&](Student student)
	{
		if (student->GetUniversity() == university)
		{
			StudOperations::PrintStudentInfo(student);
		}
		return student;
	});
}

void StudOperations::PrintAllStudents(const std::set<Student> &students)
{
	for (auto &student : students)
	{
		StudOperations::PrintStudentInfo(student);
	}
}

void StudOperations::ChangeAge(Student &student, int age)
{
	student->SetAge(age);
}

void StudOperations::ChangeHeight(Student &student, int growth)
{
	student->SetGrowth(growth);
}

void StudOperations::ChangeYear(Student &student, int year)
{
	student->SetYearOfStudy(year);
}

void StudOperations::AddStudent(std::set<Student> &students, Student &student)
{
	students.insert(student);
}

std::set<Student> StudOperations::LoadStudents(const std::set<Univer> &universities, const std::string &sFileName)
{
	std::set<Student> students;
	std::ifstream fin(sFileName);
	std::string name;
	std::string age;
	std::string growth;
	std::string studyYear;
	std::string weight;
	std::string male;
	std::string universityName;
	while (getline(fin, name))
	{
		getline(fin, age);
		getline(fin, growth);
		getline(fin, weight);
		getline(fin, studyYear);
		getline(fin, male);
		getline(fin, universityName);
		Univer university;
		for (auto const &curUniversity : universities)
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

void StudOperations::SaveStudents(const std::set<Student> &students, const std::string &sFileName)
{
	std::ofstream fout(sFileName);
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

std::string StudOperations::GetStudentInfo()
{
	std::string student;
	std::cout << "Input student's name : ";
	std::cin >> student;
	return student;
}

void StudOperations::GetChangeableStudent(int &age, int &growth, int &weight, int &studyYear)
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

Student StudOperations::GetNewStudent(const std::set<Univer> &universities)
{
	std::string name;
	std::cout << "Input student's name : ";
	std::cin >> name;
	int age;
	int	growth;
	int	weight;
	int	studyYear;
	GetChangeableStudent(age, growth, weight, studyYear);
	std::string gender;
	std::cout << "gender male/female : ";
	std::cin >> gender;
	bool isMale = gender == "male";
	auto university = uOperation->GetUniversity(universities, uOperation->GetUniversityInfo());
	return std::make_shared<CStudent>(name, isMale, age, weight, growth, university, studyYear);
}

Student StudOperations::GetStudent(const std::set <Student> &students, const std::string &name)
{
	auto it = std::find_if(students.begin(), students.end(), [&](Student student)
	{
		return student->GetName() == name;
	});
	if (it != students.end())
	{
		return *it;
	}
	return nullptr;
}