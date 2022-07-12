#pragma once



enum class KEY
{
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN,
	KEY_SPACE,
	KEY_LAST
};

enum class KEYSTATE
{ 
	KEYSTATE_PRESSED, 
	KEYSTATE_NOTPTRESSED, 
	KEYSTATE_END 
};
struct stKeyInfo
{
	bool IsPress;
	KEYSTATE State;
	KEYSTATE PrevState;
};

class CKeyMgr
{	
private:
	SINGLE(CKeyMgr);
public:
	void Init();
	void Update();
	void SetFalse();
	stKeyInfo GetKeyState(KEY _eKey) { return m_vecstKey[(int)_eKey]; }
private:
	std::vector<stKeyInfo>m_vecstKey;

};

