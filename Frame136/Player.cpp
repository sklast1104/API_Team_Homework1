#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"
#include "AbstractFactory.h"

CPlayer::CPlayer()
	: m_pBullet(nullptr)
	, lastUpdateTime{0}
	, updateInterval{200}
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.fX = 400.f;		// 중점 X
	m_tInfo.fY = 300.f;		// 중점 Y

	m_tInfo.fCX = 100.f;	// 플레이어 가로 사이즈
	m_tInfo.fCY = 100.f;	// 플레이어 세로 사이즈

	m_fSpeed = 10.f;
}

int CPlayer::Update(void)
{
	Key_Input();



	// 위쪽에서 중점 또는 사이즈의 변화를 끝낸 다음에 Update_Rect함수를 호출
	__super::Update_Rect();

	return OBJ_NOEVENT;
}
void CPlayer::Late_Update(void)
{
}


void CPlayer::Render(HDC hDC)
{
	// 뱅기

	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);

	LineTo(hDC, m_tInfo.fX - 20, m_tInfo.fY + 20);

	LineTo(hDC, m_tInfo.fX - 20, m_tInfo.fY + 10);

	LineTo(hDC, m_tInfo.fX , m_tInfo.fY - 10);

	LineTo(hDC, m_tInfo.fX, m_tInfo.fY - 50);

	LineTo(hDC, m_tInfo.fX + 5, m_tInfo.fY - 60);

	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY - 50);

	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY - 10);

	LineTo(hDC, m_tInfo.fX + 30, m_tInfo.fY + 10);

	LineTo(hDC, m_tInfo.fX + 30, m_tInfo.fY + 20);

	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY);

	LineTo(hDC, m_tInfo.fX , m_tInfo.fY);

	//
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_LEFT))
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState(VK_RIGHT))
		m_tInfo.fX += m_fSpeed;

	if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;
	
	if (GetAsyncKeyState(VK_SPACE))
	{
		DWORD currentTime = GetTickCount();
		DWORD elapsedTime = currentTime - lastUpdateTime;

		if (elapsedTime >= updateInterval) {
			CObj* bullet = new CBullet;
			bullet->Initialize();
			bullet->Set_Pos(m_tInfo.fX + 5, m_tInfo.fY - 70);
			((CBullet*)bullet)->SetDir(0.f, 1.f);
			m_pBullet->push_back(bullet);

			CObj* bullet2 = new CBullet;
			bullet2->Initialize();
			bullet2->Set_Pos(m_tInfo.fX + 5, m_tInfo.fY - 70);
			((CBullet*)bullet2)->SetDir(1.f, 1.f);
			m_pBullet->push_back(bullet2);

			CObj* bullet3 = new CBullet;
			bullet3->Initialize();
			bullet3->Set_Pos(m_tInfo.fX + 5, m_tInfo.fY - 70);
			((CBullet*)bullet3)->SetDir(-1.f, 1.f);
			m_pBullet->push_back(bullet3);

			lastUpdateTime = currentTime;
		}

		
	}
}

