// UTOP_XCalibration_OC.h : UTOP_XCalibration_OC DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_XCalibration_OCApp
// �@��e�Č���Ո��� UTOP_XCalibration_OC.cpp
//

class CUTOP_XCalibration_OCApp : public CWinApp
{
public:
	CUTOP_XCalibration_OCApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_XCalibration_OCApp theApp;