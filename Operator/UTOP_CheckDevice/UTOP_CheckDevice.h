// UTOP_CheckDevice.h : UTOP_CheckDevice DLL ����Ҫ���^�n
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �����˙n��ǰ�Ȱ��� 'stdafx.h'"
#endif

#include "resource.h"		// ��Ҫ��̖


// CUTOP_CheckDeviceApp
// �@��e�Č���Ո��� UTOP_CheckDevice.cpp
//

class CUTOP_CheckDeviceApp : public CWinApp
{
public:
	CUTOP_CheckDeviceApp();

// ����
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CUTOP_CheckDeviceApp theApp;