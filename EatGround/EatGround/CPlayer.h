#pragma once
#include"CObject.h"
class CPlayer : public CObject
{
private:
	CPlayer();
	CPlayer(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name);
public:
	static CPlayer* Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name);
	virtual ~CPlayer() override;
private:
};

