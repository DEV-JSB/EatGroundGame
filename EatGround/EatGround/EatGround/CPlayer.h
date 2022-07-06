#pragma once
#include"CObject.h"
#include"CSubject.h"
#include"CObserver.h"
class CPlayer : public CSubject
{
private:
	virtual void addObserver(CObserver* _observer)		 override;
	virtual void removeObserver(CObserver* _observer)	 override;
	virtual void notifyObserver()						 override;

private:
	CObserver* m_pObserver;
};

