// SimpleImgCompressAppDlg.h : 头文件
//

#pragma once
#include "atlimage.h"
#include "SIC.h"
#include "testdlg.h"

// CSimpleImgCompressAppDlg 对话框
class CSimpleImgCompressAppDlg : public CDialog
{
// 构造
public:
	CSimpleImgCompressAppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SIMPLEIMGCOMPRESSAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

    CSIC m_sic;

	// 生成的消息映射函数
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
