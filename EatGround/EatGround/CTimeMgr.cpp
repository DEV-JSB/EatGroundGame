#include "pch.h"
#include "CTimeMgr.h"

CTimeMgr::CTimeMgr()
{
}

CTimeMgr::~CTimeMgr()
{
}

void CTimeMgr::Init()
{
	 QueryPerformanceFrequency(&m_llFrequency);
	 QueryPerformanceCounter(&m_llCurCount);
}

void CTimeMgr::Update()
{
	QueryPerformanceCounter(&m_llPrevCount);

	m_dDt = (double)(m_llPrevCount.QuadPart - m_llCurCount.QuadPart) / (double)m_llFrequency.QuadPart;

	m_llCurCount = m_llPrevCount;
}
