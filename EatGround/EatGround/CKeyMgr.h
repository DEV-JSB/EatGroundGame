#pragma once


enum class KEY
{
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_SPACE,



	KEY_LAST
};

class CKeyMgr
{	
	SINGLE(CKeyMgr);
	
public:
	void Init();
	void Update();
	bool GetKeyState(KEY _eKey) { return m_vecbKey[(int)_eKey]; }
private:
	std::vector<bool>m_vecbKey;

};

