#pragma once
#include"CObject.h"

class CObjectMgr
{
	SINGLE(CObjectMgr);
public:
	void Init();
	void RegisterObject(OBJECT _type, CObject* _obj);
private:
	std::map<OBJECT, std::list<CObject*>> m_mapObject;
};