#include "pch.h"
#include"CScene_stage1.h"
#include"CScene_start.h"
#include"CScene_end.h"
#include "CSceneMgr.h"


CSceneMgr::CSceneMgr()
{

}
CSceneMgr::~CSceneMgr()
{

}
void CSceneMgr::Update()
{
	switch (m_eScene)
	{
	case SCENE::SCENE_START:
		m_iImageSelect = m_pCurrentScene->Update();
		if (m_iImageSelect)
		{
			m_eScene = SCENE::SCENE_STAGE1;
			m_pCurrentScene->Release();
			m_pCurrentScene = CScene_stage1::Create((IMAGE)m_iImageSelect);
			m_pCurrentScene->Init();
		}
		break;
	case SCENE::SCENE_STAGE1:
		m_iImageSelect = m_pCurrentScene->Update();
		break;
	case SCENE::SCENE_ENDING:
		break;
	}
		
}
void CSceneMgr::Init()
{
	m_vecScene.push_back(CScene_start::Create());

	m_pCurrentScene = m_vecScene[(int)SCENE::SCENE_START];
	m_eScene = SCENE::SCENE_START;
	m_pCurrentScene->Init();

}

void CSceneMgr::Render(HDC _hdc)
{
	m_pCurrentScene->Render(_hdc);
}
