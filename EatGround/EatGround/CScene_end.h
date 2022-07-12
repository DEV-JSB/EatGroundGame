#pragma once
#include"CScene.h"
class CScene_end : public CScene
{
private:
	CScene_end();
	virtual ~CScene_end();
public:
	virtual int Update()				override;
	virtual int Render(HDC _hdc)		override;
	virtual int Init()					override;
};

