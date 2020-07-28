#pragma once

class Scene;
class MainGame final
{
public:
	void Ready();					// 초기화 함수
	void Update();					// 상태변화 함수
	void LateUpdate();				// 충돌 및 제거 함수
	void Render();					// 그리는 함수
	void Release();					// 제거 함수

public:
	explicit MainGame();
	~MainGame();

private:
	HDC m_hDC;		// 여기다 최종으로 그릴것.
};

