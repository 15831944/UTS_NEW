// UTOP_ColorAccuracy_Altek.h : UTOP_ColorAccuracy_Altek DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_ColorAccuracy_AltekApp
// �o�����O����@�аѾ\ UTOP_ColorAccuracy_Altek.cpp
//

class CUTOP_ColorAccuracy_AltekApp : public CWinApp
{
public:
	CUTOP_ColorAccuracy_AltekApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorAccuracy_AltekApp theApp;