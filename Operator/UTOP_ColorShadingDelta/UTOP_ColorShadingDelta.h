// UTOP_ColorShadingDelta.h : UTOP_ColorShadingDelta DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_ColorShadingDeltaApp
// �o�����O����@�аѾ\ UTOP_ColorShadingDelta.cpp
//

class CUTOP_ColorShadingDeltaApp : public CWinApp
{
public:
	CUTOP_ColorShadingDeltaApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorShadingDeltaApp theApp;