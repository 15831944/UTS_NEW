// UTOP_TimeDelay.h : UTOP_TimeDelay DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_TimeDelayApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_TimeDelay.cpp
//

class CUTOP_TimeDelayApp : public CWinApp
{
public:
	CUTOP_TimeDelayApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_TimeDelayApp theApp;
