// UTOP_CanChageSN.h : UTOP_CanChageSN DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_CanChageSNApp
// �@��e�Č���Ո��� UTOP_CanChageSN.cpp
//

class CUTOP_CanChageSNApp : public CWinApp
{
public:
	CUTOP_CanChageSNApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CanChageSNApp theApp;