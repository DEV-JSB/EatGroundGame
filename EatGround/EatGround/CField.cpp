#include "pch.h"

#include "CField.h"

CField::CField()
{
}

CField::CField(const int _left, const int _up, const int _right, const int _down)
{
	m_lstPoint.push_back(POINT{ _left  ,   _up });
	m_lstPoint.push_back(POINT{ _right ,   _up });
	m_lstPoint.push_back(POINT{ _right , _down });
	m_lstPoint.push_back(POINT{ _left  , _down });
}


CField* CField::Create(const int _left, const int _up, const int _right, const int _down)
{
	return nullptr;
}

CField::~CField()
{
}

void CField::Render(const HDC _hdc)
{
	//Polygon(_hdc,&m_lstPoint,)
}

int CField::Update()
{
	return 0;
}
