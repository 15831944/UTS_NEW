// UTOP_DDP.h : UTOP_DDP DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_DDPApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_DDP.cpp
//

class CUTOP_DDPApp : public CWinApp
{
public:
	CUTOP_DDPApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_DDPApp theApp;
