#pragma once
#include"CScene.h"
class CSceneMgr
{
	SINGLE(CSceneMgr);

public:
	void Init();
	void Render(HDC _hdc);
private:
	CScene* m_pCurrentScene;
	std::vector<CScene*>m_vecScene;
};

