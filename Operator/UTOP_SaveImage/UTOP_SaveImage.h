// UTOP_SaveImage.h : UTOP_SaveImage DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_SaveImageApp
// �o�����O����@�аѾ\ UTOP_SaveImage.cpp
//

class CUTOP_SaveImageApp : public CWinApp
{
public:
	CUTOP_SaveImageApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
extern CUTOP_SaveImageApp theApp;