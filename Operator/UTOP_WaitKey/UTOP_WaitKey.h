// UTOP_WaitKey.h : UTOP_WaitKey DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_WaitKeyApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_WaitKey.cpp
//

class CUTOP_WaitKeyApp : public CWinApp
{
public:
	CUTOP_WaitKeyApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_WaitKeyApp theApp;
