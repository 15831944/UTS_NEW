// UTOP_SaveRAW10.h : UTOP_SaveRAW10 DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_SaveRAW10App
// �@��e�Č���Ո��� UTOP_SaveRAW10.cpp
//

class CUTOP_SaveRAW10App : public CWinApp
{
public:
	CUTOP_SaveRAW10App();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_SaveRAW10App theApp;