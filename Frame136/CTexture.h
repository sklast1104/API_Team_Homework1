#pragma once
class CTexture
{
private :

    HDC m_dc;
    HBITMAP m_hBit;
    BITMAP m_bitInfo;

    // ���Թ޾Ƽ� ��� (���Ѱ���! ������ å���� ����! ������ ������ ��)
    HDC m_mainDC;
public :

    CTexture(HDC _mainDC);
    virtual ~CTexture();

    void Create(UINT _iWidth, UINT _iHeight);

    UINT Width() { return m_bitInfo.bmWidth; }
    UINT Height() { return m_bitInfo.bmHeight; }
    HDC GetDC() { return m_dc; }

};

