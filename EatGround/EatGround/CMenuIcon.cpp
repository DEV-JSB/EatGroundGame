#include "pch.h"
#include "CBitmap.h"
#include "CMenuIcon.h"



CMenuIcon::CMenuIcon(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
	:CObject(_x, _y, _z, _width, _height)
{
	CObject::InputBitmap(_name);

	// �⺻������ ��Ʈ���� �����Ҷ� �޴� �������� ���� ������� �������� �������� �Ѵ�.
	CObject::SetBitScale(_width, _height);
	CObject::SetBitPosition(_x,_y);
}

CMenuIcon::CMenuIcon()
{
}

CMenuIcon::~CMenuIcon()
{
}

void CMenuIcon::Render(const HDC _hdc)
{
	CObject::Render(_hdc);
}

CMenuIcon* CMenuIcon::Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
{
	return new CMenuIcon(_x, _y, _z, _width, _height, _name);
}
