#pragma once
class GameObject abstract
{
public:
	virtual void Ready() = 0;
	virtual int	 Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(const HDC& hDC) = 0;
	virtual void Release() = 0;

public:
	explicit GameObject();
	virtual ~GameObject();
};

