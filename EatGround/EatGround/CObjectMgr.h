#pragma once
#include"CObject.h"

class CObjectMgr
{
	SINGLE(CObjectMgr);
public:
	void Render(HDC _hdc);
	void Init();
	void AddObject(OBJECT _type, CObject* _obj);
	int Release();
	std::list<CObject*> GetObjectList(OBJECT _type) { return m_mapObject[_type]; }
private:
	std::map<OBJECT, std::list<CObject*>> m_mapObject;
};