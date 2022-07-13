#include "pch.h"
#include "CBitmap.h"
#include "CImage.h"



CImage::CImage(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
	:CObject(_x, _y, _z, _width, _height)
{
	CObject::InputBitmap(_name);

	// �⺻������ ��Ʈ���� �����Ҷ� �޴� �������� ���� ������� �������� �������� �Ѵ�.
	CObject::SetBitScale(_width, _height);
	CObject::SetBitPosition(_x,_y);
}

CImage::CImage(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name, const float _r, const float _g, const float _b)
	:CObject(_x, _y, _z, _width, _height)
{
	CObject::InputBitmap(_name);
	CObject::SetBitScale(_width, _height);
	CObject::SetBitPosition(_x, _y);
}

CImage::CImage()
{
}

CImage::~CImage()
{
}

void CImage::Render(const HDC _hdc)
{
	CObject::Render(_hdc);
}

CImage* CImage::Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
{
	return new CImage(_x, _y, _z, _width, _height, _name);
}

CImage* CImage::Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name, const float _r, const float _g, const float _b)
{
	return new CImage(_x, _y, _z, _width, _height, _name, _r, _g, _b);
}
