// UTOP_Resolution_MultiChart.h : UTOP_Resolution_MultiChart DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_Resolution_MultiChartApp
// �@��e�Č���Ո��� UTOP_Resolution_MultiChart.cpp
//

class CUTOP_Resolution_MultiChartApp : public CWinApp
{
public:
	CUTOP_Resolution_MultiChartApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
extern CUTOP_Resolution_MultiChartApp theApp;