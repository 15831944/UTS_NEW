// UTOP_XCalibration.h : UTOP_XCalibration DLL ���D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CUTOP_XCalibrationApp
// �o�����O����@�аѾ\ UTOP_XCalibration.cpp
//

class CUTOP_XCalibrationApp : public CWinApp
{
public:
	CUTOP_XCalibrationApp();

// �мg
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_XCalibrationApp theApp;