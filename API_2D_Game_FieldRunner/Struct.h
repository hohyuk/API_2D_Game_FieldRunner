#pragma once

typedef struct tag_Info
{
	float fX, fY;				// 위치
	float fDirX, fDirY;			// 방향
	int iCX, iCY;				// 크기
	int iSrcX, iSrcY;			// 원본 크기
	tag_Info() :fX{ 0.f }, fY{ 0.f }, fDirX{ 0.f }, fDirY{ 0.f }, iCX{ 0 }, iCY{ 0 }, iSrcX{ 0 }, iSrcY{ 0 } {}
	tag_Info(float _fX, float _fY, int _iCX, int _iCY) :
		fX{ _fX }, fY{ _fY },
		fDirX{ 0.f }, fDirY{ 0.f },
		iCX{ _iCX }, iCY{ _iCY },
		iSrcX{ _iCX }, iSrcY{ _iCY } {}
	tag_Info(float _fX, float _fY, int _iCX, int _iCY, int _iSrcX, int _iSrcY) :
		fX{ _fX }, fY{ _fY },
		fDirX{ 0.f }, fDirY{ 0.f },
		iCX{ _iCX }, iCY{ _iCY },
		iSrcX{ _iSrcX }, iSrcY{ _iSrcY } {}
	tag_Info(float _fX, float _fY, float _fDirX, float _fDirY, int _iCX, int _iCY, int _iSrcX, int _iSrcY) :
		fX{ _fX }, fY{ _fY },
		fDirX{ _fDirX }, fDirY{ _fDirY },
		iCX{ _iCX }, iCY{ _iCY },
		iSrcX{ _iSrcX }, iSrcY{ _iSrcY } {}
}INFO;

typedef struct tag_Frame
{
	int iStart;				// 시작 프레임 
	int iEnd;				// 마지막 프레임 (X축 기준)
	int iSceneFrame;		// 현재 보여지는 프레임 (Y축 기준)
	float fFrameSpeed;		// 프레임 속도
	float fFixTime;			// 프레임 넘기는 속도
	tag_Frame() : iStart{ 0 }, iEnd{ 0 }, iSceneFrame{ 0 }, fFrameSpeed{ 0.f }, fFixTime{ 0.f }{}
}FRAME;