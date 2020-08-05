#include "framework.h"
#include "Gatling.h"

void Gatling::Ready()
{
	Tower::Set_Pivot(0.f, -10.f);
	Tower::Ready();
}

int Gatling::Update()
{
	return 0;
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
