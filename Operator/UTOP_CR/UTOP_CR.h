// UTOP_CR.h : UTOP_CR DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_CRApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_CR.cpp
//

class CUTOP_CRApp : public CWinApp
{
public:
	CUTOP_CRApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CRApp theApp;

