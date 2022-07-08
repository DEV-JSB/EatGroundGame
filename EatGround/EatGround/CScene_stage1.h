#pragma once
#include"CScene.h"
#include"CObserver.h"

class CScene_stage1 : public CScene
{
public:
	virtual void Update()	override;
	virtual void Render(HDC _hdc)		override;
	virtual void Init()		override;

};

