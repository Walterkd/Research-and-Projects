// SimpleImgCompressAppDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SimpleImgCompressApp.h"
#include "SimpleImgCompressAppDlg.h"
#include ".\simpleimgcompressappdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CSimpleImgCompressAppDlg 对话框



CSimpleImgCompressAppDlg::CSimpleImgCompressAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimpleImgCompressAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleImgCompressAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSimpleImgCompressAppDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_WM_TIMER()
    ON_WM_ERASEBKGND()
    ON_BN_CLICKED(IDC_BT_TEST, OnBnClickedBtTest)
END_MESSAGE_MAP()


// CSimpleImgCompressAppDlg 消息处理程序

BOOL CSimpleImgCompressAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    SetTimer(0, 66, 0);
	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CSimpleImgCompressAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSimpleImgCompressAppDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
    //CRect rect, wrect;
    //GetClientRect(&rect);
    //GetWindowRect(&wrect);
    //CDC dcDesktop;
    //dcDesktop.Attach(::GetDC(::GetDesktopWindow()));

    //int w, h;
    //w = rect.Width();
    //h = rect.Height();
    //CClientDC dc(this);
    //CDC tdc;
    //tdc.CreateCompatibleDC(&dc);
    //CBitmap bmp;
    //{
    //    int n = 32;
    //    char * buffer = new char[w * h * n / 8];
    //    memset(buffer, 0, w * h * n / 8);
    //    BOOL b = bmp.CreateBitmap(rect.Width(), rect.Height(), 1, n, buffer);
    //    delete [] buffer;
    //    buffer = NULL;
    //}
    //CBitmap * pbmp = tdc.SelectObject(&bmp);
    //tdc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcDesktop, wrect.left - rect.Width(), wrect.top, SRCCOPY);
    ////tdc.SelectObject(pbmp);
    //CSIC sic;
    //sic.SetImg(bmp);
    //sic.Compress();
    //CString txt;
    //txt.Format("%lf", sic.GetRate());
    //sic.Decompress();
    //CBitmap tbmp;
    //sic.GetImg(tbmp);
    //CDC ttdc;
    //ttdc.CreateCompatibleDC(&dc);
    //ttdc.SelectObject(&tbmp);
    //dc.BitBlt(0, 0, rect.Width(), rect.Height(), &ttdc, 0, 0, SRCCOPY);
    //dc.TextOut(0, 0, txt);
    /*CImage img;
    img.Attach(HBITMAP(bmp));
    HRESULT h1 = img.Save("c:\\test.jpg");
    if(FAILED(h1))
    {
        int i = 0;
    }*/
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CSimpleImgCompressAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSimpleImgCompressAppDlg::OnTimer(UINT nIDEvent)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    //Invalidate(false);
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
    m_sic.Compress();
    //CString txt;
    //txt.Format("全屏图像压缩率 %.4lf%%", sic.GetRate() * 100);
    SetDlgItemText(IDC_STATIC_MSG, m_sic.Describe());
    //Sleep(100);

    CDialog::OnTimer(nIDEvent);
}

BOOL CSimpleImgCompressAppDlg::OnEraseBkgnd(CDC* pDC)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值

    return CDialog::OnEraseBkgnd(pDC);
}

void CSimpleImgCompressAppDlg::OnBnClickedBtTest()
{
    // TODO: 在此添加控件通知处理程序代码
    KillTimer(0);
    CTestDlg dlg;
    dlg.m_sic.Chirp(m_sic.IsChirp());
    dlg.m_sic.SetAllow(m_sic.GetAllow());
    dlg.DoModal();
    m_sic.Chirp(dlg.m_sic.IsChirp());
    m_sic.SetAllow(dlg.m_sic.GetAllow());
    SetTimer(0, 66, 0);
}
