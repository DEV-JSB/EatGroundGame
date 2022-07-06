#pragma once
#include"CScene.h"
#include"CObserver.h"

class CScene_stage1 : public CScene , public CObserver
{
public:
	virtual void OnNotify(const int Area, EVENT _eventype) override;

};

