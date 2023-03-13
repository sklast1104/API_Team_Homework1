#pragma once
class CTexture
{
private :

    HDC m_dc;
    HBITMAP m_hBit;
    BITMAP m_bitInfo;

    // 주입받아서 사용 (약한관계! 해제의 책임이 없음! 오로지 관찰만 함)
    HDC m_mainDC;
public :

    CTexture(HDC _mainDC);
    virtual ~CTexture();

    void Create(UINT _iWidth, UINT _iHeight);

    UINT Width() { return m_bitInfo.bmWidth; }
    UINT Height() { return m_bitInfo.bmHeight; }
    HDC GetDC() { return m_dc; }

};

