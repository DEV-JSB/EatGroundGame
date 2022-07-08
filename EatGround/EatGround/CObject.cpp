#include "pch.h"
#include "CBitmap.h"
#include "CObject.h"
#include "CBitmapMgr.h"


CObject::CObject(const Vector3 _pos, const Vector3 _rotation, const Vector2 _scale)
{
	CTransform2D* newTransform = new CTransform2D(_pos, _rotation, _scale);
	m_pTransform = newTransform;
	m_mapComponent.insert({ COMPONENT::COMPONENT_TRANSFORM2D,newTransform });
}

CObject::CObject()
{
}

CObject::~CObject()
{
}
CObject::CObject(const int _x, const int _y, const int _z, const int _width, const int _height)
{
	CTransform2D* newTransform = new CTransform2D((float)_x, (float)_y, (float)_z, 0.f, 0.f, 0.f, (float)_width, (float)_height);
	m_pTransform = newTransform;
	m_mapComponent.insert({ COMPONENT::COMPONENT_TRANSFORM2D,newTransform });
}



void CObject::SetBitPosition(const int _x, const int _y)
{
	CBitmap* bitComponent = dynamic_cast<CBitmap*>(m_mapComponent[COMPONENT::COMPONENT_BITMAP]);
	bitComponent->RePositionBitmap(_x,_y);
}

void CObject::SetBitScale(const int _width, const int _height)
{
	CBitmap* bitComponent = dynamic_cast<CBitmap*>(m_mapComponent[COMPONENT::COMPONENT_BITMAP]);
	bitComponent->ResizeBitmap(_width, _height);
}

void CObject::Setposition(const int _x, const int _y, const int _z)
{
	m_pTransform->SetPosition((float)_x, (float)_y, (float)_z);
}

void CObject::InputBitmap(std::wstring _bmpname)
{
	m_mapComponent.insert({ COMPONENT::COMPONENT_BITMAP,CBitmapMgr::GetInstance()->FindBit(_bmpname) });
}

void CObject::Render(HDC _hdc)
{
	for(int i = 0; i < (int)COMPONENT::COMPONENT_END; ++i)
		m_mapComponent[(COMPONENT)i]->Render(_hdc);
}
