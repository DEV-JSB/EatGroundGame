#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
	: CObject(_x, _y, _z, _width, _height)
{
	CObject::InputBitmap(_name);

	// 기본적으로 비트맵을 생성할때 메뉴 아이콘의 기존 사이즈와 포지션을 따르도록 한다.
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
