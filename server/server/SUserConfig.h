#pragma once
#include "tinyxml.h"
#include "ConfigBase.h"
#include "ObjectBase.h"
#include "ListObject.h"

class CSUserConfig :
	public CConfigBase
{
public:
	const char *USER_XML_NAME = "name";
	const char *USER_XML_ID = "id";
	const char *USER_XML_PASSWD = "passwd";
	
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
	int Init(char *filepath, CListObject* list);
};

