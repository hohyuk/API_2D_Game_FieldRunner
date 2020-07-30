#pragma once

static void MakeRect(RECT& rc, const INFO& info, int _reduction = 1)
{
	rc.left = LONG(info.fX - (info.iCX >> _reduction));
	rc.top = LONG(info.fY - (info.iCY >> _reduction));
	rc.right = LONG(info.fX + (info.iCX >> _reduction));
	rc.bottom = LONG(info.fY + (info.iCY >> _reduction));
}

inline bool IsPointInRect(const POINT& p, const RECT& rc)
{
	if (rc.left <= p.x && rc.right >= p.x && rc.top <= p.y && rc.bottom >= p.y)
		return true;
	return false;
}