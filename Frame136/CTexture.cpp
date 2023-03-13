#include "stdafx.h"
#include "CTexture.h"

CTexture::CTexture(HDC _mainDC)
	: m_hBit(0)
	, m_dc(0)
	, m_bitInfo{}
	, m_mainDC{_mainDC}
{
	
}

CTexture::~CTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void CTexture::Create(UINT _iWidth, UINT _iHeight)
{
	m_hBit = CreateCompatibleBitmap(m_mainDC, _iWidth, _iHeight);
	m_dc = CreateCompatibleDC(m_mainDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_dc, m_hBit);
	DeleteObject(hOldBit);
}
