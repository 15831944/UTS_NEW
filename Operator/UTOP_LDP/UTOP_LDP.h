// UTOP_LDP.h : UTOP_LDP DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_LDPApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_LDP.cpp
//

class CUTOP_LDPApp : public CWinApp
{
public:
	CUTOP_LDPApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_LDPApp theApp;
