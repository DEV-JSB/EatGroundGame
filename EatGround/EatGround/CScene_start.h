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

	void DrawRect(HDC _hdc, Vector2 _pos, BITMAP _info);
	void DrawSelectRectLine(HDC _hdc, int _Select);

	static CScene_start* Create();
	virtual int Update()			override;
	virtual int Render(HDC _hdc)	override;
	virtual int Init()				override;
	virtual int Release()			override;
private:
	RECT m_rcCursor[(int)PHOTO::PHOTO_END];
	int m_iSelectImage;
};

