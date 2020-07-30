#pragma once
#include "ButtonUI.h"
class LogoUI :
	public ButtonUI
{
public:
	virtual void Ready() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;

public:
	explicit LogoUI();
	virtual ~LogoUI();

private:
	bool isShowUI;
};

