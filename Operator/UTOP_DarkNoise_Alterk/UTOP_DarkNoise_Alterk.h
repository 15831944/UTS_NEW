// UTOP_DarkNoise_Alterk.h : UTOP_DarkNoise_Alterk DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_DarkNoise_AlterkApp
// �o�����O����@�аѾ\ UTOP_DarkNoise_Alterk.cpp
//

class CUTOP_DarkNoise_AlterkApp : public CWinApp
{
public:
	CUTOP_DarkNoise_AlterkApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_DarkNoise_AlterkApp theApp;