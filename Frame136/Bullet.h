#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
private :

	// 웬만하면 단위벡터로 할것
	float m_directX;
	// 웬만하면 단위벡터로 할것
	float m_directY;

	void Shoot();


public:
	CBullet();
	virtual ~CBullet();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	void SetDir(float _directX, float _directY) {
		m_directX = _directX;
		m_directY = _directY;
	}

	
	
};

 