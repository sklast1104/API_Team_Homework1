#pragma once
#include "Obj.h"

class CBaseAirplane : public CObj
{
private :

	Vec2 startPoint;
	Vec2 endPoint;

	float speed;
	float time;

public :

	CBaseAirplane();
	virtual ~CBaseAirplane();

	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

};

