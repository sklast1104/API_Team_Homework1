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
	void		Initialize(void);	// �����͸� �ʱ�ȭ�ϴ� �Լ�
	void		Update(void);		// �� �����Ӹ��� �����ϴ� �Լ�
	void		Late_Update(void);
	void		Render(void);		// �� �����Ӹ��� ����ϴ� �Լ�
	void		Release(void);		// ��ü �ı� �� �޸� ���� �Լ�

private:
	HDC				m_DC;	
	list<CObj*>		m_ObjList[OBJ_END];
	DWORD			m_dwTime;
	int				m_iFPS;
	TCHAR			m_szFPS[32];
	CTexture* _backBuffer;
};

// �߻� ���丮 ���� : ���� ������ �� ������ �ν��Ͻ��� ����� ������ �߻�ȭ�� ����
// �ݺ��� ���� : ���� ǥ�� ����� �������� �ʰ� �������� ���� ����� �����ϴ� ����

// �߻��� �̻��Ϸ� ���͸� �����϶�(�Ѿ˵� ����)

// 1. �浹 ó���Լ� IntersectRect(&��� �� ��Ʈ�� �ּ�1, &��Ʈ�� �ּ�2, &��Ʈ�� �ּ�3)
// 2. ��Ÿ����� ������ �����ϰ� �Ͷ�