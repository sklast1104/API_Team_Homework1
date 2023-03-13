#pragma once
#include "Obj.h"
class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
	
public:
	void		Set_Bullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void		Key_Input(void);

private:
	list<CObj*>*		m_pBullet;

	DWORD lastUpdateTime;
	DWORD updateInterval;


};

