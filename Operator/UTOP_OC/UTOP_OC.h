// UTOP_OC.h : UTOP_OC DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_OCApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_OC.cpp
//

class CUTOP_OCApp : public CWinApp
{
public:
	CUTOP_OCApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_OCApp theApp;
