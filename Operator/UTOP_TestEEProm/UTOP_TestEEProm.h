// UTOP_TestEEProm.h : UTOP_TestEEProm DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_TestEEPromApp
// �o�����O����@�аѾ\ UTOP_TestEEProm.cpp
//

class CUTOP_TestEEPromApp : public CWinApp
{
public:
	CUTOP_TestEEPromApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};


extern CUTOP_TestEEPromApp theApp;