#pragma once
#include"CScene.h"
#include"CObserver.h"

class CScene_stage1 : public CScene
{
private:
	CScene_stage1();
	CScene_stage1(IMAGE _Type);
public:
	virtual ~CScene_stage1();
public:
	static CScene_stage1* Create(IMAGE _Type);

	virtual int Update()				override;
	virtual int Render(HDC _hdc)		override;
	virtual int Init()					override;
	virtual int Release()			override;

private:
	IMAGE m_eBitmapType;
};

