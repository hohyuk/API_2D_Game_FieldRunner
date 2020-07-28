#pragma once

class Scene;
class MainGame final
{
public:
	void Ready();					// �ʱ�ȭ �Լ�
	void Update();					// ���º�ȭ �Լ�
	void LateUpdate();				// �浹 �� ���� �Լ�
	void Render();					// �׸��� �Լ�
	void Release();					// ���� �Լ�

public:
	explicit MainGame();
	~MainGame();

private:
	HDC m_hDC;		// ����� �������� �׸���.
};

