// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task2/Person.h"
#include "../task2/University.h"
#include "../task2/Student.h"

BOOST_AUTO_TEST_CASE(TestPerson)
{
	CPerson person("Daniel", true, 20, 70, 180);
	BOOST_CHECK_EQUAL(person.GetName(), "Daniel");
	BOOST_CHECK_EQUAL(person.GetAge(), 20);
	BOOST_CHECK_EQUAL(person.GetWeight(), 70);
	BOOST_CHECK_EQUAL(person.GetGrowth(), 180);
	BOOST_CHECK(person.IsMale());

	person.SetName("Seraf");
	BOOST_CHECK_EQUAL(person.GetName(), "Seraf");

	person.SetAge(30);
	BOOST_CHECK_EQUAL(person.GetAge(), 30);
	person.SetAge(20);
	BOOST_CHECK_EQUAL(person.GetAge(), 30);

	person.SetWeight(60);
	BOOST_CHECK_EQUAL(person.GetWeight(), 60);

	person.SetGrowth(190);
	BOOST_CHECK_EQUAL(person.GetGrowth(), 190);
	person.SetGrowth(185);
	BOOST_CHECK_EQUAL(person.GetGrowth(), 190);
}

BOOST_AUTO_TEST_CASE(TestUniversity)
{
	CUniversity university("Volgatech");
	BOOST_CHECK_EQUAL(university.GetName(), "Volgatech");

	university.SetName("VolgaVolgatech");
	BOOST_CHECK_EQUAL(university.GetName(), "VolgaVolgatech");

}

BOOST_AUTO_TEST_CASE(TestStudent)
{
	auto university = make_shared<CUniversity>("Volgatech");
	CStudent student("Daniel", true, 20, 70, 180, university, 1);
	BOOST_CHECK_EQUAL(student.GetName(), "Daniel");
	BOOST_CHECK_EQUAL(student.GetAge(), 20);
	BOOST_CHECK_EQUAL(student.GetWeight(), 70);
	BOOST_CHECK_EQUAL(student.GetGrowth(), 180);
	BOOST_CHECK_EQUAL(student.GetUniversity(), university);
	BOOST_CHECK(student.IsMale());
	BOOST_CHECK_EQUAL(student.GetYearOfStudy(), 1);
	BOOST_CHECK_EQUAL(university->GetName(), "Volgatech");

	auto universityNew = make_shared<CUniversity>("VolgaVolgatech");
	student.SetUniversity(universityNew);
	BOOST_CHECK_EQUAL(student.GetUniversity(), universityNew);

	student.SetYearOfStudy(2);
	BOOST_CHECK_EQUAL(student.GetYearOfStudy(), 2);
	student.SetYearOfStudy(1);
	BOOST_CHECK_EQUAL(student.GetYearOfStudy(), 2);
}