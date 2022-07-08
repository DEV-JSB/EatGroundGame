#pragma once
#include"CObject.h"

class CObjectMgr
{
	SINGLE(CObjectMgr);
public:
	void Init();
	void AddObject(OBJECT _type, CObject* _obj);
	std::list<CObject*> GetObjectList(OBJECT _type) { return m_mapObject[_type]; }
private:
	std::map<OBJECT, std::list<CObject*>> m_mapObject;
};