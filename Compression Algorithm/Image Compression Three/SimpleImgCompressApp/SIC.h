#pragma once

class CSIC
{
public:
    CSIC(void);
    ~CSIC(void);

protected:
    // ͼ���С
    CSize   m_sizeImg;
    // ���ش�С
    int     m_iPixel;

    // ���ݿռ�
    unsigned char * m_cvRoom;
    // ���ݳ���
    __int64 m_iLength;

    // ѹ�����ݿռ�
    unsigned char * m_cvCRoom;
    // ѹ�����ݳ���
    __int64 m_iCLength;

    // �ݲ�
    __int32 m_iAllow;

    // �Ƿ�ȥ��
    bool    m_bChirp;


public:
    // ȡ���ݲ�
    __int32 GetAllow()
    {
        return m_iAllow;
    }
    // �����ݲ�
    void SetAllow(__int32 allow)
    {
        m_iAllow = allow;
    }
    // ȡ���Ƿ�ȥ��
    bool IsChirp()
    {
        return m_bChirp;
    }
    // �Ƿ�ȥ��
    void Chirp(bool bChirp = true)
    {
        m_bChirp = bChirp;
    }
    // ���
    void Clear()
    {
        if(m_cvRoom)
        {
            delete [] m_cvRoom;
            m_cvRoom = NULL;
        }
        m_iLength = 0;
        if(m_cvCRoom)
        {
            delete [] m_cvCRoom;
            m_cvCRoom = NULL;
        }
        m_iCLength = 0;
        m_sizeImg.cx = 0;
        m_sizeImg.cy = 0;
        m_iPixel = 0;
    }
    // ����ͼ��
    bool SetImg(CBitmap & bmp)
    {
        BITMAP BMP;
        if(bmp.GetBitmap(&BMP) && SetFormat(BMP.bmWidth, BMP.bmHeight, BMP.bmBitsPixel / 8))
        {
            m_iLength = BMP.bmHeight * BMP.bmWidthBytes;
            m_cvRoom = new unsigned char [m_iLength];
            m_iLength = bmp.GetBitmapBits(m_iLength, m_cvRoom);
            return true;
        }
        return false;
    }
    // ȡ��ͼ��
    bool GetImg(CBitmap & bmp)
    {
        if(m_cvRoom)
        {
            bmp.CreateBitmap(m_sizeImg.cx, m_sizeImg.cy, 1, m_iPixel * 8, m_cvRoom);
            return true;
        }
        return false;
    }
    // ����ѹ������
    bool SetData(unsigned char * buffer, __int64 len);
    // ȡ��ѹ������
    char * GetData(__int64 & len);
    // ����ͼ���ʽ
    bool SetFormat(int w, int h, int iPixel)
    {
        if(iPixel != 4 || w <= 0 || h <= 0)
        {
            return false;
        }
        Clear();
        m_sizeImg.cx = w;
        m_sizeImg.cy = h;
        m_iPixel = iPixel;
    }
    // ѹ��
    bool Compress();
    // ��ѹ
    bool Decompress();
    // ȡ��ѹ����
    double GetRate()
    {
        if(m_iLength == 0)
        {
            return 1.0;
        }
        else
        {
            return m_iCLength / double(m_iLength);
        }
    }
    // ȡ��ѹ������
    CString Describe()
    {
        CString txt;
        txt.Format("ѹ���� %.4lf%% (%lfK)", GetRate() * 100, m_iCLength / 1024.0);
        return txt;
    }
    // ȡ��ͼ���С
    inline CSize GetImgSize()
    {
        return m_sizeImg;
    }
};
