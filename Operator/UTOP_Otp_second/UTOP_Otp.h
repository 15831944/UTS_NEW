// UTOP_Otp.h : UTOP_Otp DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_OtpApp
// �o�����O����@�аѾ\ UTOP_Otp.cpp
//

class CUTOP_OtpApp : public CWinApp
{
public:
	CUTOP_OtpApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_OtpApp theApp;