#include "framework.h"
#include "Mortar.h"

void Mortar::Ready()
{
	Tower::Set_Pivot(18.f, 18.f);
	Tower::Ready();
	m_tInfo.iCX = m_tInfo.iCY = 160;
}

int Mortar::Update()
{
	return 0;
}

void Mortar::LateUpdate()
{
}

void Mortar::Release()
{
}

Mortar::Mortar()
{
}

Mortar::~Mortar()
{
}
