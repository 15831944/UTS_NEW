// UTOP_MeasureCurrentInit.h : UTOP_MeasureCurrentInit DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_MeasureCurrentInitApp
// �@��e�Č���Ո��� UTOP_MeasureCurrentInit.cpp
//

class CUTOP_MeasureCurrentInitApp : public CWinApp
{
public:
	CUTOP_MeasureCurrentInitApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_MeasureCurrentInitApp theApp;