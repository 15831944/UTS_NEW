// UTOP_VCM_Check.h : UTOP_VCM_Check DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_VCM_CheckApp
// �o�����O����@�аѾ\ UTOP_VCM_Check.cpp
//

class CUTOP_VCM_CheckApp : public CWinApp
{
public:
	CUTOP_VCM_CheckApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_VCM_CheckApp theApp;
