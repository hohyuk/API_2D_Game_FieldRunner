#pragma once

class GameObject;

template <class T>
class AbstractFactory
{
public:
	static GameObject* Create()
	{
		GameObject* pObj = new T;
		pObj->Ready();
		return pObj;
	}

	static GameObject* Create(float fX, float fY)
	{
		GameObject* pObj = new T;
		pObj->Set_Pos(fX, fY);
		pObj->Ready();
		return pObj;
	}

	static GameObject* Create(const TCHAR* _pKey, float fX = 0, float fY = 0)
	{
		GameObject* pObj = new T;
		pObj->Set_FrameKey(_pKey);
		pObj->Set_Pos(fX, fY);
		pObj->Ready();
		return pObj;
	}
	static GameObject* Create(const TCHAR* _pKey, INFO& _info)
	{
		GameObject* pObj = new T;
		pObj->Set_FrameKey(_pKey);
		pObj->Set_Info(_info);
		pObj->Ready();
		return pObj;
	}
};