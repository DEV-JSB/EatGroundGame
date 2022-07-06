#pragma once
#include"CObserver.h"
class CSubject
{
public:
	virtual void addObserver(CObserver* _observer) = 0;
	virtual void removeObserver(CObserver* _observer) = 0;
	virtual void notifyObserver() = 0;
private:

	CObserver* m_pObserver;

};

