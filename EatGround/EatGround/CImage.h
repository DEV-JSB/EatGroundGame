#pragma once
#include"CObject.h"

class CImage : public CObject
{
public:
	virtual void Render(const HDC _hdc) override;
public:
	//Create :  x , y , z , width , height , filename
	static CImage* Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name);
private:
	CImage(const int _x, const int _y, const int _z,const int _width,const int _height, const std::wstring _name);
	CImage();
public:
	virtual ~CImage();
};

