#include "stdafx.h"
#include "University.h"


CUniversity::CUniversity(string uName)
	:u_name(move(uName))
{
}


CUniversity::~CUniversity()
{
}

string CUniversity::GetName()const
{
	return u_name;
}
void CUniversity::SetName(string name)
{
	u_name = move(name);
}