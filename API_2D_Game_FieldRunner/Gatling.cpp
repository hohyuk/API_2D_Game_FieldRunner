#include "framework.h"
#include "Gatling.h"

void Gatling::Ready()
{
	Tower::Set_Pivot(0.f, -10.f);
	Tower::Ready();
}

void Gatling::LateUpdate()
{
}

void Gatling::Release()
{
}

Gatling::Gatling()
{
}

Gatling::~Gatling()
{
}
