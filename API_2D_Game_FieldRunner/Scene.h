#pragma once

#include "ObjectManager.h"

class Scene abstract
{
public:
	virtual void Ready() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(const HDC& hDC) = 0;
	virtual void Release() = 0;

public:
	explicit Scene();
	virtual ~Scene();

protected:
	// Create
	virtual void Create_UI(const TCHAR* _key, INFO _info, UI_TYPE::ID eID, UI_TYPE::BUTTON eBtn);
	// Render
	virtual void Render_BackGround(const HDC& hDC, int x = 0, int y = 0, int cx = WINCX, int cy = WINCY);
protected:
	const TCHAR* m_szBGKey{nullptr};		// BackGround Key
};

