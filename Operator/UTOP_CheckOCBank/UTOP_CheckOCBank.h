// UTOP_CheckOCBank.h : UTOP_CheckOCBank DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_CheckOCBankApp
// �@��e�Č���Ո��� UTOP_CheckOCBank.cpp
//

class CUTOP_CheckOCBankApp : public CWinApp
{
public:
	CUTOP_CheckOCBankApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CheckOCBankApp theApp;