// UTDV_UVC.h : UTDV_UVC DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTDV_UVCApp
// �йش���ʵ�ֵ���Ϣ������� UTDV_UVC.cpp
//

class CUTDV_UVCApp : public CWinApp
{
public:
	CUTDV_UVCApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
    virtual int ExitInstance();
};

extern CUTDV_UVCApp theApp;
