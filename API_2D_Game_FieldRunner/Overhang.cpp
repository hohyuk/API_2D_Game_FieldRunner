#include "framework.h"
#include "Overhang.h"

void Overhang::Ready()
{
	m_eRenderID = OBJECT::OVERHANG_RENDER;
	if (Compare_Key(m_pFrameKey, TEXT("Gate")))
	{
		m_tInfo.iCX = 92;
		m_tInfo.iCY = 98;
	}
}

int Overhang::Update()
{
	return 0;
}

void Overhang::LateUpdate()
{
}

void Overhang::Render(const HDC & hDC)
{
	HDC hMemDC = BMP_MGR->Find_Image(m_pFrameKey);
	GdiTransparentBlt(hDC, static_cast<int>(m_tInfo.fX), static_cast<int>(m_tInfo.fY),
		m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0,
		m_tInfo.iCX, m_tInfo.iCY, RGB(255, 0, 255));
}

void Overhang::Release()
{
}

Overhang::Overhang()
{
}

Overhang::~Overhang()
{
}
