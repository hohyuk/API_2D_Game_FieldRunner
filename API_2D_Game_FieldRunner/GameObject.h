#pragma once
class GameObject abstract
{

public:
	void Set_FrameKey(const TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }
	void Set_Pos(float fX, float fY) { m_tInfo.fX = fX, m_tInfo.fY = fY; }
	void Set_Info(INFO& _info) { m_tInfo = _info; }
	void Set_ColliderRect(const RECT& rc) { m_tColliderRC = rc; }
	RECT Get_Rect()const { return m_tRect; }
	RECT Get_ColliderRect()const { return m_tColliderRC; }

	float Get_PosX()const { return m_tInfo.fX; }
	float Get_PosY()const { return m_tInfo.fY; }

	OBJECT::RENDER Get_RenderID()const { return m_eRenderID; }

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
	void Render_Debug(const HDC & hDC, const RECT & rc, BOOL(__stdcall *_ShapeFun)(HDC hDC, int left, int top, int right, int bottom) = Rectangle, DWORD _color = RGB(255, 255, 255));
	void Render_Alpha(const HDC & hDC, const RECT & rc, int _size, DWORD _color, BOOL(__stdcall * _ShapeFun)(HDC hDC, int left, int top, int right, int bottom) = Rectangle);
protected:
	const TCHAR* m_pFrameKey{ nullptr };
	bool isClick{ false };
	INFO m_tInfo;
	FRAME m_tFrame;
	RECT m_tRect;
	RECT m_tColliderRC;

	OBJECT::RENDER m_eRenderID;
};

