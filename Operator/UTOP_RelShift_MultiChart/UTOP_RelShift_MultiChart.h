// UTOP_RelShift_MultiChart.h : UTOP_RelShift_MultiChart DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_RelShift_MultiChartApp
// �@��e�Č���Ո��� UTOP_RelShift_MultiChart.cpp
//

class CUTOP_RelShift_MultiChartApp : public CWinApp
{
public:
	CUTOP_RelShift_MultiChartApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_RelShift_MultiChartApp theApp;