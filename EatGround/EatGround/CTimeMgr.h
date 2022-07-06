#pragma once
class CTimeMgr
{
	SINGLE(CTimeMgr);
public:
	void Init();
	void Update();
	
	double GetDT() const { return m_dDt; }
private:
	// ���� �ð� ���� ���� �� �����ϱ� ���� ���Ͽ� ����ü
	LARGE_INTEGER			m_llCurCount;
	// ���� �ð� ���� �����ϱ� ���� ���Ͽ� ����ü
	LARGE_INTEGER			m_llPrevCount;
	// LARGE_INTER �� �ϴ� ������ �ð��� �̼��ϰ� ���� QueryPerformanceFrequency
	// �Լ��� LARGE_INTEGER �� �����ϱ� ����.
	
	// �ʴ� CPU �� ��ŭ �����ߴ����� �����ϴ� �����̴�.
	LARGE_INTEGER			m_llFrequency;

	// ��Ÿ Ÿ��
	double					m_dDt;


};

