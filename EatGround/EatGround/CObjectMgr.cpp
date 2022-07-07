#include "pch.h"
#include "CObjectMgr.h"

CObjectMgr::CObjectMgr()
{

}
CObjectMgr::~CObjectMgr()
{

}

void CObjectMgr::Init()
{
	std::list<CObject*> temp;
	for (int i = 0; i < (int)OBJECT::OBJECT_END; ++i)
	{
		m_mapObject.insert({ (OBJECT)i,temp });
	}
}
void CObjectMgr::RegisterObject(OBJECT _type, CObject* _obj)
{
	auto lstiter = m_mapObject.find(_type);
	(*lstiter).second.push_back(_obj);
}
