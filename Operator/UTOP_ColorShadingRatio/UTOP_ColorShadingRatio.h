// UTOP_ColorShadingRatio.h : UTOP_ColorShadingRatio DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_ColorShadingRatioApp
// �o�����O����@�аѾ\ UTOP_ColorShadingRatio.cpp
//

class CUTOP_ColorShadingRatioApp : public CWinApp
{
public:
	CUTOP_ColorShadingRatioApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_ColorShadingRatioApp theApp;