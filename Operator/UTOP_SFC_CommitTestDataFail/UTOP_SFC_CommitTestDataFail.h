// UTOP_SFC_CommitTestDataFail.h : UTOP_SFC_CommitTestDataFail DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_SFC_CommitTestDataFailApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_SFC_CommitTestDataFail.cpp
//

class CUTOP_SFC_CommitTestDataFailApp : public CWinApp
{
public:
	CUTOP_SFC_CommitTestDataFailApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_SFC_CommitTestDataFailApp theApp;
