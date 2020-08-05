#pragma once
#include "ButtonUI.h"
class TowerUI :
	public ButtonUI
{
public:
	void Set_TowerKey(UI_TYPE::BUTTON _type);
public:
	virtual void Ready() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;

public:
	explicit TowerUI();
	virtual ~TowerUI();
private:
	const TCHAR* m_pTowerKey;
	INFO m_tTowerInfo;
	RECT m_tTowerRect;
	DWORD m_Color{ RGB(255,0,0) };
};

