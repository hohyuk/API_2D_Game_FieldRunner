#pragma once
#include "ButtonUI.h"
class LogoUI :
	public ButtonUI
{
public:
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;

public:
	explicit LogoUI();
	virtual ~LogoUI();
};

