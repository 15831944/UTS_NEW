// UTOP_BlemishCircle.h : UTOP_BlemishCircle DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_BlemishCircleApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_BlemishCircle.cpp
//

class CUTOP_BlemishCircleApp : public CWinApp
{
public:
	CUTOP_BlemishCircleApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_BlemishCircleApp theApp;
