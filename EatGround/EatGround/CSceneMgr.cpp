#include "pch.h"
#include"CScene_stage1.h"
#include"CScene_stage2.h"
#include"CScene_start.h"
#include"CScene_end.h"
#include "CSceneMgr.h"

void CSceneMgr::Init()
{
	m_vecScene.push_back(CScene_start::Create());


	m_pCurrentScene = m_vecScene[(int)SCENE::SCENE_START];
	m_pCurrentScene->Init();

}

void CSceneMgr::Render(HDC _hdc)
{
	m_pCurrentScene->Render(_hdc);
}
