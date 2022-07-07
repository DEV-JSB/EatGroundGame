#pragma once
#include"CObject.h"


class CMenuIcon : public CObject
{
private:
	CMenuIcon();
	virtual ~CMenuIcon();
public:
	static CMenuIcon* Create();
};

