#pragma once
#include"CScene.h"
class CSceneMgr
{
	SINGLE(CSceneMgr);

public:
	void Update();
	void Init();
	void Render(HDC _hdc);
private:
	int m_iImageSelect;
	SCENE m_eScene;
	CScene* m_pCurrentScene;
	std::vector<CScene*>m_vecScene;
};

