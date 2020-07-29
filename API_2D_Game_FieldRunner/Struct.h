#pragma once

typedef struct tag_Info
{
	float fX;
	float fY;
	int iCX;
	int iCY;

	tag_Info() :fX{ 0.f }, fY{ 0.f }, iCX{ 0 }, iCY{ 0 }{}
	tag_Info(float _fX, float _fY, int _iCX, int _iCY) :fX{ _fX }, fY{ _fY }, iCX{ _iCX }, iCY{ _iCY }{}
}INFO;

typedef struct tag_Frame
{
	int iStart;				// 시작 프레임 
	int iEnd;				// 마지막 프레임 (X축 기준)
	int iSceneFrame;		// 현재 보여지는 프레임 (Y축 기준)
	float fFrameSpeed;		// 프레임 속도
	float fFixTime;			// 프레임 넘기는 속도
}FRAME;