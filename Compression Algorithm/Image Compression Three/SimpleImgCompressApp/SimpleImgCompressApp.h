// SimpleImgCompressApp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CSimpleImgCompressAppApp:
// �йش����ʵ�֣������ SimpleImgCompressApp.cpp
//

class CSimpleImgCompressAppApp : public CWinApp
{
public:
	CSimpleImgCompressAppApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSimpleImgCompressAppApp theApp;
