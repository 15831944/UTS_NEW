// UTOP_RI.h : UTOP_RI DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_RIApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_RI.cpp
//

class CUTOP_RIApp : public CWinApp
{
public:
	CUTOP_RIApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_RIApp theApp;
