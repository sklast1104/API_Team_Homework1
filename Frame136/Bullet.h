#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
private :

	// �����ϸ� �������ͷ� �Ұ�
	float m_directX;
	// �����ϸ� �������ͷ� �Ұ�
	float m_directY;

	void Shoot();


public:
	CBullet();
	virtual ~CBullet();

public:
	// CObj��(��) ���� ��ӵ�
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

 