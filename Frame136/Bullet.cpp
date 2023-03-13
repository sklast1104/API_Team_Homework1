#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet() :
	m_directX{1.f}
	, m_directY{1.f}
{

}


CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fSpeed = 1.f;
}

void CBullet::Shoot()
{
	m_tInfo.fY -= m_fSpeed * m_directY;
	m_tInfo.fX += m_fSpeed * m_directX;
}

int CBullet::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	Shoot();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}
void CBullet::Late_Update(void)
{
	if (0 >= m_tRect.left || WINCX <= m_tRect.right ||
		0 >= m_tRect.top || WINCY <= m_tRect.bottom)
		m_bDead = true;
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release(void)
{
}



