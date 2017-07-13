#include "stdafx.h"
#include "FunBase.h"


CFunBase::CFunBase()
{
	mbExist = 0;
}

CFunBase::~CFunBase()
{
}

bool CFunBase::IsExist()
{
	return mbExist;
}