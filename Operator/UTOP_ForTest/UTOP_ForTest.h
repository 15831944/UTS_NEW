// UTOP_ForTest.h : UTOP_ForTest DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_ForTestApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_ForTest.cpp
//

class CUTOP_ForTestApp : public CWinApp
{
public:
	CUTOP_ForTestApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ForTestApp theApp;
