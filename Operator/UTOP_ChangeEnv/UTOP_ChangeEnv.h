// UTOP_ChangeEnv.h : UTOP_ChangeEnv DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUTOP_ChangeEnvApp
// �йش���ʵ�ֵ���Ϣ������� UTOP_ChangeEnv.cpp
//

class CUTOP_ChangeEnvApp : public CWinApp
{
public:
	CUTOP_ChangeEnvApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ChangeEnvApp theApp;
