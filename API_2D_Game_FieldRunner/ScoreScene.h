#pragma once
#include "Scene.h"
class ScoreScene :
	public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual void Ready() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit ScoreScene();
	virtual~ScoreScene();

private:
	void Set_Color(int idx);
private:
	int index{};
	vector<int>* m_pScore;
	DWORD m_Color[3];
};

