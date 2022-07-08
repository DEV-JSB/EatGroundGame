#pragma once
#include"CObject.h"


class CMenuIcon : public CObject
{
private:
	CMenuIcon(int _x, int _y, int _z);
	CMenuIcon();
	virtual ~CMenuIcon();
public:
	static CMenuIcon* Create(const int _x,const int _y,const int _z);
};

