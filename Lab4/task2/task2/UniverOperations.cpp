#include "stdafx.h"
#include "UniverOperations.h"
UniverOperations::UniverOperations()
{

}

bool UniverOperations::IsUniversityExist(const std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name)
{
	for (const auto &university : universities)
	{
		if (university->GetName() == name)
		{
			return true;
		}
	}
	return false;
}

void UniverOperations::DeleteAllStudentsFromSameUniversity(std::set<std::shared_ptr<CStudent>> &students,
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

std::set<std::shared_ptr<CUniversity>> UniverOperations::LoadUniversities(const std::string &uFilename)
{
	std::set<std::shared_ptr<CUniversity>> universities;
	std::ifstream fin(uFilename);
	std::string name;

	while (getline(fin, name))
	{
		auto university = std::make_shared<CUniversity>(name);
		universities.insert(university);
	}

	return universities;
}

bool UniverOperations::DeleteUniversity(std::set<std::shared_ptr<CUniversity>> &universities,
	std::shared_ptr<CUniversity> &university, std::set<std::shared_ptr<CStudent>> &students)
{
	if (universities.find(university) != universities.end())
	{
		UniverOperations::DeleteAllStudentsFromSameUniversity(students, university);
		universities.erase(university);
		university = nullptr;
	}
	return true;
}

void UniverOperations::SaveUniversities(const std::set<std::shared_ptr<CUniversity>> &universities, const std::string &uFilename)
{
	std::ofstream fout(uFilename);
	for (auto const &curUniversity : universities)
	{
		fout << curUniversity->GetName() << std::endl;
	}
}

std::string UniverOperations::GetUniversityInfo()
{
	std::string university;
	std::cout << "Input university name : ";
	std::getline(std::cin, university);
	std::getline(std::cin, university).clear();
	if (university != "")
	{
		return university;
	}
	return "";
}

std::shared_ptr<CUniversity> UniverOperations::GetUniversity(const std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name)
{
	for (const auto &university : universities)
	{
		if (university->GetName() == name)
		{
			return university;
		}
	}
	return nullptr;
}

bool UniverOperations::AddUniversity(std::set<std::shared_ptr<CUniversity>> &universities, const std::string &name)
{
	if (!UniverOperations::IsUniversityExist(universities, name))
	{
		auto universityPtr = std::make_shared<CUniversity>(name);
		universities.insert(universityPtr);
		return true;
	}
	return false;
}

void UniverOperations::PrintUniversities(const std::set<std::shared_ptr<CUniversity>> &universities)
{
	for (const auto &university : universities)
	{
		std::cout << university->GetName() << std::endl;
	}
}
