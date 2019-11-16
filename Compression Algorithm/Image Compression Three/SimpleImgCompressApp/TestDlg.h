#pragma once
#include "SIC.h"
#include "atlimage.h"
#include "settingdlg.h"

// CTestDlg �Ի���

class CTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestDlg();

    CPoint m_ptLast;
    CPoint m_ptOffset;
    CString m_sDes;
    CSIC m_sic;
// �Ի�������
	enum { IDD = IDD_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnMOpen();
    afx_msg void OnMCut();
    afx_msg void OnMCompress();
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMSetting();
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};
