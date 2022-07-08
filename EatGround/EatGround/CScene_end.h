#pragma once
#include"CScene.h"
class CScene_end : public CScene
{
private:
	CScene_end();
	virtual ~CScene_end();
public:
	virtual void Update()				override;
	virtual void Render(HDC _hdc)		override;
	virtual void Init()					override;
};

