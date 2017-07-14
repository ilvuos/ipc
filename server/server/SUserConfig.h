#pragma once
#include "tinyxml.h"
#include "ConfigBase.h"
#include "ObjectBase.h"

class CSUserConfig :
	public CConfigBase
{
public:
	const char *USER_XML_NAME = "name";
	const char *USER_XML_ID = "ID";
	CSUserConfig();
	~CSUserConfig();
protected:
	TiXmlDocument*mpTiXmldoc;
	TiXmlNode*    mpTiXmlnode ;
	TiXmlElement* mpTiXmltodoElement ;
	TiXmlElement* mpTiXmlitemElement ;
public:
	int Writer(char *name,int id);
	int Remove(int id);
	int Open(char *filepath,CObjectBase* list);
};

