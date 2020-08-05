#include "framework.h"
#include "Flame.h"

void Flame::Ready()
{
	Tower::Set_Pivot(0.f, -20.f);
	Tower::Ready();

}

void Flame::LateUpdate()
{
}

void Flame::Release()
{
}

Flame::Flame()
{
}

Flame::~Flame()
{
}
