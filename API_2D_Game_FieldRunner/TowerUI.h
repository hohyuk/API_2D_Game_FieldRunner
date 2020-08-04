#pragma once
#include "ButtonUI.h"
class TowerUI :
	public ButtonUI
{
public:
	virtual void Ready() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;

public:
	explicit TowerUI();
	virtual ~TowerUI();
};

