#include "pch.h"
#include "CObjectMgr.h"

CObjectMgr::CObjectMgr()
{

}
CObjectMgr::~CObjectMgr()
{

}

void CObjectMgr::Render(HDC _hdc)
{
	for (int i = 0; i < (int)OBJECT::OBJECT_END; ++i)
	{
		auto lst = m_mapObject[(OBJECT)i].begin();
		while (lst != m_mapObject[(OBJECT)i].end())
		{
			(*lst)->Render(_hdc);
			++lst;
		}
	}
}

void CObjectMgr::Init()
{
	for (int i = 0; i < (int)OBJECT::OBJECT_END; ++i)
	{
		std::list<CObject*> temp;
		m_mapObject.insert({ (OBJECT)i,temp });
	}
}
void CObjectMgr::AddObject(OBJECT _type, CObject* _obj)
{
	auto lstiter = m_mapObject.find(_type);
	(*lstiter).second.push_back(_obj);
}
