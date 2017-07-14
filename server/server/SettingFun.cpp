#include "stdafx.h"
#include "SettingFun.h"
#define _USER_CONFIG_XML_ "D:\\kevin\\server\\server\\Debug\\user_config.xml"

CSettingFun::CSettingFun()
{
	mpSuserConfig = NULL;
	mpUserList = NULL;
}


CSettingFun::~CSettingFun()
{
}
int CSettingFun::Init() 
{
	mpSuserConfig = new CSUserConfig();
	mpUserList = new CDoubleList();
	mpSuserConfig->Init(_USER_CONFIG_XML_, mpUserList);
	return 0;
}