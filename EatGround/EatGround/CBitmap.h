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
	
	// �������� ���� ����� ������
	Size m_stSize;


	// ��Ʈ���� �׸� ����
	HDC m_hDC;

	// ��Ʈ���� ����� ������ ������
	Vector2 m_vecPos;

	// ���Ϸ� �ҷ����� ��Ʈ��
	HBITMAP	m_hBit;

	// ��Ʈ���� ũ�� ����
	BITMAP	m_bitInfo;

};

