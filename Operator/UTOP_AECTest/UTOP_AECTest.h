// UTOP_AECTest.h : UTOP_AECTest DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_AECTestApp
// �o�����O����@�аѾ\ UTOP_AECTest.cpp
//

class CUTOP_AECTestApp : public CWinApp
{
public:
	CUTOP_AECTestApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
extern CUTOP_AECTestApp theApp;