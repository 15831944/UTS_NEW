// UTOP_GetOCBank.h : UTOP_GetOCBank DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_GetOCBankApp
// �@��e�Č���Ո��� UTOP_GetOCBank.cpp
//

class CUTOP_GetOCBankApp : public CWinApp
{
public:
	CUTOP_GetOCBankApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_GetOCBankApp theApp;