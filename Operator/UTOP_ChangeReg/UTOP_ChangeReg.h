// UTOP_ChangeReg.h : UTOP_ChangeReg DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_ChangeRegApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_ChangeReg.cpp
//

class CUTOP_ChangeRegApp : public CWinApp
{
public:
	CUTOP_ChangeRegApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ChangeRegApp theApp;
