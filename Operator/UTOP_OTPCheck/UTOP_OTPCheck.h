// UTOP_OTPCheck.h : UTOP_OTPCheck DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_OTPCheckApp
// �@��e�Č���Ո��� UTOP_OTPCheck.cpp
//

class CUTOP_OTPCheckApp : public CWinApp
{
public:
	CUTOP_OTPCheckApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_OTPCheckApp theApp;