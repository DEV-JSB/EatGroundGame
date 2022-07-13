#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
	: CObject(_x, _y, _z, _width, _height)
{
	CObject::InputBitmap(_name);

	// �⺻������ ��Ʈ���� �����Ҷ� �޴� �������� ���� ������� �������� �������� �Ѵ�.
	CObject::SetBitScale(_width, _height);
	CObject::SetBitPosition(_x, _y);
}
CPlayer* CPlayer::Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
{
	return new CPlayer(_x, _y, _z, _width, _height, _name);
}

CPlayer::~CPlayer()
{
}

void CPlayer::Render(HDC _hdc)
{
	CObject::Render(_hdc);
}
