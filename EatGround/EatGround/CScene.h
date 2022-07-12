#pragma once
#include"CBitmap.h"


class CScene abstract
{
protected:
	CScene();
	virtual ~CScene();
public:
	virtual int Update()			= 0;
	virtual int Render(HDC _hdc)	= 0;
	virtual int Init()				= 0;
	virtual int Release()			= 0;
};

