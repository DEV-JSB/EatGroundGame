#pragma once
#include"CScene.h"

class CScene_stage2 : public CScene
{
private:
	CScene_stage2();
	virtual ~CScene_stage2();
public:
	virtual void Update()			override;
	virtual void Render(HDC _hdc)	override;
	virtual void Init()				override;
};

