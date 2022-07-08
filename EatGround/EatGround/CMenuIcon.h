#pragma once
#include"CObject.h"

class CMenuIcon : public CObject
{
public:
	virtual void Render(const HDC _hdc) override;
public:
	static CMenuIcon* Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name);
private:
	CMenuIcon(const int _x, const int _y, const int _z,const int _width,const int _height, const std::wstring _name);
	CMenuIcon();
	virtual ~CMenuIcon();
};

