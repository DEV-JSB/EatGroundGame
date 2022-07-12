#pragma once
#include"CScene.h"

class CScene_stage2 : public CScene
{
private:
	CScene_stage2();
	virtual ~CScene_stage2();
public:
	virtual int Update()			override;
	virtual int Render(HDC _hdc)	override;
	virtual int Init()				override;
};

