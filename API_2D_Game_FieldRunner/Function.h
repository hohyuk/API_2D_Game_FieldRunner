#pragma once

static void MakeRect(RECT& rc, const INFO& info, int _reduction = 1)
{
	rc.left = LONG(info.fX - (info.iCX >> _reduction));
	rc.top = LONG(info.fY - (info.iCY >> _reduction));
	rc.right = LONG(info.fX + (info.iCX >> _reduction));
	rc.bottom = LONG(info.fY + (info.iCY >> _reduction));
}

static void MakeRect(RECT& rc, const INFO& info, int _iCX, int _iCY)
{
	rc.left = LONG(info.fX - _iCX);
	rc.top = LONG(info.fY - _iCY);
	rc.right = LONG(info.fX + _iCX);
	rc.bottom = LONG(info.fY + _iCY);
}

static void MakeRect(RECT& rc, const INFO& info, float _fCX, float _fCY)
{
	rc.left = LONG(info.fX - _fCX);
	rc.top = LONG(info.fY - _fCY);
	rc.right = LONG(info.fX + _fCX);
	rc.bottom = LONG(info.fY + _fCY);
}

static void MakeRect(RECT& rc, float _fX, float _fY, float _fCX, float _fCY)
{
	rc.left = LONG(_fX - _fCX);
	rc.top = LONG(_fY - _fCY);
	rc.right = LONG(_fX + _fCX);
	rc.bottom = LONG(_fY + _fCY);
}

inline bool Compare_Key(const TCHAR* _FramKey, const TCHAR* _CmpKey)
{
	if (!_tcscmp(_FramKey, _CmpKey))
		return true;
	return false;
}

inline bool IsPointInRect(const POINT& p, const RECT& rc)
{
	if (rc.left <= p.x && rc.right >= p.x && rc.top <= p.y && rc.bottom >= p.y)
		return true;
	return false;
}

inline float Distance(const float& _px, const float& _py, const float& _distx, const float& _disty)
{
	float w = _distx - _px;
	float h = _disty - _py;
	return sqrtf((w*w) + (h*h));
}

inline float Distance(const int& _px, const int& _py, const int& _distx, const int& _disty)
{
	float w = static_cast<float>(_distx - _px);
	float h = static_cast<float>(_disty - _py);
	return sqrtf((w*w) + (h*h));
}

inline bool IsPointInCircle(const POINT& p, const RECT& _rect)
{
	int centerX = (_rect.right - _rect.left) >> 1;
	int centerY = (_rect.bottom - _rect.top) >> 1;
	int posX = _rect.right - centerX;
	int posY = _rect.bottom - centerY;

	if (Distance(p.x, p.y, posX, posY) <= static_cast<float>(centerX))
		return true;
	return false;
}