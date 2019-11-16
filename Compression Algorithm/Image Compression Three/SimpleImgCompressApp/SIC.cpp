#include "StdAfx.h"
#include ".\sic.h"

CSIC::CSIC(void)
    : m_cvRoom(NULL)
    , m_cvCRoom(NULL)
    , m_iAllow(1000)
    , m_bChirp(false)
{
    Clear();
}

CSIC::~CSIC(void)
{
    Clear();
}

// 压缩
bool CSIC::Compress()
{
    if(m_cvRoom)
    {
        if(m_iPixel == 4)
        {
            if(m_cvCRoom)
            {
                delete [] m_cvCRoom;
            }
            m_iCLength = m_iLength * 3 / 4;
            m_cvCRoom = new unsigned char[m_iCLength];
            __int64 base = 0;
            __int64 len;
            __int64 tmp;
            __int64 index = 0;
            unsigned char r, g, b;
            double sr, sg, sb;
            unsigned char * pc;
            __int32 dr, dg, db;
            while(base < m_iLength)
            {
                r = m_cvRoom[base];
                g = m_cvRoom[base + 1];
                b = m_cvRoom[base + 2];
                sr = r;
                sg = g;
                sb = b;
                for(len = 4; len < m_iLength - base; len += 4)
                {
                    // 计算容差
                    pc = m_cvRoom + base + len;
                    dr = pc[0] - r;
                    dg = pc[1] - g;
                    db = pc[2] - b;
                    if(dr * dr + dg * dg + db * db > m_iAllow)
                    {
                        if(m_bChirp)
                        {
                            // 检查是不是噪点
                            if(len + 4 < m_iLength - base)
                            {
                                pc = m_cvRoom + base + len + 4;
                                dr = pc[0] - r;
                                dg = pc[1] - g;
                                db = pc[2] - b;
                                if(dr * dr + dg * dg + db * db > m_iAllow)
                                {
                                    break;
                                }
                            }
                            if(len + 4 * m_sizeImg.cx + 4 < m_iLength - base)
                            {
                                pc = m_cvRoom + base + len + 4 * m_sizeImg.cx;
                                dr = pc[0] - r;
                                dg = pc[1] - g;
                                db = pc[2] - b;
                                if(dr * dr + dg * dg + db * db > m_iAllow)
                                {
                                    break;
                                }
                                pc = m_cvRoom + base + len + 4 * m_sizeImg.cx + 4;
                                dr = pc[0] - r;
                                dg = pc[1] - g;
                                db = pc[2] - b;
                                if(dr * dr + dg * dg + db * db > m_iAllow)
                                {
                                    break;
                                }
                                pc = m_cvRoom + base + len + 4 * m_sizeImg.cx - 4;
                                dr = pc[0] - r;
                                dg = pc[1] - g;
                                db = pc[2] - b;
                                if(dr * dr + dg * dg + db * db > m_iAllow)
                                {
                                    break;
                                }
                            }
                            if(base + len - 4 * m_sizeImg.cx - 4 > 0)
                            {
                                pc = m_cvRoom + base + len - 4 * m_sizeImg.cx - 4;
                                dr = pc[0] - r;
                                dg = pc[1] - g;
                                db = pc[2] - b;
                                if(dr * dr + dg * dg + db * db > m_iAllow)
                                {
                                    break;
                                }
                                pc = m_cvRoom + base + len - 4 * m_sizeImg.cx;
                                dr = pc[0] - r;
                                dg = pc[1] - g;
                                db = pc[2] - b;
                                if(dr * dr + dg * dg + db * db > m_iAllow)
                                {
                                    break;
                                }
                                pc = m_cvRoom + base + len - 4 * m_sizeImg.cx + 4;
                                dr = pc[0] - r;
                                dg = pc[1] - g;
                                db = pc[2] - b;
                                if(dr * dr + dg * dg + db * db > m_iAllow)
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    sr += pc[0];
                    sg += pc[1];
                    sb += pc[2];
                }
                if(len > 8)
                {
                    tmp = len / 4;
                    r = sr / tmp;
                    g = sg / tmp;
                    b = sb / tmp;
                }
                if(r == 0)
                {
                    r = 1;
                }
                m_cvCRoom[index] = r;
                m_cvCRoom[index + 1] = g;
                m_cvCRoom[index + 2] = b;
                index += 3;
                if(len <= 8)
                {
                    len = 4;
                }
                else
                {
                    tmp = len / 4 - 1;
                    if(tmp > 0xFFFF)
                    {
                        tmp = 0xFFFF;
                        len = tmp * 4 + 4;
                    }
                    pc = (unsigned char *)&tmp;
                    m_cvCRoom[index] = 0;
                    m_cvCRoom[index + 1] = pc[0];
                    m_cvCRoom[index + 2] = pc[1];
                    index += 3;
                }
                base += len;
            }
            m_iCLength = index;
        }
        return true;
    }
    return false;
}

// 解压
bool CSIC::Decompress()
{
    if(m_cvCRoom)
    {
        if(m_iPixel == 4)
        {
            if(m_cvRoom)
            {
                delete [] m_cvRoom;
            }
            m_iLength = m_sizeImg.cx * m_sizeImg.cy * m_iPixel;
            m_cvRoom = new unsigned char[m_iLength];
            __int64 base = 0;
            __int32 len;
            __int32 i;
            __int64 index = 0;
            while(base < m_iLength)
            {
                m_cvRoom[base + 3] = 0;
                m_cvRoom[base] = m_cvCRoom[index];
                m_cvRoom[base + 1] = m_cvCRoom[index + 1];
                m_cvRoom[base + 2] = m_cvCRoom[index + 2];
                base += 4;
                if(base < m_iLength && m_cvCRoom[index + 3] == 0)
                {
                    len = *(unsigned __int16 *)(m_cvCRoom + index + 4);
                    for(i = 0; i < len; i++)
                    {
                        m_cvRoom[base + 3] = 0;
                        m_cvRoom[base] = m_cvCRoom[index];
                        m_cvRoom[base + 1] = m_cvCRoom[index + 1];
                        m_cvRoom[base + 2] = m_cvCRoom[index + 2];
                        base += 4;
                        if(base >= m_iLength)
                        {
                            break;
                        }
                    }
                    index += 3;
                    //base -= 4;
                }
                index += 3;
            }
        }
        return true;
    }
    return false;
}
