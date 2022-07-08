#pragma once
#include"CScene.h"

class CScene_start : public CScene
{
private:
	enum class PHOTO{ PHOTO_IRONMAN , PHOTO_SPIDERMAN, PHOTO_WARMACHINE , PHOTO_DOCTORSTRANGE , PHOTO_END};
private:
	CScene_start();
	virtual ~CScene_start();
public:
	static CScene_start* Create();
	virtual void Update()			override;
	virtual void Render(HDC _hdc)	override;
	virtual void Init()				override;
private:
	RECT m_rcCursor[(int)PHOTO::PHOTO_END];
};

