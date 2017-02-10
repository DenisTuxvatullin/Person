#pragma once
#include <string>
#include <set>
#include <memory>

using namespace std;
class CUniversity
{
public:
	CUniversity(string university)
		:m_name(move(university))
	{
	}

	~CUniversity()
	{
	}

	string GetName() const
	{
		return m_name;
	}

	void SetName(string name)
	{
		m_name = move(name);
	}


private:
	string m_name;
};

