// UTOP_MeasureSuspendCurrent.h : UTOP_MeasureSuspendCurrent DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_MeasureSuspendCurrentApp
// �@��e�Č���Ո��� UTOP_MeasureSuspendCurrent.cpp
//

class CUTOP_MeasureSuspendCurrentApp : public CWinApp
{
public:
	CUTOP_MeasureSuspendCurrentApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_MeasureSuspendCurrentApp theApp;