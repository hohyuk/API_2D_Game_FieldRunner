#pragma once
#include "GameObject.h"
class Tile final :
	public GameObject
{
public:
	void IsNotTowerInstall() { isNotTowerInstall = !isNotTowerInstall; }
	void IsStartPoint() { isStartPoint = !isStartPoint; }
	void IsEndPoint() { isEndPoint = !isEndPoint; }

public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit Tile();
	virtual ~Tile();

private:
	void SelectColor();
private:
	bool isNotTowerInstall{ false };	//  true�� ���� Ÿ�� �˻� ������ �� ����
	bool isStartPoint{ false };
	bool isEndPoint{ false };
	DWORD m_dwColor;
};

