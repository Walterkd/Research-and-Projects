// SimpleImgCompressAppDlg.h : ͷ�ļ�
//

#pragma once
#include "atlimage.h"
#include "SIC.h"
#include "testdlg.h"

// CSimpleImgCompressAppDlg �Ի���
class CSimpleImgCompressAppDlg : public CDialog
{
// ����
public:
	CSimpleImgCompressAppDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SIMPLEIMGCOMPRESSAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

    CSIC m_sic;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnTimer(UINT nIDEvent);
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnBnClickedBtTest();
};
