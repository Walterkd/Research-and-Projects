#pragma once

class CSIC
{
public:
    CSIC(void);
    ~CSIC(void);

protected:
    // 图像大小
    CSize   m_sizeImg;
    // 像素大小
    int     m_iPixel;

    // 数据空间
    unsigned char * m_cvRoom;
    // 数据长度
    __int64 m_iLength;

    // 压缩数据空间
    unsigned char * m_cvCRoom;
    // 压缩数据长度
    __int64 m_iCLength;

    // 容差
    __int32 m_iAllow;

    // 是否去噪
    bool    m_bChirp;


public:
    // 取得容差
    __int32 GetAllow()
    {
        return m_iAllow;
    }
    // 设置容差
    void SetAllow(__int32 allow)
    {
        m_iAllow = allow;
    }
    // 取得是否去噪
    bool IsChirp()
    {
        return m_bChirp;
    }
    // 是否去噪
    void Chirp(bool bChirp = true)
    {
        m_bChirp = bChirp;
    }
    // 清空
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
    // 设置图像
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
    // 取得图像
    bool GetImg(CBitmap & bmp)
    {
        if(m_cvRoom)
        {
            bmp.CreateBitmap(m_sizeImg.cx, m_sizeImg.cy, 1, m_iPixel * 8, m_cvRoom);
            return true;
        }
        return false;
    }
    // 设置压缩数据
    bool SetData(unsigned char * buffer, __int64 len);
    // 取得压缩数据
    char * GetData(__int64 & len);
    // 设置图像格式
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
    // 压缩
    bool Compress();
    // 解压
    bool Decompress();
    // 取得压缩率
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
    // 取得压缩描述
    CString Describe()
    {
        CString txt;
        txt.Format("压缩率 %.4lf%% (%lfK)", GetRate() * 100, m_iCLength / 1024.0);
        return txt;
    }
    // 取得图像大小
    inline CSize GetImgSize()
    {
        return m_sizeImg;
    }
};
