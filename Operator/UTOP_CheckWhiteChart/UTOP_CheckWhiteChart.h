// UTOP_CheckWhiteChart.h : UTOP_CheckWhiteChart DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_CheckWhiteChartApp
// �@��e�Č���Ո��� UTOP_CheckWhiteChart.cpp
//

class CUTOP_CheckWhiteChartApp : public CWinApp
{
public:
	CUTOP_CheckWhiteChartApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CheckWhiteChartApp theApp;