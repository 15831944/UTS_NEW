// UTOP_SFC_Init.h : UTOP_SFC_Init DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_SFC_InitApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_SFC_Init.cpp
//

class CUTOP_SFC_InitApp : public CWinApp
{
public:
	CUTOP_SFC_InitApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_SFC_InitApp theApp;
