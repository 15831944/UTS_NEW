// UTOP_ShowMsg.h : UTOP_ShowMsg DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_ShowMsgApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_ShowMsg.cpp
//

class CUTOP_ShowMsgApp : public CWinApp
{
public:
	CUTOP_ShowMsgApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ShowMsgApp theApp;
