// UTOP_AWB_Asus.h : UTOP_AWB_Asus DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_AWB_AsusApp
// �@��e�Č���Ո��� UTOP_AWB_Asus.cpp
//

class CUTOP_AWB_AsusApp : public CWinApp
{
public:
	CUTOP_AWB_AsusApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_AWB_AsusApp theApp;