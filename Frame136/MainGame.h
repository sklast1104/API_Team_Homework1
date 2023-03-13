#pragma once

#include "Include.h"

class CTexture;

class CObj;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize(void);	// 데이터를 초기화하는 함수
	void		Update(void);		// 매 프레임마다 갱신하는 함수
	void		Late_Update(void);
	void		Render(void);		// 매 프레임마다 출력하는 함수
	void		Release(void);		// 객체 파괴 시 메모리 해제 함수

private:
	HDC				m_DC;	
	list<CObj*>		m_ObjList[OBJ_END];
	DWORD			m_dwTime;
	int				m_iFPS;
	TCHAR			m_szFPS[32];
	CTexture* _backBuffer;
};

// 추상 팩토리 패턴 : 생성 패턴의 한 종류로 인스턴스를 만드는 절차를 추상화한 패턴
// 반복자 패턴 : 내부 표현 방식은 공개하지 않고 순차적인 접근 방법을 제공하는 패턴

// 발사한 미사일로 몬스터를 삭제하라(총알도 삭제)

// 1. 충돌 처리함수 IntersectRect(&결과 값 렉트의 주소1, &렉트의 주소2, &렉트의 주소3)
// 2. 피타고라스의 정리를 공부하고 와라