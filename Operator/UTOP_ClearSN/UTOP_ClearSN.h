// UTOP_ClearSN.h : UTOP_ClearSN DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_ClearSNApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_ClearSN.cpp
//

class CUTOP_ClearSNApp : public CWinApp
{
public:
	CUTOP_ClearSNApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ClearSNApp theApp;

