#pragma once
#include "GameObject.h"
class ButtonUI :
	public GameObject
{
public:
	// dynamic_cast 필요
	void Set_ButtonType(UI_TYPE::BUTTON _type) { m_tBtn = _type; }
public:
	// GameObject을(를) 통해 상속됨
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit ButtonUI();
	virtual ~ButtonUI();

protected:
	UI_TYPE::BUTTON m_tBtn;					// 버튼 종류
};

