// UTOP_ResolutionNokia.h : UTOP_ResolutionNokia DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_ResolutionNokiaApp
// �o�����O����@�аѾ\ UTOP_ResolutionNokia.cpp
//

class CUTOP_ResolutionNokiaApp : public CWinApp
{
public:
	CUTOP_ResolutionNokiaApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ResolutionNokiaApp theApp;