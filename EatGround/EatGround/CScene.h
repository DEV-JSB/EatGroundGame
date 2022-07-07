#pragma once
#include"CBitmap.h"


class CScene
{
public:
	virtual void Update();
	virtual void Render();
	virtual void Init();
protected:
	std::vector<std::wstring> m_vecFilename;
};

