#pragma once
class CObserver
{

public:
	virtual ~CObserver();
	virtual void OnNotify(const int Area, EVENT _eventype) = 0;
};

