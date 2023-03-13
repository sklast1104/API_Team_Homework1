#pragma once
#include "Obj.h"
class CSquad : public CObj
{
private :

public :

	CSquad();
	virtual ~CSquad();

	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

};

