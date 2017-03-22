// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Person.h"
#include "Student.h"
#include "University.h"
typedef std::set<std::shared_ptr<CUniversity>> sUniver;
typedef std::set<std::shared_ptr<CStudent>> sStudent;

static const enum
{	
	ADD_UNIVERSITY = 1,
	DELETE_UNIVERSITY = 2,
	ADD_STUDENT = 3,
	DELETE_STUDENT = 4,
	CHANGE_UNIVERSITY = 5,
	CHANGE_STUDENT = 6,
	CHANGE_STUDENTS_UNIVERSITY = 7,
	PRINT_UNIVERSITIES = 8,
	PRINT_STUDENTS_FROM_UNIVERSITY = 9,
	PRINT_STUDENT = 10
};

void PrintActions()
{
	std::cout << "1. Add university" << std::endl;
	std::cout << "2. Delete university" << std::endl;
	std::cout << "3. Add student				8. Print universities" << std::endl;
	std::cout << "4. Delete student			9. Print students from university" << std::endl;
	std::cout << "5. Change university			10. Print students" << std::endl;
	std::cout << "6. Change student" << std::endl;
	std::cout << "7. Change student's university " << std::endl << std::endl;

}

void ActionAddUniversity(sUniver &universities)
{
	if (uOperation->AddUniversity(universities, uOperation->GetUniversityInfo()))
	{
		std::cout << "University has added" << std::endl;
		return;
	}
	std::cout << "Error adding university" << std::endl;
}

void ActionDeleteUniversity(sUniver &universities, sStudent &students)
{
	if (auto university = uOperation->GetUniversity(universities, uOperation->GetUniversityInfo()))
	{
		if (uOperation->DeleteUniversity(universities, university, students))
		{
			std::cout << "Deleted" << std::endl;
			return;
		}
		std::cout << "Error deleting" << std::endl;
	}
}

void ActionAddStudent(sUniver &universities, sStudent &students)
{
	if (auto student = sOperation->GetNewStudent(universities))
	{
		if (student->GetUniversity())
		{
			sOperation->AddStudent(students, student);
			std::cout << "Student has added" << std::endl;
			return;
		}
		std::cout << "Error adding" << std::endl;
	}
}

void ActionDeleteStudent(sStudent &students)
{
	if (auto student = sOperation->GetStudent(students, sOperation->GetStudentInfo()))
	{
		if (sOperation->DeleteStudent(students, student))
		{
			std::cout << "Deleted" << std::endl;
			return;
		}
		std::cout << "Error deleting" << std::endl;
	}
}

void ActionChangeUniversity(sUniver &universities)
{
	std::string universityInfo = uOperation->GetUniversityInfo();
	if (auto university = uOperation->GetUniversity(universities, universityInfo))
	{
		std::string newName = uOperation->GetUniversityInfo();
		university->SetName(newName);
		std::cout << "Name has changed" << std::endl;
		return;
	}
	std::cout << "Error changing name" << std::endl;
}

void ActionChangeStudent(sStudent &students)
{
	if (auto student = sOperation->GetStudent(students, sOperation->GetStudentInfo()))
	{
		int age, growth, weight, studyYear;
		sOperation->GetChangeableStudent(age, growth, weight, studyYear);
		student->SetAge(age);
		student->SetGrowth(growth);
		student->SetYearOfStudy(studyYear);
		student->SetWeight(weight);
		std::cout << "Changed" << std::endl;
		return;
	}
	std::cout << "No such student" << std::endl;
}

void ActionChangeStudentUniversity(sUniver &universities, sStudent &students)
{
	if (auto student = sOperation->GetStudent(students, sOperation->GetStudentInfo()))
	{
		if (auto university = uOperation->GetUniversity(universities, uOperation->GetUniversityInfo()))
		{
			sOperation->ChangeUniversityForStudent(university, students, student);
			std::cout << "Changed" << std::endl;
			return;
		}
		std::cout << "No such university" << std::endl;
		return;
	}
	std::cout << "No such student" << std::endl;
}

void ActionPrintStudentsFromUniversity(sUniver &universities, sStudent &students)
{
	if (auto university = uOperation->GetUniversity(universities, uOperation->GetUniversityInfo()))
	{
		sOperation->PrintStudents(university, students);
		return;
	}
	std::cout << "No matches" << std::endl;
}

void DialogWithUser(sUniver &universities, sStudent &students)
{
	int choice = 1;
	PrintActions();
	std::cout << "Input command: ";
	while (std::cin >> choice)
	{
		switch (choice)
		{
			case ADD_UNIVERSITY:
			{
				ActionAddUniversity(universities);
				break;
			}
			case DELETE_UNIVERSITY:
			{
				ActionDeleteUniversity(universities, students);
				break;
			}
			case ADD_STUDENT:
			{
				ActionAddStudent(universities, students);
				break;
			}
			case DELETE_STUDENT:
			{
				ActionDeleteStudent(students);
				break;
			}
			case CHANGE_UNIVERSITY:
			{
				ActionChangeUniversity(universities);
				break;
			}
			case CHANGE_STUDENT:
			{
				ActionChangeStudent(students);
				break;
			}
			case CHANGE_STUDENTS_UNIVERSITY:
			{
				ActionChangeStudentUniversity(universities, students);
				break;
			}
			case PRINT_UNIVERSITIES:
			{
				  uOperation->PrintUniversities(universities);
				  break;
			}
			case PRINT_STUDENTS_FROM_UNIVERSITY:
			{
				ActionPrintStudentsFromUniversity(universities, students);
				break;
			}
			case PRINT_STUDENT:
			{
				sOperation->PrintAllStudents(students);
				break;
			}
		}
		std::cout << "Input command: ";
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Incorrect number of param");
		return 1;
	}
	std::string sFilename = argv[1];
	std::string uFilename = argv[2];
	auto universities = uOperation->LoadUniversities(uFilename);
	auto students = sOperation->LoadStudents(universities, sFilename);
	DialogWithUser(universities, students);
	uOperation->SaveUniversities(universities, uFilename);
	sOperation->SaveStudents(students, sFilename);
	return 0;
}

