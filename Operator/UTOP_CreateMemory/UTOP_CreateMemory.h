// UTOP_CreateMemory.h : UTOP_CreateMemory DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_CreateMemoryApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_CreateMemory.cpp
//

class CUTOP_CreateMemoryApp : public CWinApp
{
public:
	CUTOP_CreateMemoryApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CreateMemoryApp theApp;

