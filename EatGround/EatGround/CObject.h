#pragma once
#include"CComponent.h"
#include"CTransform2D.h"

class CObject
{
protected:
	CObject();
	virtual ~CObject();

protected:
	void Setposition(const int _x, const int _y, const int _z);
	void InputBitmap(std::wstring _bmpname);
protected:
	std::map<COMPONENT, CComponent*> m_mapComponent;
	CTransform2D* m_pTransform;
};

