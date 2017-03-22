#include "stdafx.h"
#include "University.h"

CUniversity::CUniversity(const std::string &university)
	: m_name(university)
{
}

std::string CUniversity::GetName() const
{
	return m_name;
}

void CUniversity::SetName(const std::string& name)
{
	m_name = name;
}
