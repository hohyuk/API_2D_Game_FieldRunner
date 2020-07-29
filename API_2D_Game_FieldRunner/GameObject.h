#pragma once
class GameObject abstract
{

public:
	void Set_FrameKey(const TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }
	void Set_Pos(float fX, float fY) { m_tInfo.fX = fX, m_tInfo.fY = fY; }
	void Set_Info(INFO& _info) { m_tInfo = _info; }
public:
	virtual void Ready() = 0;
	virtual int	 Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(const HDC& hDC) = 0;
	virtual void Release() = 0;

public:
	explicit GameObject();
	virtual ~GameObject();

protected:
	const TCHAR* m_pFrameKey{ nullptr };

	INFO m_tInfo;
	FRAME m_tFrame;
	RECT m_tRect;
};

