#include "stdafx.h"
#include "Person.h"

CPerson::CPerson(const std::string &name, bool isMale,
	int age, int weight, int growth)
	: m_name(name), m_isMale(isMale),
	m_age(age), m_weight(weight), m_growth(growth)
{
}

std::string CPerson::GetName() const
{
	return m_name;
}

bool CPerson::IsMale() const
{
	return m_isMale;
}

int CPerson::GetAge() const
{
	return m_age;
}

int CPerson::GetGrowth() const
{
	return m_growth;
}

int CPerson::GetWeight() const
{
	return m_weight;
}

void CPerson::SetAge(int age)
{
	if (age > m_age)
	{
		m_age = age;
	}
}

void CPerson::SetName(const std::string& name)
{
	m_name = name;
}

void CPerson::SetGrowth(int growth)
{
	if (growth > m_growth)
	{
		m_growth = growth;
	}
}

void CPerson::SetWeight(int weight)
{
	m_weight = weight;
}