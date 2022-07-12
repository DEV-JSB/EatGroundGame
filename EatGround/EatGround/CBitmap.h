#pragma once
#include"CComponent.h"
class CBitmap : public CComponent 
{
private:
	CBitmap();
public:
	virtual ~CBitmap();
public:
	static CBitmap* Create();

	virtual void Update() override;
	virtual void Render(HDC _hdc) override;


	Vector2 GetPos() { return m_vecPos; }
	BITMAP GetInfo() { return m_bitInfo; }

	void RePositionBitmap(const int _x, const int _y);
	void ResizeBitmap(const int _width, const int _height);
	void BitmapSetting(const HBITMAP _hbit);
private:
	
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

