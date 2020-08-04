#pragma once
#include "GameObject.h"
class ButtonUI :
	public GameObject
{
public:
	// dynamic_cast �ʿ�
	void Set_ButtonType(UI_TYPE::BUTTON _type) { m_tBtn = _type; }
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit ButtonUI();
	virtual ~ButtonUI();

protected:
	void Click_Button();
protected:
	bool isShowUI{ false };
	bool isButtonSound{ false };
	UI_TYPE::BUTTON m_tBtn;					// ��ư ����
};

