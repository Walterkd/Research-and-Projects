// SimpleImgCompressAppDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SimpleImgCompressApp.h"
#include "SimpleImgCompressAppDlg.h"
#include ".\simpleimgcompressappdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CSimpleImgCompressAppDlg �Ի���



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


// CSimpleImgCompressAppDlg ��Ϣ�������

BOOL CSimpleImgCompressAppDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��\������...\���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    SetTimer(0, 66, 0);
	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSimpleImgCompressAppDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR CSimpleImgCompressAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSimpleImgCompressAppDlg::OnTimer(UINT nIDEvent)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
    //txt.Format("ȫ��ͼ��ѹ���� %.4lf%%", sic.GetRate() * 100);
    SetDlgItemText(IDC_STATIC_MSG, m_sic.Describe());
    //Sleep(100);

    CDialog::OnTimer(nIDEvent);
}

BOOL CSimpleImgCompressAppDlg::OnEraseBkgnd(CDC* pDC)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    return CDialog::OnEraseBkgnd(pDC);
}

void CSimpleImgCompressAppDlg::OnBnClickedBtTest()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    KillTimer(0);
    CTestDlg dlg;
    dlg.m_sic.Chirp(m_sic.IsChirp());
    dlg.m_sic.SetAllow(m_sic.GetAllow());
    dlg.DoModal();
    m_sic.Chirp(dlg.m_sic.IsChirp());
    m_sic.SetAllow(dlg.m_sic.GetAllow());
    SetTimer(0, 66, 0);
}
