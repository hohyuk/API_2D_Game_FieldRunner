#pragma once

static void MakeRect(RECT& rc, const INFO& info)
{
	rc.left = LONG(info.fX - (info.iCX >> 1));
	rc.top = LONG(info.fY - (info.iCY >> 1));
	rc.right = LONG(info.fX + (info.iCX >> 1));
	rc.bottom = LONG(info.fY + (info.iCY >> 1));
}