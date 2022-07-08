#pragma once
#include"CScene.h"

class CScene_start : public CScene
{
private:
	CScene_start();
	virtual ~CScene_start();
public:
	static CScene_start* Create();
	virtual void Update()			override;
	virtual void Render(HDC _hdc)	override;
	virtual void Init()				override;

	
};

