// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Person.h"
#include "Student.h"
#include "University.h"
#include <set>
#include <iostream>
#include <fstream>
#include "UniverOperations.h"
#include "StudOperations.h"
#include <stdlib.h>



void PrintActions()
{
	std::cout << "1. Add university" << std::endl;
	std::cout << "2. Delete university" << std::endl;
	std::cout << "3. Add student				8. Print universities" << std::endl;
	std::cout << "4. Delete student			9. Print students from university" << std::endl;
	std::cout << "5. Change university			10. Print students" << std::endl;
	std::cout << "6. Change student			11. Clear" << std::endl;
	std::cout << "7. Change student's university		0. Exit" << std::endl << std::endl;

}

void MainActions(std::set<std::shared_ptr<CUniversity>> &universities, std::set<std::shared_ptr<CStudent>> &students)
{
	int choice = 1;
	PrintActions();
	while (choice != 0)
	{
		std::cout << "Input command: ";
		std::cin >> choice;
		switch (choice)
		{
			case 1:
			{
				  if (AddUniversity(universities, GetUniversityInfo()))
				  {
					  std::cout << "University has added" << std::endl;
					  break;
				  }
				  std::cout << "Error adding university" << std::endl;
				  break;
			}
			case 2:
			{
				  if (auto university = GetUniversity(universities, GetUniversityInfo()))
				  {
					  if (DeleteUniversity(universities, university, students))
					  {
						  std::cout << "Deleted" << std::endl;
						  break;
					  }
					  std::cout << "Error deleting" << std::endl;
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
						  std::cout << "Student has added" << std::endl;
						  break;
					  }
					  std::cout << "Error adding" << std::endl;
				  }
				  break;
			}
			case 4:
			{
				  if (auto student = GetStudent(students, GetStudentInfo()))
				  {
					  if (DeleteStudent(students, student))
					  {
						  std::cout << "Deleted" << std::endl;
						  break;
					  }
					  std::cout << "Error deleting" << std::endl;
				  }
				  break;
			}
			case 5:
			{
				  std::string universityInfo = GetUniversityInfo();
				  if (auto university = GetUniversity(universities, universityInfo))
				  {
					  std::string newName = GetUniversityInfo();
					  university->SetName(newName);
					  std::cout << "Name has changed" << std::endl;
					  break;
				  }
				  std::cout << "Error changing name" << std::endl;
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
					  std::cout << "Changed" << std::endl;
					  break;
				  }
				  std::cout << "No such student" << std::endl;
				  break;
			}
			case 7:
			{
				  if (auto student = GetStudent(students, GetStudentInfo()))
				  {
					  if (auto university = GetUniversity(universities, GetUniversityInfo()))
					  {
						  ChangeUniversityForStudent(university, students, student);
						  std::cout << "Changed" << std::endl;
						  break;
					  }
					  std::cout << "No such university" << std::endl;
					  break;
				  }
				  std::cout << "No such student" << std::endl;
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
					  break;
				  }
				  std::cout << "No matches" << std::endl;
				  break;
			}
			case 10:
			{
				   PrintAllStudents(students);
				   break;
			}
			case 11:
			{
				system("cls");
				PrintActions();
				break;
			}

		}
	}
}

int main()
{
	auto universities = LoadUniversities();
	auto students = LoadStudents(universities);

	MainActions(universities, students);
	
	SaveUniversities(universities);
	SaveStudents(students);
	return 0;
}

