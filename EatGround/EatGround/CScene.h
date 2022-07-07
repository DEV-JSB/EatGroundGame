#pragma once
#include"CBitmap.h"


class CScene
{
public:
	void Update();
	void Render();
	void Enter();
private:
	std::vector<wchar_t*> m_vecFilename;
	std::vector<CBitmap*> m_vecBitmap;
};

