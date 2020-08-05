#include "framework.h"
#include "Goo.h"

void Goo::Ready()
{
	Tower::Set_Pivot(0.f, -10.f);
	Tower::Ready();

}

int Goo::Update()
{
	return 0;
}

void Goo::LateUpdate()
{
}

void Goo::Release()
{
}

Goo::Goo()
{
}

Goo::~Goo()
{
}
