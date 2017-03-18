#include "stdafx.h"
#include "University.h"

std::string CUniversity::GetName() const
{
	return m_name;
}

void CUniversity::SetName(const std::string& name)
{
	m_name = move(name);
}

CUniversity::CUniversity(std::string university)
	:m_name(move(university))
{}

CUniversity::~CUniversity()
{}