// UTOP_CheckSN.h : UTOP_CheckSN DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_CheckSNApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_CheckSN.cpp
//

class CUTOP_CheckSNApp : public CWinApp
{
public:
	CUTOP_CheckSNApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CheckSNApp theApp;

