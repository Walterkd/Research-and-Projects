// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SimpleImgCompressApp.h"
#include "TestDlg.h"
#include ".\testdlg.h"


// CTestDlg 对话框

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)
CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
    , m_sDes("")
    , m_ptOffset(0, 0)
{
}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
    ON_COMMAND(ID_M_OPEN, OnMOpen)
    ON_COMMAND(ID_M_CUT, OnMCut)
    ON_COMMAND(ID_M_COMPRESS, OnMCompress)
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_COMMAND(ID_M_SETTING, OnMSetting)
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CTestDlg 消息处理程序

void CTestDlg::OnMOpen()
{
    // TODO: 在此添加命令处理程序代码
    CString strFilter;
    static int nFilterLoad;
    CSimpleArray<GUID> aguidFileTypes;

    HRESULT hResult = CImage::GetExporterFilterString(strFilter, aguidFileTypes, "所有支持的图像文件");
    if (FAILED(hResult))
    {
        CString fmt;
        fmt.Format("GetExporterFilter failed:\n%x", hResult);
        this->MessageBox(fmt, "错误", MB_ICONERROR);
    }
    else
    {
        CFileDialog dlg(TRUE, NULL, NULL, OFN_PATHMUSTEXIST, strFilter);
        dlg.m_pOFN->nFilterIndex = nFilterLoad;
        hResult = (int)dlg.DoModal();
        if(hResult == IDOK)
        {
            this->BeginWaitCursor();
            this->KillTimer(0);
            CClientDC dc(this);
            CDC tdc;
            tdc.CreateCompatibleDC(&dc);
            CImage image;
            if(SUCCEEDED(image.Load(dlg.GetPathName())))
            {
                tdc.SetStretchBltMode(HALFTONE);
                CBitmap bmp;
                bmp.CreateCompatibleBitmap(&dc, image.GetWidth(), image.GetHeight());
                tdc.SelectObject(&bmp);
                image.BitBlt(HDC(tdc), 0, 0);
                m_sic.SetImg(bmp);
                m_ptOffset.x = 0;
                m_ptOffset.y = 0;
            }
            nFilterLoad = dlg.m_pOFN->nFilterIndex;
            this->EndWaitCursor();
        }
    }
}

void CTestDlg::OnMCut()
{
    // TODO: 在此添加命令处理程序代码
    this->GetParent()->ShowWindow(SW_HIDE);
    this->ShowWindow(SW_HIDE);
    Sleep(100);
    CDC dcDesktop;
    dcDesktop.Attach(::GetDC(::GetDesktopWindow()));
    int w, h;
    w = ::GetSystemMetrics(SM_CXSCREEN);
    h = ::GetSystemMetrics(SM_CYSCREEN);
    CClientDC dc(this);
    CDC tdc;
    tdc.CreateCompatibleDC(&dc);
    CBitmap bmp;
    bmp.CreateCompatibleBitmap(&dc, w, h);
    tdc.SelectObject(&bmp);
    tdc.BitBlt(0, 0, w, h, &dcDesktop, 0, 0, SRCCOPY);
    m_sic.SetImg(bmp);
    this->ShowWindow(SW_SHOW);
    this->GetParent()->ShowWindow(SW_SHOW);
    m_sDes = "";
    m_ptOffset.x = 0;
    m_ptOffset.y = 0;
    Invalidate(false);
}

void CTestDlg::OnMCompress()
{
    // TODO: 在此添加命令处理程序代码
    m_sic.Compress();
    m_sDes = m_sic.Describe();
    m_sic.Decompress();
    MessageBox(m_sDes);
    Invalidate(false);
}

void CTestDlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO: 在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    CClientDC cdc(this);
    CBitmap bmp;
    CRect rect;
    GetClientRect(&rect);
    if(m_sic.GetImg(bmp))
    {
        CDC tdc;
        tdc.CreateCompatibleDC(&cdc);
        tdc.SelectObject(&bmp);
        cdc.FillSolidRect(&rect, RGB(255, 255, 255));
        cdc.BitBlt(m_ptOffset.x, m_ptOffset.y, m_sic.GetImgSize().cx, m_sic.GetImgSize().cy, &tdc, 0, 0, SRCCOPY);
    }
    //cdc.TextOut(0, 0, m_sDes);
}

void CTestDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    m_ptLast = point;

    CDialog::OnLButtonDown(nFlags, point);
}

void CTestDlg::OnMSetting()
{
    // TODO: 在此添加命令处理程序代码
    CSettingDlg dlg;
    dlg.m_iAllow = m_sic.GetAllow();
    dlg.m_bChirp = m_sic.IsChirp();
    if(dlg.DoModal() == IDOK)
    {
        m_sic.SetAllow(dlg.m_iAllow);
        m_sic.Chirp(dlg.m_bChirp);
    }
}

void CTestDlg::OnMouseMove(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    if(m_ptLast.x != -1)
    {
        m_ptOffset += point - m_ptLast;
        m_ptLast = point;
        Invalidate(false);
    }

    CDialog::OnMouseMove(nFlags, point);
}

void CTestDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    m_ptLast.x = -1;

    CDialog::OnLButtonUp(nFlags, point);
}
