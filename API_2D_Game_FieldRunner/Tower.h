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
	enum BULLET_ID { GOO_BULLET, FLAME1_BULLET, FLAME2_BULLET, MORTAR_BULLET, END_BULLET };
protected:
	virtual void UpgradeTower() = 0;
	virtual void Attack(float fDist) = 0;
	virtual void MakeBullet() = 0;
	void CreateBullet(BULLET_ID eID, float fX, float fY, float rad);
protected:
	void Set_Pivot(float x, float y) { m_tInfo.fX += x, m_tInfo.fY += y; }
	void Click_Tower(const POINT& pt);
	void UnClick_Tower(const POINT& pt);
	void Click_Upgrage(const POINT& pt);
	bool Click_Sell(const POINT& pt);

	void Attack_EnemyRanger();		// Enemy 공격 범위 찾기
	void TowerAnim();
	void Render_TowerUI(const HDC& hDC, const TCHAR * _pKey, int x, int y, int cx, int cy, int _state = 0);
	void Render_TowerUI(const HDC& hDC, const TCHAR * _pKey, int x, int y, int w, int h, int _wSrc, int _hSrc, int _state = 0);

public:
	explicit Tower();
	virtual ~Tower();

protected:
	enum PRICE { CURRENT, SELL, UPGRADE, END };
protected:
	static bool isTowerClick;			// 타워들중 하나만 판별하기위해 static사용
	int m_iIndex;						// 설치된 타워 인덱스 번호(위치)
	int m_UpgradePossibe;				// 업글
	int m_Level{};
	int m_LevelMotion{};				// 레벨에 맞는 이미지
	int m_iAttackRange;
	int m_iPriceArr[PRICE::END]{};
	RECT m_SellRect;
	RECT m_UpgradeRect;
	RECT m_ClickRangeRect;
	RECT m_AttackRangeRect;

	GameObject* m_pTarget{ nullptr };

	// 포신 위치 설청
	float m_fBarrelX{};
	float m_fBarrelY{};
	float m_fBarrelRad{};					// 반지름
};

