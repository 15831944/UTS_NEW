// UTOP_SFC_CommitTestDataPass.h : UTOP_SFC_CommitTestDataPass DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_SFC_CommitTestDataPassApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_SFC_CommitTestDataPass.cpp
//

class CUTOP_SFC_CommitTestDataPassApp : public CWinApp
{
public:
	CUTOP_SFC_CommitTestDataPassApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_SFC_CommitTestDataPassApp theApp;
