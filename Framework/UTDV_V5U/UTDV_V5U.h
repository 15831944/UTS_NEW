// UTDV_V5U.h : UTDV_V5U DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTDV_V5UApp
// �йش���ʵ�ֵ���Ϣ������� UTDV_V5U.cpp
//

class CUTDV_V5UApp : public CWinApp
{
public:
	CUTDV_V5UApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTDV_V5UApp theApp;
