// UTOP_MeasureCurrent.h : UTOP_MeasureCurrent DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_MeasureCurrentApp
// �@��e�Č���Ո��� UTOP_MeasureCurrent.cpp
//

class CUTOP_MeasureCurrentApp : public CWinApp
{
public:
	CUTOP_MeasureCurrentApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_MeasureCurrentApp theApp;