// UTOP_FullScreenSFR.h : UTOP_FullScreenSFR DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_FullScreenSFRApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_FullScreenSFR.cpp
//

class CUTOP_FullScreenSFRApp : public CWinApp
{
public:
	CUTOP_FullScreenSFRApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_FullScreenSFRApp theApp;