#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr);
public:
	void Init();
	void Update();
	
	double GetDT() const { return m_dDt; }
private:
	// 현재 시간 값을 갱신 후 저장하기 위한 유니온 구조체
	LARGE_INTEGER			m_llCurCount;
	// 이전 시간 값을 저장하기 위한 유니온 구조체
	LARGE_INTEGER			m_llPrevCount;
	// LARGE_INTER 로 하는 이유는 시간을 미세하게 새는 QueryPerformanceFrequency
	// 함수가 LARGE_INTEGER 에 저장하기 때문.
	
	// 초당 CPU 가 얼만큼 진동했는지를 저장하는 변수이다.
	LARGE_INTEGER			m_llFrequency;

	// 델타 타임
	double					m_dDt;


};

