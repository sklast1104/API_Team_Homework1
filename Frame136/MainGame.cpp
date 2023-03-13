#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "AbstractFactory.h"
#include "Monster.h"
#include "Mouse.h"
#include "CollisionMgr.h"
#include "CTexture.h"

CMainGame::CMainGame()
	: m_dwTime(GetTickCount()), m_iFPS(0)
	, _backBuffer{nullptr}
{
	ZeroMemory(m_szFPS, sizeof(TCHAR) * 32);
}


CMainGame::~CMainGame()
{
	Safe_Delete<CTexture*>(_backBuffer);

	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);

	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front())->Set_Bullet(&m_ObjList[OBJ_BULLET]);

	m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create(200.f, 200.f));

	_backBuffer = new CTexture(m_DC);
	_backBuffer->Create(WINCX, WINCY);

	//m_ObjList[OBJ_MOUSE].push_back(CAbstractFactory<CMouse>::Create());
}

void CMainGame::Update(void)
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}

}

void CMainGame::Late_Update(void)
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}

	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_MOUSE], m_ObjList[OBJ_MONSTER]);
	CCollisionMgr::Collision_Sphere(m_ObjList[OBJ_BULLET], m_ObjList[OBJ_MONSTER]);
}

void CMainGame::Render(void)
{
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);

		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}


	// Clear
	Rectangle(_backBuffer->GetDC(), 0, 0, WINCX, WINCY);
	//Rectangle(m_DC, 100, 100, WINCX - 100 , WINCY - 100);

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); ++iter)
		{
			(*iter)->Render(_backBuffer->GetDC());
		}
	}

	// 문자열 출력 함수

	TCHAR		szBuff[32] = L"";

	swprintf_s(szBuff, L"Bullet : %f", 3.14f);
	
	 TextOut(_backBuffer->GetDC(), 50, 50, szBuff, lstrlen(szBuff));

	 BitBlt(m_DC, 0, 0, WINCX, WINCY,
		 _backBuffer->GetDC(), 0, 0, SRCCOPY);
}

void CMainGame::Release(void)
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
	
	ReleaseDC(g_hWnd, m_DC);
}
