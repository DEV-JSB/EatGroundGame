#pragma once
#include"CComponent.h"
class CBitmap : public CComponent 
{
protected:
	CBitmap();
public:
	virtual ~CBitmap();
public:
	static CBitmap* Create();

	virtual int Update(const int _xChange, const int _yChange)	override;
	virtual void Render(HDC _hdc)								override;


	Vector2 GetPos() { return m_vecPos; }
	BITMAP GetInfo() { return m_bitInfo; }

	void RePositionBitmap(const int _x, const int _y);
	void ResizeBitmap(const int _width, const int _height);
	void BitmapSetting(const HBITMAP _hbit);
protected:
	
	// 중점으로 부터 출력할 사이즈
	Size m_stSize;


	// 비트맵을 그릴 도구
	HDC m_hDC;

	// 비트맵의 출력을 시작할 포지션
	Vector2 m_vecPos;

	// 파일로 불러들인 비트맵
	HBITMAP	m_hBit;

	// 비트맵의 크기 정보
	BITMAP	m_bitInfo;

};

