#pragma once
#include "Actor.h"
class Tower :
	public Actor
{
public:
	void Set_Index(int index) { m_iIndex = index; }
public:
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;
protected:
	void Set_Pivot(float x, float y) { m_tInfo.fX += x, m_tInfo.fY += y; }
	void Click_Tower(const POINT& pt);
	void UnClick_Tower(const POINT& pt);
	void Click_Upgrage(const POINT& pt);
	bool Click_Sell(const POINT& pt);

	void Render_TowerUI(const HDC& hDC, const TCHAR * _pKey, int x, int y, int cx, int cy, int _state = 0);
	void Render_TowerUI(const HDC& hDC, const TCHAR * _pKey, int x, int y, int w, int h, int _wSrc, int _hSrc, int _state = 0);

public:
	explicit Tower();
	virtual ~Tower();

protected:
	static bool isTowerClick;			// Ÿ������ �ϳ��� �Ǻ��ϱ����� static���
	int m_iIndex;						// ��ġ�� Ÿ�� �ε��� ��ȣ(��ġ)
	RECT m_SellRect;
	RECT m_UpgradeRect;
	RECT m_ClickRangeRect;
};

