#include "pch.h"
#include "CBitmapMgr.h"


CBitmapMgr::CBitmapMgr()
	:m_szContentPath{}
{}

CBitmapMgr::~CBitmapMgr()
{}

void CBitmapMgr::Init()
{
	GetCurrentDirectory(255, m_szContentPath);
}
