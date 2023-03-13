#pragma once

#include "Include.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

	INFO		Get_Info(void) { return m_tInfo; }
	RECT		Get_Rect(void)	{ return m_tRect; }
	void		Set_Dead()		{ m_bDead = true; }

public:
	virtual void		Initialize(void)PURE;
	virtual int			Update(void)PURE;
	virtual void		Late_Update(void)PURE;
	virtual void		Render(HDC hDC)PURE;
	virtual void		Release(void)PURE;

public:
	void			Update_Rect(void);

protected:
	INFO			m_tInfo;
	RECT			m_tRect;	

	float			m_fSpeed;
	bool			m_bDead;
};

