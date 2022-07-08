#pragma once
#include"CBitmap.h"


class CScene abstract
{
protected:
	CScene();
	virtual ~CScene();
public:
	virtual void Update()			= 0;
	virtual void Render(HDC _hdc)	= 0;
	virtual void Init()				= 0;
};

