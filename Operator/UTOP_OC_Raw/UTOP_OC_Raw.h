// UTOP_OC_Raw.h : UTOP_OC_Raw DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_OC_RawApp
// �o�����O����@�аѾ\ UTOP_OC_Raw.cpp
//

class CUTOP_OC_RawApp : public CWinApp
{
public:
	CUTOP_OC_RawApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_OC_RawApp theApp;
