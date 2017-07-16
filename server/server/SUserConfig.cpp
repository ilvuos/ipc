#include "stdafx.h"
#include "SUserConfig.h"


CSUserConfig::CSUserConfig()
{
	mpTiXmldoc = NULL;
	mpTiXmlnode = NULL;
	mpTiXmltodoElement = NULL;
	mpTiXmlitemElement = NULL;
}

CSUserConfig::~CSUserConfig()
{
}
int CSUserConfig::Writer(char *name, int id)
{
	int nID;
	char passwd[]="123456";
	TiXmlElement attendee("add");
	attendee.SetAttribute(USER_XML_NAME, name);
	attendee.SetAttribute(USER_XML_ID, id);
	attendee.SetAttribute(USER_XML_PASSWD, passwd);
	
	assert(mpTiXmlnode);
	mpTiXmlitemElement = mpTiXmlnode->ToElement();
	assert(mpTiXmlitemElement);

	while (mpTiXmlitemElement) {
		mpTiXmlitemElement->QueryIntAttribute(USER_XML_ID, &nID);
		if (nID == id) {
			return 0;
		}
		mpTiXmlitemElement = mpTiXmlitemElement->NextSiblingElement();
	}

	mpTiXmlnode = mpTiXmltodoElement->LastChild();
	mpTiXmlitemElement = mpTiXmlnode->ToElement();
	mpTiXmltodoElement->InsertAfterChild(mpTiXmlitemElement, attendee);

	mpTiXmldoc->SaveFile();
	return 0;
}
int CSUserConfig::Remove(int id)
{
	int nID = 0;
	assert(mpTiXmlnode);
	mpTiXmlitemElement = mpTiXmlnode->ToElement();
	assert(mpTiXmlitemElement);
	while (mpTiXmlitemElement){
		 mpTiXmlitemElement->QueryIntAttribute(USER_XML_ID,&nID);
		 if (nID == id) {
			 mpTiXmltodoElement->RemoveChild(mpTiXmlitemElement);
			 mpTiXmlitemElement = mpTiXmlnode->ToElement();
			 continue;
		 }
		 mpTiXmlitemElement = mpTiXmlitemElement->NextSiblingElement();
	}

	mpTiXmlitemElement = NULL;
	mpTiXmldoc->SaveFile();
	return 0;
}

int CSUserConfig::Init(char *filepath, CListObject* list)
{
	const char    *pBuffer = NULL;

	if(!mpTiXmldoc)
		mpTiXmldoc = new TiXmlDocument(filepath);
	bool loadOkay = mpTiXmldoc->LoadFile();
	if (!loadOkay)
		return -1;
		
	mpTiXmlnode = mpTiXmldoc->FirstChild("configuration");
	assert(mpTiXmlnode);
	mpTiXmltodoElement = mpTiXmlnode->ToElement();
	assert(mpTiXmltodoElement);

	mpTiXmlnode = mpTiXmltodoElement->FirstChild("user");	// This skips the "PDA" comment.
	assert(mpTiXmlnode);
	mpTiXmltodoElement = mpTiXmlnode->ToElement();
	assert(mpTiXmltodoElement);

	mpTiXmlnode = mpTiXmltodoElement->FirstChildElement();
	assert(mpTiXmlnode);
	mpTiXmlitemElement = mpTiXmlnode->ToElement();
	assert(mpTiXmlitemElement);

    if(!list)
		return -1;
	
	while (mpTiXmlitemElement){
		pBuffer = mpTiXmlitemElement->Attribute(USER_XML_NAME);
		pBuffer = mpTiXmlitemElement->Attribute(USER_XML_ID);
		mpTiXmlitemElement = mpTiXmlitemElement->NextSiblingElement();
	}
	return 0;
}
