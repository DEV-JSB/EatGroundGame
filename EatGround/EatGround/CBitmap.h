#pragma once
#include"CComponent.h"
class CBitmap : public CComponent 
{

public:
	void SetBitmap(HBITMAP _bitmap);
	void SetBitInfo(BITMAP _bitinfo);
private:
	
	// �������� ���� ����� ������
	Size m_stSize;

	// ��Ʈ���� ����� ������ ������
	Vector2 m_vecPos;

	// ��Ʈ���� �׸� ȭ��
	HDC		m_hdc;

	// ���Ϸ� �ҷ����� ��Ʈ��
	HBITMAP	m_hBit;

	// ��Ʈ���� ũ�� ����
	BITMAP	m_bitInfo;

};

