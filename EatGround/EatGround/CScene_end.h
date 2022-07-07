#pragma once
#include"CScene.h"
class CScene_end : public CScene
{
public:
	virtual void Update()	override;
	virtual void Render()	override;
	virtual void Init()		override;
};

