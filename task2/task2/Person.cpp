#include "stdafx.h"
#include "Person.h"


CPerson::CPerson(unsigned short age, string name, unsigned short weight, unsigned short growth, bool isMale)
	: p_name(move(name)), p_isMale(isMale),
	p_age(age), p_weight(weight), p_growth(growth)
{

}

CPerson::~CPerson()
{
}

unsigned short CPerson::GetAge()const
{
	return p_age;
}
void CPerson::SetAge(unsigned short age)
{
	if (age > p_age)
	{
		p_age = age;
	}
}

unsigned short CPerson::GetWeight()const
{
	return p_weight;
}
void CPerson::SetWeight(unsigned short weight)
{
	if (weight > 0)
	{
		p_weight = weight;
	}
}

unsigned short CPerson::GetGrowth()const
{
	return p_growth;
}
void CPerson::SetGrowth(unsigned short growth)
{
	if (growth > p_growth)
	{
		p_growth = growth;
	}
}

string CPerson::GetName()const
{
	return p_name;
}
void CPerson::SetName(string name)
{
	p_name = move(name);
}
