// SettingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SimpleImgCompressApp.h"
#include "SettingDlg.h"


// CSettingDlg 对话框

IMPLEMENT_DYNAMIC(CSettingDlg, CDialog)
CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
    , m_iAllow(0)
    , m_bChirp(FALSE)
{
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_ET_ALLOW, m_iAllow);
    DDV_MinMaxInt(pDX, m_iAllow, 0, 1000000);
    DDX_Check(pDX, IDC_CK_CHIRP, m_bChirp);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
END_MESSAGE_MAP()


// CSettingDlg 消息处理程序
