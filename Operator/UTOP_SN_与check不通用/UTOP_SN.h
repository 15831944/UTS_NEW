// UTOP_SN.h : UTOP_SN DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_SNApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_SN.cpp
//

class CUTOP_SNApp : public CWinApp
{
public:
	CUTOP_SNApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_SNApp theApp;

