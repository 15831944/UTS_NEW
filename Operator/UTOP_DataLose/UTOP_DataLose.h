// UTOP_DataLose.h : UTOP_DataLose DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_DataLoseApp
// �@��e�Č���Ո��� UTOP_DataLose.cpp
//

class CUTOP_DataLoseApp : public CWinApp
{
public:
	CUTOP_DataLoseApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_DataLoseApp theApp;