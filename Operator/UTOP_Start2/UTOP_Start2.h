// UTOP_Start2.h : UTOP_Start2 DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_Start2App
// �@��e�Č���Ո��� UTOP_Start2.cpp
//

class CUTOP_Start2App : public CWinApp
{
public:
	CUTOP_Start2App();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_Start2App theApp;