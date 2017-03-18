// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task2/Student.h"

using namespace std;

const string NAME = "STUDENT POLITEHA";
const int STUDY_YEAR = 2, AGE = 12, WEIGHT = 50, GROWTH = 150;
const string UNAME = "PGTU";

struct UniverFixture
{
	CUniversity univer;

	UniverFixture()
		:univer(UNAME)
	{
	}
};

struct StudentFixture
{
	CStudent student;

	StudentFixture()
		:student(NAME, true, AGE, WEIGHT, GROWTH, nullptr, STUDY_YEAR)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(StudentTest, StudentFixture)

BOOST_AUTO_TEST_CASE(StudentDefaultParams)
{
	BOOST_CHECK_EQUAL(student.GetAge(), AGE);
	BOOST_CHECK_EQUAL(student.GetGrowth(), GROWTH);
	BOOST_CHECK_EQUAL(student.GetWeight(), WEIGHT);
	BOOST_CHECK_EQUAL(student.GetYearOfStudy(), STUDY_YEAR);
	BOOST_CHECK_EQUAL(student.GetName(), NAME);
	BOOST_CHECK_EQUAL(student.IsMale(), true);
}

BOOST_AUTO_TEST_CASE(StudentWithChangedParams)
{
	auto universityNew = std::make_shared<CUniversity>("VolgaVolgatech");
	student.SetName("Student");
	BOOST_CHECK_EQUAL(student.GetName(), "Student");
	student.SetAge(20);
	student.SetGrowth(180);
	student.SetWeight(70);
	student.SetYearOfStudy(3);
	student.SetUniversity(universityNew);
	BOOST_CHECK_EQUAL(student.GetAge(), 20);
	BOOST_CHECK_EQUAL(student.GetWeight(), 70);
	BOOST_CHECK_EQUAL(student.GetGrowth(), 180);
	BOOST_CHECK_EQUAL(student.GetUniversity(), universityNew);
	BOOST_CHECK(student.IsMale());
	BOOST_CHECK_EQUAL(student.GetYearOfStudy(), 3);
	BOOST_CHECK_EQUAL(universityNew->GetName(), "VolgaVolgatech");
}

BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////
BOOST_FIXTURE_TEST_SUITE(UniverTest, UniverFixture)

BOOST_AUTO_TEST_CASE(UniverDefaultParams)
{
	BOOST_CHECK_EQUAL(univer.GetName(), UNAME);

}

BOOST_AUTO_TEST_CASE(UniverWithChangedParams)
{
	univer.SetName("MGTU");
	BOOST_CHECK_EQUAL(univer.GetName(), "MGTU");
}

BOOST_AUTO_TEST_SUITE_END()


