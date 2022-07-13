#include "pch.h"
#include "CKeyMgr.h"
#include "CPlayer.h"

bool CPlayer::IsCanMove(LINE _etype)
{
	for (std::list<Line>::iterator iter = m_lstLine.begin(); iter != m_lstLine.end(); ++iter)
	{
		switch (_etype)
		{
		case LINE::LINE_WIDTH:
			if ((*iter).type == LINE::LINE_WIDTH)
			{
				if ((*iter).start.y == m_pTransform->GetPosition_Y() &&
					(*iter).start.x <= m_pTransform->GetPosition_X() &&
					m_pTransform->GetPosition_X() <= (*iter).end.x)
					return true;
			}
			break;
		case LINE::LINE_HEIGHT:
			if ((*iter).type == LINE::LINE_HEIGHT)
			{
				if ((*iter).start.x == m_pTransform->GetPosition_X() &&
					(*iter).start.y <= m_pTransform->GetPosition_Y() &&
					m_pTransform->GetPosition_Y() <= (*iter).end.y)
					return true;
			}
			break;
		}
	}
	printf("움직일 수 없다\n");
	return false;
}

CPlayer::CPlayer(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
	: CObject(_x, _y, _z, _width, _height)
{
	CObject::InputBitmap(_name);

	// 기본적으로 비트맵을 생성할때 메뉴 아이콘의 기존 사이즈와 포지션을 따르도록 한다.
	CObject::SetBitScale(_width, _height);
	CObject::SetBitPosition(_x, _y);
}
CPlayer::~CPlayer()
{
}
CPlayer* CPlayer::Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
{
	return new CPlayer(_x, _y, _z, _width, _height, _name);
}





void CPlayer::Render(HDC _hdc)
{
	CObject::Render(_hdc);
}

int CPlayer::Update()
{
	if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_RIGHT).IsPress)
	{
		if (IsCanMove(LINE::LINE_WIDTH))
		{
			CObject::MoveTransAndBitPosition(1, 0);
		}
	}
	if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_LEFT).IsPress)
	{
		if (IsCanMove(LINE::LINE_WIDTH))
		{
			CObject::MoveTransAndBitPosition(-1, 0);
		}
	}
	if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_DOWN).IsPress)
	{
		if (IsCanMove(LINE::LINE_HEIGHT))
		{
			CObject::MoveTransAndBitPosition(0, 1);
		}
	}
	if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_UP).IsPress)
	{
		if (IsCanMove(LINE::LINE_HEIGHT))
		{
			CObject::MoveTransAndBitPosition(0, -1);
		}
	}
	if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_SPACE).IsPress)
	{
	}
	return 0;
}

int CPlayer::SettingMoveNavi(const int _left, const int _top, const int _right, const int _bottom)
{
	Line tmp;
	tmp.start = { _left , _top };
	tmp.end = { _right , _top };
	tmp.type = LINE::LINE_WIDTH;

	m_lstLine.push_back({ { _left , _top } , { _right , _top } , LINE::LINE_WIDTH });
	
	tmp.start = { _left , _bottom};
	tmp.end = { _right , _bottom };
	tmp.type = LINE::LINE_WIDTH;
	m_lstLine.push_back(tmp);

	tmp.start = { _left , _top };
	tmp.end = { _left , _bottom };
	tmp.type = LINE::LINE_HEIGHT;
	m_lstLine.push_back(tmp);

	tmp.start = { _right , _top };
	tmp.end = { _right , _bottom };
	tmp.type = LINE::LINE_HEIGHT;
	m_lstLine.push_back(tmp);

	return 0;
}
