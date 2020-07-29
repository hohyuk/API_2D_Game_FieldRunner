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
	int iStart;				// ���� ������ 
	int iEnd;				// ������ ������ (X�� ����)
	int iSceneFrame;		// ���� �������� ������ (Y�� ����)
	float fFrameSpeed;		// ������ �ӵ�
	float fFixTime;			// ������ �ѱ�� �ӵ�
}FRAME;