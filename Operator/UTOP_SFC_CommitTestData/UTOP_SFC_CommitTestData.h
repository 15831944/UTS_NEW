// UTOP_SFC_CommitTestData.h : UTOP_SFC_CommitTestData DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_SFC_CommitTestDataApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_SFC_CommitTestData.cpp
//

class CUTOP_SFC_CommitTestDataApp : public CWinApp
{
public:
	CUTOP_SFC_CommitTestDataApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_SFC_CommitTestDataApp theApp;
