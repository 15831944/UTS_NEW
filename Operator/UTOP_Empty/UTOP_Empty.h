// UTOP_Empty.h : UTOP_Empty DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_EmptyApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_Empty.cpp
//

class CUTOP_EmptyApp : public CWinApp
{
public:
	CUTOP_EmptyApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_EmptyApp theApp;
