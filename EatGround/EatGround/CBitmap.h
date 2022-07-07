#pragma once
#include"CComponent.h"
class CBitmap : public CComponent 
{

public:
	void SetBitmap(HBITMAP _bitmap);
	void SetBitInfo(BITMAP _bitinfo);
private:
	
	// 중점으로 부터 출력할 사이즈
	Size m_stSize;

	// 비트맵의 출력을 시작할 포지션
	Vector2 m_vecPos;

	// 비트맵이 그릴 화면
	HDC		m_hdc;

	// 파일로 불러들인 비트맵
	HBITMAP	m_hBit;

	// 비트맵의 크기 정보
	BITMAP	m_bitInfo;

};

