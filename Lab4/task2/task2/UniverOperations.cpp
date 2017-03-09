#include "stdafx.h"
#include <set>
#include <iostream>
#include <fstream>
#include "UniverOperations.h"
#include <memory>

const std::string UNIVERSITIES_FILE_NAME = "2-univer.txt";

bool IsUniversityExist(const std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name)
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

void DeleteAllStudentsFromSameUniversity(std::set<std::shared_ptr<CStudent>> &students,
	std::shared_ptr<CUniversity> &university)
{
	for (auto &student : students)
	{
		if (student->GetUniversity() == university)
		{
			students.erase(student);
		}
	}
}

std::set<std::shared_ptr<CUniversity>> LoadUniversities()
{
	std::set<std::shared_ptr<CUniversity>> universities;

	std::ifstream fin(UNIVERSITIES_FILE_NAME);
	std::string name;

	while (getline(fin, name))
	{
		auto university = std::make_shared<CUniversity>(name);
		universities.insert(university);
	}

	return universities;
}

bool DeleteUniversity(std::set<std::shared_ptr<CUniversity>> &universities,
	std::shared_ptr<CUniversity> &university, std::set<std::shared_ptr<CStudent>> &students)
{
	if (universities.find(university) != universities.end())
	{
		DeleteAllStudentsFromSameUniversity(students, university);
		universities.erase(university);
		university = nullptr;
	}
	return true;
}

void SaveUniversities(const std::set<std::shared_ptr<CUniversity>> &universities)
{
	std::ofstream fout(UNIVERSITIES_FILE_NAME);

	for (auto &curUniversity : universities)
	{
		fout << curUniversity->GetName() << std::endl;
	}
}

std::string GetUniversityInfo()
{
	std::string university;
	std::cout << "Input university name : ";
	std::cin >> university;

	return university;
}

std::shared_ptr<CUniversity> GetUniversity(const std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name)
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



bool AddUniversity(std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name)
{
	if (!IsUniversityExist(universities, name))
	{
		auto universityPtr = std::make_shared<CUniversity>(name);
		universities.insert(universityPtr);

		return true;
	}

	return false;
}

void PrintUniversities(const std::set<std::shared_ptr<CUniversity>> &universities)
{
	size_t i = 1;
	for (auto &university : universities)
	{
		std::cout << university->GetName() << std::endl;
	}
}
