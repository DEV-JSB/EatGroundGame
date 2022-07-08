#include "pch.h"
#include "CMenuIcon.h"


CMenuIcon::CMenuIcon(int _x, int _y, int _z)
	:CObject(_x,_y,_z)
{
}

CMenuIcon::CMenuIcon()
{
}

CMenuIcon::~CMenuIcon()
{
}


CMenuIcon* CMenuIcon::Create(const int _x,const int _y,const int _z)
{
	return new CMenuIcon(_x, _y, _z);
}
