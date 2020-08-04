#pragma once
#include "ButtonUI.h"
class ExitUI :
	public ButtonUI
{
public:
	virtual void Ready() override;
	virtual void Render(const HDC & hDC) override;

public:
	explicit ExitUI();
	virtual ~ExitUI();
};

