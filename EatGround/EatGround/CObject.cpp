#include "pch.h"
#include "CObject.h"
#include "CBitmapMgr.h"


CObject::CObject(const int _x, const int _y, const int _z)
{
	m_pTransform->SetPosition(_x,_y,_z);
}

CObject::CObject()
{
	// 기본 트랜스폼 생성 , 0,0,0
	CTransform2D* newTransform = new CTransform2D(0.f,0.f,0.f,0.f,0.f,0.f);
	m_pTransform = newTransform;
	m_mapComponent.insert({ COMPONENT::COMPONENT_TRANSFORM2D,newTransform });
}

CObject::~CObject()
{
}

void CObject::Setposition(const int _x, const int _y, const int _z)
{
	m_pTransform->SetPosition((float)_x, (float)_y, (float)_z);
}

void CObject::InputBitmap(std::wstring _bmpname)
{
	m_mapComponent.insert({ COMPONENT::COMPONENT_BITMAP,CBitmapMgr::GetInstance()->FindBit(_bmpname) });
}