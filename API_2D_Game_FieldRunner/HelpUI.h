#pragma once
#include "ButtonUI.h"
class HelpUI :
	public ButtonUI
{
public:
	virtual void Ready() override;
	virtual void Render(const HDC & hDC) override;

public:
	explicit HelpUI();
	virtual ~HelpUI();
};

